//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) { 
    int sock_fd;
    char buffer[BUFFER_SIZE];
    char username[50];
    char password[50];
    struct sockaddr_in server_addr;
    struct hostent *server;
    ssize_t bytes_recv;
    FILE *file;
    
    // Check if enough arguments provided
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    
    // Get server details
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: Could not resolve hostname.\n");
        exit(1);
    }
    
    // Clear the buffer and create socket
    memset(buffer, 0, BUFFER_SIZE);
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }
    
    // Assign IP address and port to socket
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);
    
    // Connect to the server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Connection failed.\n");
        exit(1);
    } 
    
    // Get login credentials
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    // Send login credentials to server
    sprintf(buffer, "USER %s\r\n", username);
    send(sock_fd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    bytes_recv = recv(sock_fd, buffer, BUFFER_SIZE, 0);
    if(bytes_recv < 0) {
        printf("Error: Response error from server.\n");
        close(sock_fd);
        exit(1);
    }
    
    sprintf(buffer, "PASS %s\r\n", password);
    send(sock_fd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    bytes_recv = recv(sock_fd, buffer, BUFFER_SIZE, 0);
    if(bytes_recv < 0) {
        printf("Error: Response error from server.\n");
        close(sock_fd);
        exit(1);
    }
    
    printf("%s", buffer);
    
    // Start user interaction
    while(1) {
        printf("Enter command: ");
        scanf("%s", buffer);
        
        // Handle 'get' command
        if(strcmp(buffer, "get") == 0) {
            // Get filename and send retrieval command to server
            char filename[50];
            printf("Enter filename: ");
            scanf("%s", filename);
            sprintf(buffer, "RETR %s\r\n", filename);
            send(sock_fd, buffer, strlen(buffer), 0);
            
            // Get file size and create local file
            long int filesize;
            memset(buffer, 0, BUFFER_SIZE);
            bytes_recv = recv(sock_fd, buffer, BUFFER_SIZE, 0);
            sscanf(buffer, "%ld", &filesize);
            file = fopen(filename, "w");
            
            // Receive file data from server
            int bytes_read = 0;
            while(bytes_read < filesize) {
                memset(buffer, 0, BUFFER_SIZE);
                bytes_recv = recv(sock_fd, buffer, BUFFER_SIZE, 0);
                fwrite(buffer, 1, bytes_recv, file);
                bytes_read += bytes_recv;
            }
            fclose(file);
            printf("File retrieved successfully.\n");
            
            // Get and print response from server
            memset(buffer, 0, BUFFER_SIZE);
            bytes_recv = recv(sock_fd, buffer, BUFFER_SIZE, 0);
            printf("%s", buffer);
        }
        
        // Handle 'put' command
        else if(strcmp(buffer, "put") == 0) {
            // Get filename and check if exists
            char filename[50];
            printf("Enter filename: ");
            scanf("%s", filename);
            file = fopen(filename, "r");
            if(file == NULL) {
                printf("Error: File not found.\n");
                continue;
            }
            
            // Get file size and send PUT command to server
            fseek(file, 0L, SEEK_END);
            long int filesize = ftell(file);
            rewind(file);
            sprintf(buffer, "PUT %s %ld\r\n", filename, filesize);
            send(sock_fd, buffer, strlen(buffer), 0);
            
            // Send file data to server
            int bytes_sent = 0;
            while(bytes_sent < filesize) {
                memset(buffer, 0, BUFFER_SIZE);
                int bytes_to_send = fread(buffer, 1, BUFFER_SIZE, file);
                send(sock_fd, buffer, bytes_to_send, 0);
                bytes_sent += bytes_to_send;
            }
            fclose(file);
            printf("File sent successfully.\n");
            
            // Get and print response from server
            memset(buffer, 0, BUFFER_SIZE);
            bytes_recv = recv(sock_fd, buffer, BUFFER_SIZE, 0);
            printf("%s", buffer);
        }
        
        // Handle 'quit' command
        else if(strcmp(buffer, "quit") == 0) {
            send(sock_fd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
            memset(buffer, 0, BUFFER_SIZE);
            bytes_recv = recv(sock_fd, buffer, BUFFER_SIZE, 0);
            printf("%s", buffer);
            break;
        }
        
        // Handle unknown command
        else {
            printf("Error: Unknown command.\n");
        }
    }
    
    // Close the socket and exit program
    close(sock_fd);
    return 0; 
}