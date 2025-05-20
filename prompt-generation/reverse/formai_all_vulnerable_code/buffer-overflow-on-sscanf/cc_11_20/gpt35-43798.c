//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define BUFSIZE 1024

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sock;
    struct sockaddr_in ftp_server_addr;
    char buf[BUFSIZE];
    int bytes_received = -1;
    int server_port = 21;
    char *server_ip = "127.0.0.1";
    char *username = "";
    char *password = "";
    char *filename = "";
    char *local_filename = "";
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if(argc < 2){
        printf("Usage: %s ftp_server_address\n", argv[0]);
        return 1;
    }

    server_ip = argv[1];

    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock < 0){
        error("socket() failed");
    }

    memset(&ftp_server_addr, 0, sizeof(ftp_server_addr));
    ftp_server_addr.sin_family = AF_INET;
    ftp_server_addr.sin_addr.s_addr = inet_addr(server_ip);
    ftp_server_addr.sin_port = htons(server_port);

    if(connect(sock, (struct sockaddr *) &ftp_server_addr, sizeof(ftp_server_addr)) < 0){
        error("connect() failed");
    }

    bytes_received = recv(sock, buf, BUFSIZE, 0);
    if(bytes_received < 0){
        error("recv() failed");
    }
    buf[bytes_received] = 0;
    printf("%s", buf);

    // Send user command
    printf("Username: ");
    getline(&line, &len, stdin);
    username = strtok(line, "\n");
    sprintf(buf, "USER %s\r\n", username);
    if(send(sock, buf, strlen(buf), 0) < 0){
        error("send() failed");
    }
    bytes_received = recv(sock, buf, BUFSIZE, 0);
    if(bytes_received < 0){
        error("recv() failed");
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);

    // Send password command
    printf("Password: ");
    getline(&line, &len, stdin);
    password = strtok(line, "\n");
    sprintf(buf, "PASS %s\r\n", password);
    if(send(sock, buf, strlen(buf), 0) < 0){
        error("send() failed");
    }
    bytes_received = recv(sock, buf, BUFSIZE, 0);
    if(bytes_received < 0){
        error("recv() failed");
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);

    // Set passive mode
    sprintf(buf, "PASV\r\n");
    if(send(sock, buf, strlen(buf), 0) < 0){
        error("send() failed");
    }
    bytes_received = recv(sock, buf, BUFSIZE, 0);
    if(bytes_received < 0){
        error("recv() failed");
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);

    // Get address and port for data connection
    int p1, p2, p3, p4, p5, p6;
    sscanf(buf, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\n", &p1,&p2,&p3,&p4,&p5,&p6);
    int data_port = p5 * 256 + p6;
    struct sockaddr_in data_server_addr;
    memset(&data_server_addr, 0, sizeof(data_server_addr));
    data_server_addr.sin_family = AF_INET;
    data_server_addr.sin_addr.s_addr = inet_addr(server_ip);
    data_server_addr.sin_port = htons(data_port);

    // Send list command
    sprintf(buf, "LIST\r\n");
    if(send(sock, buf, strlen(buf), 0) < 0){
        error("send() failed");
    }
    bytes_received = recv(sock, buf, BUFSIZE, 0);
    if(bytes_received < 0){
        error("recv() failed");
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);

    // Connect to data server
    int data_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(data_sock < 0){
        error("socket() failed");
    }
    if(connect(data_sock, (struct sockaddr *) &data_server_addr, sizeof(data_server_addr)) < 0){
        error("connect() failed");
    }

    bytes_received = recv(data_sock, buf, BUFSIZE, 0);
    if(bytes_received < 0){
        error("recv() failed");
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);

    // Receive data
    while((bytes_received = recv(data_sock, buf, BUFSIZE, 0)) > 0){
        fwrite(buf, 1, bytes_received, stdout);
    }

    close(data_sock);

    // Get file to retrieve
    printf("Enter filename: ");
    getline(&line, &len, stdin);
    filename = strtok(line, "\n");

    // Set passive mode
    sprintf(buf, "PASV\r\n");
    if(send(sock, buf, strlen(buf), 0) < 0){
        error("send() failed");
    }
    bytes_received = recv(sock, buf, BUFSIZE, 0);
    if(bytes_received < 0){
        error("recv() failed");
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);

    // Get address and port for data connection
    sscanf(buf, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\n", &p1,&p2,&p3,&p4,&p5,&p6);
    data_port = p5 * 256 + p6;
    memset(&data_server_addr, 0, sizeof(data_server_addr));
    data_server_addr.sin_family = AF_INET;
    data_server_addr.sin_addr.s_addr = inet_addr(server_ip);
    data_server_addr.sin_port = htons(data_port);

    // Send RETR command
    sprintf(buf, "RETR %s\r\n", filename);
    if(send(sock, buf, strlen(buf), 0) < 0){
        error("send() failed");
    }
    bytes_received = recv(sock, buf, BUFSIZE, 0);
    if(bytes_received < 0){
        error("recv() failed");
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);

    // Connect to data server
    data_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(data_sock < 0){
        error("socket() failed");
    }
    if(connect(data_sock, (struct sockaddr *) &data_server_addr, sizeof(data_server_addr)) < 0){
        error("connect() failed");
    }

    // Receive file
    file = fopen("received_file", "w");
    while((bytes_received = recv(data_sock, buf, BUFSIZE, 0)) > 0){
        fwrite(buf, 1, bytes_received, file);
    }
    fclose(file);
    close(data_sock);

    // Get file to upload
    printf("Enter file to upload: ");
    getline(&line, &len, stdin);
    filename = strtok(line, "\n");

    // Set passive mode
    sprintf(buf, "PASV\r\n");
    if(send(sock, buf, strlen(buf), 0) < 0){
        error("send() failed");
    }
    bytes_received = recv(sock, buf, BUFSIZE, 0);
    if(bytes_received < 0){
        error("recv() failed");
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);

    // Get address and port for data connection
    sscanf(buf, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\n", &p1,&p2,&p3,&p4,&p5,&p6);
    data_port = p5 * 256 + p6;
    memset(&data_server_addr, 0, sizeof(data_server_addr));
    data_server_addr.sin_family = AF_INET;
    data_server_addr.sin_addr.s_addr = inet_addr(server_ip);
    data_server_addr.sin_port = htons(data_port);

    // Send STOR command
    sprintf(buf, "STOR %s\r\n", filename);
    if(send(sock, buf, strlen(buf), 0) < 0){
        error("send() failed");
    }
    bytes_received = recv(sock, buf, BUFSIZE, 0);
    if(bytes_received < 0){
        error("recv() failed");
    }
    buf[bytes_received] = '\0';
    printf("%s", buf);

    // Connect to data server
    data_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(data_sock < 0){
        error("socket() failed");
    }
    if(connect(data_sock, (struct sockaddr *) &data_server_addr, sizeof(data_server_addr)) < 0){
        error("connect() failed");
    }

    // Send file
    file = fopen(filename, "r");
    while((bytes_received = fread(buf, 1, BUFSIZE, file)) > 0){
        if(send(data_sock, buf, bytes_received, 0) < 0){
            error("send() failed");
        }
    }
    fclose(file);
    close(data_sock);

    close(sock);

    return 0;
}