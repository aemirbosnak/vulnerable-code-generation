//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define PORT 21

int control_socket;

void *receive_response(void *arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(control_socket, buffer, sizeof(buffer)-1, 0);
        if (bytes_received <= 0) {
            perror("Connection closed by server");
            exit(EXIT_FAILURE);
        }
        printf("%s", buffer);
    }
    return NULL;
}

void connect_to_server(const char *server_ip) {
    struct sockaddr_in server_addr;
    control_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (control_socket < 0) {
        perror("Cannot create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(control_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    printf("Connected to FTP server\n");

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, receive_response, NULL);
}

void send_command(const char *command) {
    send(control_socket, command, strlen(command), 0);
}

void list_files() {
    send_command("PASV\r\n");
    // Wait for a response to the PASV command

    // Additional code would need to extract the PASV response and set up a data connection...

    send_command("LIST\r\n");
}

void download_file(const char *filename) {
    send_command("PASV\r\n");
    // Improve to actually retrieve PASV mode...

    char command[BUFFER_SIZE];
    sprintf(command, "RETR %s\r\n", filename);
    send_command(command);
}

void upload_file(const char *filename) {
    send_command("PASV\r\n");
    // Improve to actually retrieve PASV mode...

    char command[BUFFER_SIZE];
    sprintf(command, "STOR %s\r\n", filename);
    send_command(command);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file for upload");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        send(control_socket, buffer, sizeof(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
    }
    fclose(file);
}

void disconnect() {
    send_command("QUIT\r\n");
    close(control_socket);
    printf("Disconnected from FTP server\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <FTP Server IP>\n", argv[0]);
        return EXIT_FAILURE;
    }

    connect_to_server(argv[1]);
    char command[BUFFER_SIZE];

    while (1) {
        printf("ftp> ");
        fgets(command, sizeof(command), stdin);
        
        if (strncmp(command, "ls", 2) == 0) {
            list_files();
        } else if (strncmp(command, "get", 3) == 0) {
            char filename[BUFFER_SIZE];
            sscanf(command + 4, "%s", filename);
            download_file(filename);
        } else if (strncmp(command, "put", 3) == 0) {
            char filename[BUFFER_SIZE];
            sscanf(command + 4, "%s", filename);
            upload_file(filename);
        } else if (strcmp(command, "exit\n") == 0 || strcmp(command, "quit\n") == 0) {
            disconnect();
            break;
        } else {
            printf("Unknown command: %s", command);
        }
    }
    return EXIT_SUCCESS;
}