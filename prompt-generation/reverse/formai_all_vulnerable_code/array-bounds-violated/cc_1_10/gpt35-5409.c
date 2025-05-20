//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void send_file(int sock, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return;
    }
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        if (send(sock, buffer, bytes_read, 0) != bytes_read) {
            printf("Error: failed to send file '%s'\n", filename);
            break;
        }
    }
    fclose(file);
}

void receive_file(int sock, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not create file '%s'\n", filename);
        return;
    }
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        if (fwrite(buffer, 1, bytes_received, file) != (size_t)bytes_received) {
            printf("Error: failed to write to file '%s'\n", filename);
            break;
        }
    }
    fclose(file);
}

int main(int argc, char **argv) {
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(21);
    if (connect(client_sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: could not connect to server\n");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    if ((bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0)) < 0) {
        printf("Error: failed to receive message from server\n");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    char *username = "user anonymous\n";
    send(client_sock, username, strlen(username), 0);
    if ((bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0)) < 0) {
        printf("Error: failed to receive message from server\n");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    char *password = "pass anonymous\n";
    send(client_sock, password, strlen(password), 0);
    if ((bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0)) < 0) {
        printf("Error: failed to receive message from server\n");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    char *filename = "example.txt";
    char *get_command = malloc(strlen(filename) + 6);
    sprintf(get_command, "get %s\n", filename);
    send(client_sock, get_command, strlen(get_command), 0);
    receive_file(client_sock, filename);
    char *put_command = malloc(strlen(filename) + 6);
    sprintf(put_command, "put %s\n", filename);
    send(client_sock, put_command, strlen(put_command), 0);
    send_file(client_sock, filename);
    return 0;
}