//FormAI DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
 
#define PORT 8080 
#define BUFFER_SIZE 1024 
 
char *get_file_extension(char *filename) { 
    char *dot = strrchr(filename, '.'); 
    if(!dot || dot == filename) return ""; 
    return dot + 1; 
} 
 
char *get_content_type(char *filename) { 
    char *extension = get_file_extension(filename); 
    if(strcmp(extension, "htm") == 0 || strcmp(extension, "html") == 0) { 
        return "text/html"; 
    } 
    if(strcmp(extension, "css") == 0) { 
        return "text/css"; 
    } 
    if(strcmp(extension, "jpg") == 0 || strcmp(extension, "jpeg") == 0) { 
        return "image/jpeg"; 
    } 
    if(strcmp(extension, "png") == 0) { 
        return "image/png"; 
    } 
    if(strcmp(extension, "gif") == 0) { 
        return "image/gif"; 
    } 
    if(strcmp(extension, "js") == 0) { 
        return "application/javascript"; 
    } 
    return "text/plain"; 
} 
 
void send_file(int client_socket, char *filename) { 
    char buffer[BUFFER_SIZE]; 
    FILE *file = fopen(filename, "r"); 
    if(file == NULL) { 
        send(client_socket, "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\nContent-Type: text/plain\r\n\r\n", 
             strlen("HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\nContent-Type: text/plain\r\n\r\n"), 0); 
    } else { 
        fseek(file, 0, SEEK_END); 
        int content_length = ftell(file); 
        rewind(file); 
        char *content_type = get_content_type(filename); 
        sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\nContent-Type: %s\r\n\r\n", content_length, content_type); 
        send(client_socket, buffer, strlen(buffer), 0); 
        int bytes_read; 
        while((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) { 
            send(client_socket, buffer, bytes_read, 0); 
        } 
        fclose(file); 
    } 
} 
 
int main() { 
    int server_socket, client_socket, address_length; 
    struct sockaddr_in server_address, client_address; 
    char buffer[BUFFER_SIZE], request_type[BUFFER_SIZE], request_path[BUFFER_SIZE]; 
     
    // Create socket 
    server_socket = socket(AF_INET, SOCK_STREAM, 0); 
    if(server_socket == -1) { 
        perror("Failed to create socket"); 
        exit(EXIT_FAILURE); 
    } 
     
    // Bind socket to port 
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons(PORT); 
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) { 
        perror("Failed to bind socket"); 
        exit(EXIT_FAILURE); 
    } 
     
    // Listen for incoming connections 
    if(listen(server_socket, 10) == -1) { 
        perror("Failed to listen for incoming connections"); 
        exit(EXIT_FAILURE); 
    } 
    printf("Listening on port %d...\n", PORT); 
     
    while(1) { 
        // Accept incoming connection 
        address_length = sizeof(client_address); 
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_length); 
        if(client_socket == -1) { 
            perror("Failed to accept incoming connection"); 
            continue; 
        } 
         
        printf("Received incoming connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port)); 
         
        // Receive and parse request 
        ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0); 
        if(bytes_received == -1) { 
            perror("Failed to receive data from client"); 
        } else { 
            buffer[bytes_received] = '\0'; 
            printf("Received request:\n%s\n", buffer); 
             
            sscanf(buffer, "%s %s", request_type, request_path); 
             
            // Serve file 
            send_file(client_socket, request_path + 1); 
        } 
         
        close(client_socket); 
    } 
     
    close(server_socket); 
    return 0; 
}