//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);

    // Creating server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the given address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Waiting for incoming connections...\n");

        if ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr,
                                (socklen_t *) &addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New connection established! ");

        // Cyberpunk style code begins
        char username[100];
        char password[100];
        char filename[100];
        char command[100];
        char input[500];
        char output[500];
        int authorized = 0;
        int file_exists = 0;
        int bytes, i;

        // Authentication
        while (!authorized) {
            bytes = recv(client_fd, input, 500, 0);
            input[bytes] = '\0';

            printf("Received login request: %s\n", input);

            sscanf(input, "%s %s", username, password); // Parsing input

            if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
                printf("Access granted for %s!\n", username);
                authorized = 1;
                send(client_fd, "Access granted!\n", 16, 0);
            } else {
                printf("Access denied for %s!\n", username);
                send(client_fd, "Access denied!\n", 15, 0);
            }
        }

        // File operations
        while (authorized) {
            bytes = recv(client_fd, input, 500, 0);
            input[bytes] = '\0';

            printf("Received command: %s\n", input);

            sscanf(input, "%s %s", command, filename); // Parsing input

            if (strcmp(command, "download") == 0) {
                FILE *fp = fopen(filename, "rb");

                if (fp != NULL) {
                    file_exists = 1;
                    send(client_fd, "OK", 2, 0);

                    while ((bytes = fread(output, 1, 500, fp)) > 0) {
                        send(client_fd, output, bytes, 0);
                    }

                    fclose(fp);
                } else {
                    send(client_fd, "File not found!", 15, 0);
                }
            } else if (strcmp(command, "upload") == 0) {
                if (file_exists) {
                    send(client_fd, "File already exists!", 21, 0);
                } else {
                    send(client_fd, "OK", 2, 0);

                    FILE *fp = fopen(filename, "wb");
                    bytes = recv(client_fd, input, 500, 0);

                    while (bytes > 0) {
                        fwrite(input, 1, bytes, fp);
                        bytes = recv(client_fd, input, 500, 0);
                    }

                    fclose(fp);
                    file_exists = 1;
                }
            } else if (strcmp(command, "exit") == 0) {
                printf("Closing connection with %s...\n", username);
                send(client_fd, "Closing connection...", 21, 0);
                authorized = 0;
            } else {
                send(client_fd, "Invalid command!", 16, 0);
            }
        }

        close(client_fd);
    }

    return 0;
}