//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
    struct sockaddr_in serv_address;
    char user_input[MAX_LENGTH];
    char server_msg[MAX_LENGTH];
    
    if(argc < 3) {
        printf("Usage: ./ftpClient <IP Address> <Port Number>\n");
        exit(1);
    }
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Failed to create socket.\n");
        exit(1);
    }
    
    serv_address.sin_family = AF_INET;
    serv_address.sin_addr.s_addr = inet_addr(argv[1]);
    serv_address.sin_port = htons(atoi(argv[2]));
    
    if(connect(sock, (struct sockaddr *)&serv_address, sizeof(serv_address)) < 0) {
        printf("Connection Failed.\n");
        exit(1);
    }
    
    printf("Connected to FTP Server. Enter 'quit' to exit.\n");
    while(1) {
        printf("FTP Client: ");
        memset(user_input, 0, MAX_LENGTH);
        fgets(user_input, MAX_LENGTH, stdin);
        user_input[strlen(user_input) - 1] = '\0';
        
        if(strcmp(user_input, "quit") == 0) {
            close(sock);
            printf("Disconnected from FTP Server.\n");
            exit(0);
        }
        
        write(sock, user_input, strlen(user_input));
        
        if(read(sock, server_msg, MAX_LENGTH) == 0) {
            printf("\nServer Disconnected.\n");
            close(sock);
            exit(1);
        }
        
        printf("FTP Server: %s", server_msg);
    }
    return 0;
}