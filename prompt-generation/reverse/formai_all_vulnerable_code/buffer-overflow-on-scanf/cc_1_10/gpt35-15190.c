//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int connect_to_server(char* ip_address, int port) {
    int socket_desc;
    struct sockaddr_in server;
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket\n");
        return -1;
    } 
    
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
 
    if (connect(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Connection failed\n");
        return -1;
    }
    
    printf("Connected to server\n");
    return socket_desc;
}

void receive_file(int socket_desc, char* file_name) {
    char buffer[MAX_SIZE];
    int file_size, read_size;
    FILE* file;
    
    recv(socket_desc, buffer, sizeof(buffer), 0);
    if (strcmp(buffer, "FILE NOT FOUND") == 0) {
        printf("File not found on server\n");
        return;
    }
    
    file_size = atoi(buffer);
    printf("File size: %d\n", file_size);
    
    file = fopen(file_name, "wb");
    if (file == NULL) {
        printf("Could not open file\n");
        return;
    }
    
    while (file_size > 0) {
        read_size = recv(socket_desc, buffer, sizeof(buffer), 0);
        fwrite(buffer, sizeof(char), read_size, file);
        file_size -= read_size;
    }
    
    fclose(file);
    printf("File received successfully\n");
}

void send_command(int socket_desc, char* command) {
    char buffer[MAX_SIZE];
    strcpy(buffer, command);
    send(socket_desc, buffer, strlen(buffer), 0);
}

void send_file(int socket_desc, char* file_name) {
    char buffer[MAX_SIZE];
    int read_size;
    FILE* file;
    
    file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Could not open file\n");
        return;
    }
    
    send_command(socket_desc, "PUT");
    send_command(socket_desc, file_name);
    
    while (!feof(file)) {
        read_size = fread(buffer, sizeof(char), sizeof(buffer), file);
        send(socket_desc, buffer, read_size, 0);
    }
    
    fclose(file);
    printf("File sent successfully\n");
}

int main(int argc, char* argv[]) {
    char ip_address[16];
    int port, socket_desc, choice;
    char file_name[20];
    
    printf("Enter IP address: ");
    scanf("%s", ip_address);
    printf("Enter port: ");
    scanf("%d", &port);
    
    socket_desc = connect_to_server(ip_address, port);
    if (socket_desc == -1) {
        return 0;
    }
    
    printf("Choose an option:\n");
    printf("1. Download file\n");
    printf("2. Upload file\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", file_name);
            send_command(socket_desc, "GET");
            send_command(socket_desc, file_name);
            receive_file(socket_desc, file_name);
            break;
        case 2:
            printf("Enter file name: ");
            scanf("%s", file_name);
            send_file(socket_desc, file_name);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    
    close(socket_desc);
    return 0;
}