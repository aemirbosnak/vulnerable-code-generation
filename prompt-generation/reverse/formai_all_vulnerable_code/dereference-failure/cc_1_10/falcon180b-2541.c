//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024
#define SERVER_PORT 25
#define SERVER_IP "127.0.0.1"

int sock;
int client_socket;
struct sockaddr_in server_addr;
char buffer[BUFFER_SIZE];
char* message;
int message_size;

void* send_message(void* arg) {
    int bytes_sent = 0;
    while (bytes_sent < message_size) {
        int sent_bytes = send(client_socket, message + bytes_sent, message_size - bytes_sent, 0);
        if (sent_bytes == -1) {
            printf("Error sending message: %s\n", strerror(errno));
            break;
        }
        bytes_sent += sent_bytes;
    }
    close(client_socket);
    return NULL;
}

int main() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }
    printf("Connected to server\n");
    char* response;
    while (1) {
        if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
            printf("Error receiving data from server: %s\n", strerror(errno));
            break;
        }
        response = strstr(buffer, "250");
        if (response!= NULL) {
            printf("Server ready to receive message\n");
            char* email = "test@example.com";
            char* subject = "Test SMTP Message";
            char* body = "This is a test SMTP message.";
            message_size = strlen(email) + strlen(subject) + strlen(body) + 100;
            message = malloc(message_size);
            sprintf(message, "HELO %s\r\nMAIL FROM:<%s>\r\nRCPT TO:<%s>\r\nDATA\r\nSUBJECT:%s\r\n\r\n%s\r\n.\r\nQUIT\r\n", email, email, email, subject, body);
            pthread_t thread_id[MAX_THREADS];
            int i = 0;
            while (i < MAX_THREADS && (response = strstr(buffer, "250"))!= NULL) {
                pthread_create(&thread_id[i], NULL, send_message, message);
                i++;
            }
            free(message);
        }
    }
    close(sock);
    return 0;
}