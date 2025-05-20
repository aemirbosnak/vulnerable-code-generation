//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

typedef struct client_data {
	int socket;
	struct sockaddr_in addr;
	char* buffer;
	int buffer_len;
} client_data;

client_data clients[MAX_CLIENTS];
int client_count = 0;

void handle_client(int socket) {
	char buffer[MAX_BUFFER_SIZE];
	int bytes_received = recv(socket, buffer, MAX_BUFFER_SIZE, 0);
	if (bytes_received < 0) {
		perror("Error receiving data from client");
		close(socket);
		return;
	}

	buffer[bytes_received] = '\0';
	printf("Received data from client: %s", buffer);

	char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello world!</h1></body></html>\r\n";
	int bytes_sent = send(socket, response, strlen(response), 0);
	if (bytes_sent < 0) {
		perror("Error sending data to client");
		close(socket);
		return;
	}

	close(socket);
}

int main(int argc, char* argv[]) {
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket < 0) {
		perror("Error creating server socket");
		return EXIT_FAILURE;
	}

	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);

	if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		perror("Error binding server socket");
		close(server_socket);
		return EXIT_FAILURE;
	}

	if (listen(server_socket, MAX_CLIENTS) < 0) {
		perror("Error listening on server socket");
		close(server_socket);
		return EXIT_FAILURE;
	}

	while (1) {
		struct sockaddr_in client_addr;
		socklen_t client_addr_len = sizeof(client_addr);
		int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
		if (client_socket < 0) {
			perror("Error accepting client connection");
			continue;
		}

		if (client_count >= MAX_CLIENTS) {
			printf("Too many clients connected, closing connection\n");
			close(client_socket);
			continue;
		}

		clients[client_count].socket = client_socket;
		clients[client_count].addr = client_addr;
		clients[client_count].buffer = malloc(MAX_BUFFER_SIZE);
		clients[client_count].buffer_len = 0;
		client_count++;

		printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

		handle_client(client_socket);
	}

	close(server_socket);
	return EXIT_SUCCESS;
}