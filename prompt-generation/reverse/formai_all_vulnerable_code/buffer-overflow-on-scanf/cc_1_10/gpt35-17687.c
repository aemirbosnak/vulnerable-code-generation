//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void send_command(int sockfd, char* command){
    send(sockfd, command, strlen(command), 0);
}

int receive_response(int sockfd, char* response){
    int code = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1){
        perror("Error receiving response from server");
        exit(1);
    }
    sscanf(buffer, "%d", &code);
    strcpy(response, buffer);
    return code;
}

int connect_to_server(char* address, int port){
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent* server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        perror("Error creating socket");
        exit(1);
    }

    server = gethostbyname(address);
    if (server == NULL){
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr*)server->h_addr);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1){
        perror("Error connecting to server");
        exit(1);
    }
    return sockfd;
}

void login(int sockfd, char* username, char* password){
    char response[BUFFER_SIZE];
    send_command(sockfd, "USER ");
    send_command(sockfd, username);
    send_command(sockfd, "\r\n");
    receive_response(sockfd, response);

    if (response[0] == '4' || response[0] == '5'){
        printf("Invalid username\n");
        exit(1);
    }

    send_command(sockfd, "PASS ");
    send_command(sockfd, password);
    send_command(sockfd, "\r\n");
    receive_response(sockfd, response);

    if (response[0] == '4' || response[0] == '5'){
        printf("Invalid password\n");
        exit(1);
    }
}

void download(int sockfd, char* filename){
    char buffer[BUFFER_SIZE];
    int filefd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (filefd == -1){
        perror("Error creating local file");
        exit(1);
    }

    send_command(sockfd, "TYPE I\r\n");
    char response[BUFFER_SIZE];
    int code = receive_response(sockfd, response);
    if (code != 200){
        printf("Error setting transfer type\n");
        exit(1);
    }

    send_command(sockfd, "PASV\r\n");
    code = receive_response(sockfd, response);
    if (code != 227){
        printf("Error entering passive mode\n");
        exit(1);
    }

    // parse address and port from response
    char* start_ip = strchr(response, '(') + 1;
    char* end_ip = strchr(start_ip, ')');
    char* start_port = end_ip + 2;
    char* end_port = strchr(start_port, ')');
    *end_ip = '\0';
    *end_port = '\0';

    int port1 = atoi(strtok(start_port, ","));
    int port2 = atoi(strtok(NULL, ","));
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(start_ip);
    serv_addr.sin_port = htons(port1 * 256 + port2);

    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1){
        perror("Error creating socket for data transfer");
        exit(1);
    }

    if (connect(serverfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1){
        perror("Error connecting to server for data transfer");
        exit(1);
    }

    send_command(sockfd, "RETR ");
    send_command(sockfd, filename);
    send_command(sockfd, "\r\n");

    code = receive_response(sockfd, response);
    if (code != 150){
        printf("Error downloading file\n");
        exit(1);
    }

    int bytes_received = 0;
    while ((bytes_received = recv(serverfd, buffer, BUFFER_SIZE, 0)) > 0){
        write(filefd, buffer, bytes_received);
    }

    close(filefd);
    close(serverfd);
    receive_response(sockfd, response);
    if (response[0] != '2'){
        printf("Error completing transaction\n");
        exit(1);
    }
}

void help(){
    printf("Commands available:\n");
    printf("\tdownload <filename>\n");
    printf("\texit\n");
}

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("Usage: ./ftpclient <server address> <server port>\n");
        exit(1);
    }

    int sockfd = connect_to_server(argv[1], atoi(argv[2]));
    char username[50], password[50], command[50], arg[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    login(sockfd, username, password);

    printf("Connected to FTP server at %s:%s\n", argv[1], argv[2]);
    help();

    while (1){
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "exit") == 0){
            send_command(sockfd, "QUIT\r\n");
            char response[BUFFER_SIZE];
            receive_response(sockfd, response);
            if (response[0] == '2'){
                printf("Goodbye!\n");
                break;
            }
            else{
                printf("Error quitting\n");
            }
        }
        else if (strcmp(command, "download") == 0){
            scanf("%s", arg);
            download(sockfd, arg);
        }
        else{
            printf("Invalid command\n");
            help();
        }
    }

    close(sockfd);

    return 0;
}