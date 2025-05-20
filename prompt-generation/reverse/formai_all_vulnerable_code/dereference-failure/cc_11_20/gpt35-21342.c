//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    
    // Check for correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <ip_address> <port_number> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Retrieve inputs
    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char *filename = argv[3];
    
    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    // Get server address
    struct hostent *server = gethostbyname(ip_address);
    if (server == NULL) {
        printf("Error: No such host exists\n");
        exit(EXIT_FAILURE);
    }
    
    // Set server address properties
    struct sockaddr_in server_address;
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], 
          (char *)&server_address.sin_addr.s_addr, 
          server->h_length);
    server_address.sin_port = htons(port_number);
    
    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    
    // Send request for file
    char request[MAX_BUFFER_SIZE];
    sprintf(request, "RETR %s\r\n", filename);
    write(socket_fd, request, strlen(request));
    
    // Read response from server
    char response[MAX_BUFFER_SIZE];
    int response_size = read(socket_fd, response, sizeof(response));
    if (response_size == -1) {
        perror("Failed to read response from server");
        exit(EXIT_FAILURE);
    }
    
    // Check if file exists and if it is a regular file
    char *file_error = strstr(response, "550");
    if (file_error != NULL) {
        printf("Error: File does not exist on server\n");
        exit(EXIT_FAILURE);
    }
    
    char *file_size_string = strstr(response, "213");
    if (file_size_string == NULL) {
        perror("Failed to get file size from server");
        exit(EXIT_FAILURE);
    }
    
    // Get file size
    int file_size = atoi(file_size_string + 4);
    
    // Open file for writing
    FILE *output_file = fopen(filename, "w");
    if (output_file == NULL) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }
    
    // Receive file data
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received = 0;
    int total_bytes_received = 0;
    while (total_bytes_received < file_size) {
        bytes_received = read(socket_fd, buffer, sizeof(buffer));
        if (bytes_received == -1) {
            perror("Failed to read file data from server");
            exit(EXIT_FAILURE);
        }
        total_bytes_received += bytes_received;
        fwrite(buffer, 1, bytes_received, output_file);
    }
    
    // Close file and socket
    fclose(output_file);
    close(socket_fd);
    
    printf("File has been successfully downloaded!\n");
    return 0;
}