//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CMD_LEN 100
#define BUFFER_SIZE 1024

#define ERROR -1
#define SUCCESS 0

void print_menu() {
    printf("\n\nFTP CLIENT MENU\n");
    printf("1. Connect to server\n");
    printf("2. Upload file to server\n");
    printf("3. Download file from server\n");
    printf("4. List files on server\n");
    printf("5. Exit\n\n");
}

int connect_to_server(int sockfd, struct sockaddr_in server_addr) {
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    
    // Get username
    printf("Enter username: ");
    scanf("%s", username);
    strcat(buffer, username);
    strcat(buffer, " ");
    
    // Get password
    printf("Enter password: ");
    scanf("%s", password);
    strcat(buffer, password);
    
    // Send login credentials to server
    if (send(sockfd, buffer, sizeof(buffer), 0) == ERROR) {
        printf("Error sending login credentials to server\n");
        return ERROR;
    }
    
    // Wait for server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) == ERROR) {
        printf("Error receiving server response\n");
        return ERROR;
    }
    
    if (strcmp(buffer, "SUCCESS") == SUCCESS) {
        printf("Login successful\n");
    } else {
        printf("Login failed: %s\n", buffer);
        return ERROR;
    }
    
    return SUCCESS;
}

int upload_file(int sockfd, struct sockaddr_in server_addr) {
    char filename[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    int n, ret;
    FILE *fp;
    
    // Get filename
    printf("Enter file name to upload: ");
    scanf("%s", filename);
    
    // Open file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return ERROR;
    }
    
    // Send filename to server
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, filename);
    if (send(sockfd, buffer, sizeof(buffer), 0) == ERROR) {
        printf("Error sending filename to server\n");
        return ERROR;
    }
    
    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == ERROR) {
        printf("Error receiving server response\n");
        return ERROR;
    }
    
    if (strcmp(buffer, "EXIST") == SUCCESS) {
        printf("File already exist on server\n");
        return ERROR;
    }
    
    // Upload file
    memset(buffer, 0, sizeof(buffer));
    ret = 1;
    while (ret) {
        n = fread(buffer, 1, BUFFER_SIZE, fp);
        if (n > 0) {
            ret = send(sockfd, buffer, n, 0);
            if (ret == ERROR) {
                printf("Error sending file\n");
                return ERROR;
            }
        } else {
            ret = 0;
        }
    }
    
    fclose(fp);
    printf("File uploaded successfully\n");
    return SUCCESS;
}

int download_file(int sockfd, struct sockaddr_in server_addr) {
    char filename[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    int n;
    FILE *fp;
    
    // Get filename
    printf("Enter file name to download: ");
    scanf("%s", filename);
    
    // Send filename to server
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, filename);
    if (send(sockfd, buffer, sizeof(buffer), 0) == ERROR) {
        printf("Error sending filename to server\n");
        return ERROR;
    }
    
    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == ERROR) {
        printf("Error receiving server response\n");
        return ERROR;
    }
    
    if (strcmp(buffer, "NOT_FOUND") == SUCCESS) {
        printf("File not found on server\n");
        return ERROR;
    }
    
    // Open file
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return ERROR;
    }
    
    // Receive file
    memset(buffer, 0, sizeof(buffer));
    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, n, fp);
    }
    
    fclose(fp);
    printf("File downloaded successfully\n");
    return SUCCESS;
}

int list_files(int sockfd, struct sockaddr_in server_addr) {
    char buffer[BUFFER_SIZE];
    int n;
    
    // Send command to server
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "LIST");
    if (send(sockfd, buffer, sizeof(buffer), 0) == ERROR) {
        printf("Error sending command to server\n");
        return ERROR;
    }
    
    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("%s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    
    printf("End of file list\n");
    return SUCCESS;
}

int main(int argc, char *argv[]) {
    int sockfd, port, ret;
    struct sockaddr_in server_addr;
    char cmd[MAX_CMD_LEN];
    
    // Get server hostname and port
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(ERROR);
    }
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == ERROR) {
        printf("Error creating socket\n");
        exit(ERROR);
    }
    
    // Setup server address
    port = atoi(argv[2]);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    ret = inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    if (ret == ERROR) {
        printf("Invalid address\n");
        exit(ERROR);
    } else if (ret == 0) {
        printf("Address not in presentation format\n");
        exit(ERROR);
    }
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == ERROR) {
        printf("Error connecting to server\n");
        exit(ERROR);
    }
    
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%s", cmd);
        
        if (strcmp(cmd, "1") == SUCCESS) {
            if (connect_to_server(sockfd, server_addr) == ERROR) {
                printf("Login failed\n");
            }
        } else if (strcmp(cmd, "2") == SUCCESS) {
            if (upload_file(sockfd, server_addr) == ERROR) {
                printf("File upload failed\n");
            }
        } else if (strcmp(cmd, "3") == SUCCESS) {
            if (download_file(sockfd, server_addr) == ERROR) {
                printf("File download failed\n");
            }
        } else if (strcmp(cmd, "4") == SUCCESS) {
            if (list_files(sockfd, server_addr) == ERROR) {
                printf("File listing failed\n");
            }
        } else if (strcmp(cmd, "5") == SUCCESS) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    
    close(sockfd);
    return SUCCESS;
}