//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 21

typedef struct {
    int sockfd;
    struct sockaddr_in server_addr; 
} FTPClient;

void initialize_ftp_client(FTPClient *client, const char *server_ip);
void connect_to_server(FTPClient *client);
void send_command(FTPClient *client, const char *command);
void read_response(FTPClient *client);
void list_files(FTPClient *client);
void download_file(FTPClient *client, const char *filename);
void cleanup(FTPClient *client);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <FTP_SERVER_IP>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    FTPClient client;
    initialize_ftp_client(&client, argv[1]);
    connect_to_server(&client);
    
    read_response(&client); // Reading server greeting
    list_files(&client);
    
    char filename[100];
    printf("Enter filename to download: ");
    scanf("%s", filename);
    
    download_file(&client, filename);
    
    cleanup(&client);
    return EXIT_SUCCESS;
}

void initialize_ftp_client(FTPClient *client, const char *server_ip) {
    // Step 1: Create socket
    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }
    
    // Step 2: Configure server address structure
    memset(&client->server_addr, 0, sizeof(client->server_addr));
    client->server_addr.sin_family = AF_INET;
    client->server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &client->server_addr.sin_addr);
}

void connect_to_server(FTPClient *client) {
    // Step 3: Connect to the FTP server
    if (connect(client->sockfd, (struct sockaddr *)&client->server_addr, sizeof(client->server_addr)) < 0) {
        perror("Connection to server failed");
        close(client->sockfd);
        exit(EXIT_FAILURE);
    }
}

void send_command(FTPClient *client, const char *command) {
    // Step 4: Send command to FTP server
    send(client->sockfd, command, strlen(command), 0);
    // Append CRLF
    send(client->sockfd, "\r\n", 2, 0);
}

void read_response(FTPClient *client) {
    // Step 5: Read response from FTP server
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client->sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Failed to read response");
    } else {
        buffer[bytes_received] = '\0';
        printf("Server: %s", buffer);
    }
}

void list_files(FTPClient *client) {
    // Step 6: List the files in the current directory
    send_command(client, "LIST");
    read_response(client);
}

void download_file(FTPClient *client, const char *filename) {
    // Step 7: Send RETR command to download the specified file
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s", filename);
    send_command(client, command);
    
    // Step 8: Receive the file data
    char buffer[BUFFER_SIZE];
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Could not open file for writing");
        return;
    }

    int bytes_received;
    while ((bytes_received = recv(client->sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, fp);
    }

    fclose(fp);
    printf("File downloaded: %s\n", filename);
}

void cleanup(FTPClient *client) {
    // Step 9: Close the socket and cleanup
    close(client->sockfd);
}