//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXBUF 1024

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server_addr;
    char filename[MAXBUF], command[MAXBUF], buf[MAXBUF];
    FILE *fp;
    int bytes_received = 0, file_size = 0, total_received = 0;

    // Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
        return 1;
    }

    // Clear server_addr
    memset(&server_addr, 0, sizeof(server_addr));

    // Set family, ip, and port of server
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(21);

    // Connect to server
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect failed");
        return 1;
    }

    // Receive welcome message
    memset(buf, 0, MAXBUF);
    if(recv(sock, buf, MAXBUF, 0) < 0) {
        perror("Could not receive welcome message");
        return 1;
    }
    printf("%s", buf);

    // Send username
    printf("Username: ");
    fgets(buf, MAXBUF, stdin);
    snprintf(command, MAXBUF, "USER %s", strtok(buf, "\n"));
    send(sock, command, strlen(command), 0);

    // Receive password prompt
    memset(buf, 0, MAXBUF);
    if(recv(sock, buf, MAXBUF, 0) < 0) {
        perror("Could not receive password prompt");
        return 1;
    }
    printf("%s", buf);

    // Send password
    printf("Password: ");
    fgets(buf, MAXBUF, stdin);
    snprintf(command, MAXBUF, "PASS %s", strtok(buf, "\n"));
    send(sock, command, strlen(command), 0);

    // Receive login successful message
    memset(buf, 0, MAXBUF);
    if(recv(sock, buf, MAXBUF, 0) < 0) {
        perror("Could not receive login successful message");
        return 1;
    }
    printf("%s", buf);

    // Get filename from user
    printf("Enter filename to download: ");
    fgets(filename, MAXBUF, stdin);
    strtok(filename, "\n");

    // Send PASV command to enter passive mode
    send(sock, "PASV\r\n", strlen("PASV\r\n"), 0);

    memset(buf, 0, MAXBUF);
    if(recv(sock, buf, MAXBUF, 0) < 0) {
        perror("Could not receive PASV response");
        return 1;
    }

    // Get IP and port from PASV response
    char *p1, *p2;
    int ip[4], port[2], data_sock;
    p1 = strrchr(buf, '(');
    p2 = strrchr(buf, ')');
    sscanf(p1, "(%d,%d,%d,%d,%d,%d)", &ip[0], &ip[1], &ip[2], &ip[3], &port[0], &port[1]);

    // Create data socket and connect to server
    if((data_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create data socket");
        return 1;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl((ip[0] << 24) | (ip[1] << 16) | (ip[2] << 8) | ip[3]);
    server_addr.sin_port = htons((port[0] << 8) | port[1]);
    if(connect(data_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect to data socket");
        return 1;
    }

    // Send RETR command to download file
    snprintf(command, MAXBUF, "RETR %s\r\n", filename);
    send(sock, command, strlen(command), 0);

    // Receive response to RETR command
    memset(buf, 0, MAXBUF);
    if(recv(sock, buf, MAXBUF, 0) < 0) {
        perror("Could not receive RETR response");
        return 1;
    }

    // Check if file exists
    if(strncmp(buf, "550", 3) == 0) {
        printf("File not found.\n");
        return 1;
    }

    // Open file for writing
    if((fp = fopen(filename, "wb")) == NULL) {
        perror("Could not open file for writing");
        return 1;
    }

    // Get file size from response to RETR command
    sscanf(buf, "%*d %*s %*s %*s %d", &file_size);
    printf("Downloading %s (%d bytes)\n", filename, file_size);

    // Download file
    while(total_received < file_size) {
        if((bytes_received = recv(data_sock, buf, MAXBUF, 0)) < 0) {
            perror("Could not receive file data");
            return 1;
        }
        total_received += bytes_received;
        fwrite(buf, sizeof(char), bytes_received, fp);
        memset(buf, 0, MAXBUF);
    }
    fclose(fp);
    close(sock);
    close(data_sock);

    printf("File download complete.\n");
    return 0;
}