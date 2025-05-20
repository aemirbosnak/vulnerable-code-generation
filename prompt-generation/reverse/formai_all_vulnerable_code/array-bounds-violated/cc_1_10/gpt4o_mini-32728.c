//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define FTP_PORT 21
#define MAX_COMMAND_LENGTH 256

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "226") || strstr(buffer, "250")) {
            break; // End of relevant response
        }
    }
}

int connect_to_ftp(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    host = gethostbyname(hostname);
    if (host == NULL) {
        error("ERROR, no such host");
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(FTP_PORT);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void authenticate(int sockfd, const char *username, const char *password) {
    char command[MAX_COMMAND_LENGTH];

    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void upload_file(int sockfd, const char *local_file_path, const char *remote_file_name) {
    char command[MAX_COMMAND_LENGTH];

    // Set binary mode
    send_command(sockfd, "TYPE I");
    receive_response(sockfd);

    // Prepare the data connection
    int data_sockfd;
    struct sockaddr_in data_addr;

    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        error("ERROR opening data socket");
    }

    // Here, typically passive mode should be implemented, but for simplicity, we use active mode
    snprintf(command, sizeof(command), "PORT %d,%d,%d,%d,%d,%d",
             (data_sockfd >> 24) & 0xFF, (data_sockfd >> 16) & 0xFF, 
             (data_sockfd >> 8) & 0xFF, data_sockfd & 0xFF,
             (FTP_PORT >> 8) & 0xFF, FTP_PORT & 0xFF);

    send_command(sockfd, command);
    receive_response(sockfd);

    // Start file upload
    snprintf(command, sizeof(command), "STOR %s", remote_file_name);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Open file to send
    FILE *file = fopen(local_file_path, "rb");
    if (!file) {
        error("Failed to open the local file");
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        send(data_sockfd, buffer, bytes_read, 0);
    }

    fclose(file);
    close(data_sockfd);
    receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <local_file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *local_file_path = argv[4];
    const char *remote_file_name = "uploaded_file.txt";

    int sockfd = connect_to_ftp(hostname);
    receive_response(sockfd);

    authenticate(sockfd, username, password);
    
    // Upload the file
    upload_file(sockfd, local_file_path, remote_file_name);

    // Logout
    send_command(sockfd, "QUIT");
    receive_response(sockfd);
    
    close(sockfd);
    return 0;
}