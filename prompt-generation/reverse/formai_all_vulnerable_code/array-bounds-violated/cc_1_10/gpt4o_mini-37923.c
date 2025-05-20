//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <pthread.h>

#define PORT 8888
#define BUFFER_SIZE 8192

void *handle_client(void *client_socket);
void surreal_http_response(int client_sock);

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        fprintf(stderr, "A lone star fell from the sky; I cannot create the socket of dreams.\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "The binding of reality unravelled. Goodbye, sweet HTTP Proxy.\n");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    listen(server_sock, 10);
    fprintf(stdout, "The surrealist HTTP Proxy awaits, listening to the whispers of the net...\n");

    while (1) {
        addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
        if (client_sock < 0) {
            fprintf(stderr, "Another ephemeral moment lost in the cacophony of chaos.\n");
            continue;
        }

        fprintf(stdout, "A new client has slipped through the veil of existence.\n");
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void*)&client_sock);
        pthread_detach(thread_id);
    }

    close(server_sock);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = *(int*)client_socket;
    char buffer[BUFFER_SIZE];
    int read_size;

    read_size = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (read_size < 0) {
        fprintf(stderr, "The message from beyond was too garbled to comprehend.\n");
        close(sock);
        return NULL;
    }
    
    buffer[read_size] = '\0';
    fprintf(stdout, "A message from the cosmos: \n%s\n", buffer);
    
    surreal_http_response(sock);

    close(sock);
    fprintf(stdout, "The portal to the other side has been sealed.\n");
    return NULL;
}

void surreal_http_response(int client_sock) {
    char *header = "HTTP/1.1 200 OK\r\n"
                   "Content-Type: text/html\r\n"
                   "Connection: close\r\n\r\n";

    char *body = "<html><head><title>Surrealist Proxy</title></head>"
                 "<body><h1>Welcome, Seeker of Bizarre Proxies!</h1>"
                 "<p>Your connection is but a mirage in the infinite desert of the web.</p>"
                 "<p>If you see this message, the stars have aligned in your favor!</p></body></html>";

    send(client_sock, header, strlen(header), 0);
    send(client_sock, body, strlen(body), 0);
    fprintf(stdout, "The voiceless echoes of the universe have been sent forth as a response.\n");
}