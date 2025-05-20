//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define SERVER_PORT 21
#define BUF_SIZE 512

int sockfd;

char buffer[BUF_SIZE];
char filename[BUF_SIZE];
char username[BUF_SIZE];
char password[BUF_SIZE];

struct sockaddr_in server_addr;
struct sockaddr_in client_addr;

void open_connection(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket 
    if (sockfd == -1){
        perror("Socket error\n");
        exit(1);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
        perror("Connection error\n");
        exit(1);
    }
}

void send_cmd(char *cmd){
    if (send(sockfd, cmd, strlen(cmd), 0) == -1){
        perror("Command error\n");
        exit(1);
    }
}

void read_res(){
    int bytes_read = 0;
    memset(buffer, 0, BUF_SIZE);
    bytes_read = recv(sockfd, buffer, BUF_SIZE, 0);
    if (bytes_read == -1){
        perror("Error reading response\n");
        exit(1);
    }
    printf("%s", buffer);
}

void login(){
    printf("Enter your username: ");
    scanf("%s", username);
    
    char cmd[BUF_SIZE];
    sprintf(cmd, "USER %s\r\n", username);
    send_cmd(cmd);
    read_res();
    
    printf("Enter your password: ");
    scanf("%s", password);
    
    sprintf(cmd, "PASS %s\r\n", password);
    send_cmd(cmd);
    read_res();
    
    printf("\n");
}

void get_file(){
    printf("Enter name of file to download: ");
    scanf("%s", filename);
    
    char cmd[BUF_SIZE];
    sprintf(cmd, "TYPE I\r\n");
    send_cmd(cmd);
    read_res();
    
    sprintf(cmd, "PASV\r\n");
    send_cmd(cmd);
    read_res();
    
    // parse port
    int port_high, port_low;
    char *tok = strtok(buffer, "(");
    tok = strtok(NULL, ",");
    tok = strtok(NULL, ",");
    tok = strtok(NULL, ",");
    tok = strtok(NULL, ",");
    port_high = atoi(tok);
    tok = strtok(NULL, ",");
    port_low = atoi(tok);
    
    int data_sockfd;
    struct sockaddr_in data_addr;
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd == -1){
        perror("Data socket error\n");
        exit(1);
    }
    
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port_high * 256 + port_low);
    data_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) == -1){
        perror("Data connection error\n");
        exit(1);
    }
    
    sprintf(cmd, "RETR %s\r\n", filename);
    send_cmd(cmd);
    read_res();
    
    FILE *fd;
    fd = fopen(filename, "wb");
    if (fd == NULL){
        perror("File error\n");
        exit(1);
    }
    
    int bytes_read = 0;
    while ((bytes_read = recv(data_sockfd, buffer, BUF_SIZE, 0)) > 0){
        fwrite(buffer, sizeof(char), bytes_read, fd);
    }
    
    fclose(fd);
    printf("File download complete!\n");
    
    close(data_sockfd);
}

void disconnect(){
    send_cmd("QUIT\r\n");
    read_res();
    
    close(sockfd);
}

int main(){
    open_connection();
    
    read_res(); // Welcome message
    
    login();
    
    get_file();
    
    disconnect();
    
    return 0;
}