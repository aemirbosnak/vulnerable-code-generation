//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define FTP_PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void paranoid_log(const char *msg) {
    FILE *logfile = fopen("ftp_client.log", "a");
    if (logfile == NULL) {
        perror("Error opening log file");
        return;
    }
    fprintf(logfile, "LOG: %s\n", msg);
    fclose(logfile);
}

void establish_connection(int *sockfd, const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *he;

    he = gethostbyname(hostname);
    if (he == NULL) {
        error("Failed to resolve hostname");
    }

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd == -1) {
        error("Failed to create socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("Failed to connect to server");
    }

    paranoid_log("Connected to FTP server");
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) == -1) {
        error("Failed to send command");
    }
    paranoid_log(command);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_received < 0) {
        error("Failed to receive response");
    }

    buffer[bytes_received] = '\0';
    printf("Server: %s\n", buffer);
    paranoid_log(buffer);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "PASV\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);

    // Assume that in passive mode we are getting an IP and port to connect to.
    // This is a simplified representation. You would need to parse the response.
    char *data_server_ip = "127.0.0.1"; // This should be parsed from server response.
    int data_port = 12345; // This should be parsed from server response.

    int data_sockfd;
    establish_connection(&data_sockfd, data_server_ip);

    snprintf(command, sizeof(command), "LIST\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);
    
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(data_sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        paranoid_log(buffer);
    }

    close(data_sockfd);
}

void ftp_quit(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
    paranoid_log("Disconnected from FTP server");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    establish_connection(&sockfd, hostname);
    receive_response(sockfd);

    ftp_login(sockfd, username, password);
    list_files(sockfd);
    ftp_quit(sockfd);

    close(sockfd);
    paranoid_log("Client terminated normally.");
    return EXIT_SUCCESS;
}