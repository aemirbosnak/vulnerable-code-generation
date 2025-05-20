//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<unistd.h>

#define SERV_PORT 21
#define BUFF_SIZE 4096

int main(int argc, char **argv) {
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[BUFF_SIZE];
    int sockfd, bytes, filefd;
    FILE *fileptr;

    if(argc < 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) perror("Socket creation failed");

    bzero((char*)&servaddr, sizeof(servaddr));
    server = gethostbyname(argv[1]);
    if(server == NULL) {
        printf("Invalid hostname\n");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(SERV_PORT);

    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) perror("Connection failed");

    bytes = read(sockfd, buffer, BUFF_SIZE-1);
    if(bytes < 0) perror("Reading from socket failed");

    buffer[bytes] = '\0';

    printf("%s", buffer);

    char user[100], pass[100];

    sprintf(user, "USER %s\r\n", argv[2]);
    sprintf(pass, "PASS %s\r\n", argv[3]);

    write(sockfd, user, strlen(user));
    bytes = read(sockfd, buffer, BUFF_SIZE-1);
    buffer[bytes] = '\0';
    printf("%s", buffer);

    write(sockfd, pass, strlen(pass));
    bytes = read(sockfd, buffer, BUFF_SIZE-1);
    buffer[bytes] = '\0';
    printf("%s", buffer);

    write(sockfd, "PASV\r\n", 6);
    bytes = read(sockfd, buffer, BUFF_SIZE-1);

    int ip_address[6];
    int port_num1, port_num2;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d).\n", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3], &port_num1, &port_num2);

    int port = (port_num1 * 256) + port_num2;

    servaddr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) perror("Data connection failed");

    int resp;
    char ftp_cmd[1000];

    printf("\nEnter filename to download: ");

    scanf("%s", ftp_cmd);

    sprintf(ftp_cmd, "RETR %s\r\n", ftp_cmd);

    write(sockfd, ftp_cmd, strlen(ftp_cmd));

    bytes = read(sockfd, buffer, BUFF_SIZE-1);

    if(strncmp(buffer, "550", 3) == 0) {
        printf("File not found on server\n");
        exit(1);
    }
    else if(strncmp(buffer, "150", 3) == 0) {

        fileptr = fopen(ftp_cmd+5, "wb");
        if(fileptr == NULL) perror("File creation failed");

        while((bytes = read(sockfd, buffer, BUFF_SIZE-1)) > 0) {
            fwrite(buffer, 1, bytes, fileptr);
        }

        fclose(fileptr);

        bytes = read(sockfd, buffer, BUFF_SIZE-1);

        printf("%s\n", buffer);

        bytes = read(sockfd, buffer, BUFF_SIZE-1);

        printf("%s\n", buffer);
    }
    else {
        printf("Unknown response from server.\n");
        exit(1);
    }

    close(sockfd);
    return 0;
}