//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void print_welcome_message() {
    printf("====================================\n");
    printf("       POP3 Client Example          \n");
    printf("        By a Creative Mind          \n");
    printf("====================================\n");
}

char* build_command(const char *command, const char *param) {
    char *full_command = malloc(BUFFER_SIZE);
    snprintf(full_command, BUFFER_SIZE, "%s %s\r\n", command, param);
    return full_command;
}

void read_response(int socket_fd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket_fd, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_received < 0) {
        error("Failed to receive response");
    }
    
    buffer[bytes_received] = '\0'; 
    printf("Server Response: %s", buffer);
}

void process_pop3_commands(int socket_fd) {
    char username[50];
    char password[50];
    
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    char *user_command = build_command("USER", username);
    send(socket_fd, user_command, strlen(user_command), 0);
    read_response(socket_fd);
    free(user_command);

    char *pass_command = build_command("PASS", password);
    send(socket_fd, pass_command, strlen(pass_command), 0);
    read_response(socket_fd);
    free(pass_command);

    char *list_command = "LIST\r\n";
    send(socket_fd, list_command, strlen(list_command), 0);
    read_response(socket_fd);

    char *quit_command = "QUIT\r\n";
    send(socket_fd, quit_command, strlen(quit_command), 0);
    read_response(socket_fd);
}

int main() {
    int socket_fd;
    struct sockaddr_in server_address;

    print_welcome_message();

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error("Unable to open socket");
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace this with the actual server IP

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Connection failed");
    }

    read_response(socket_fd); // Read the initial greeting from the server
    process_pop3_commands(socket_fd);

    close(socket_fd);
    return 0;
}