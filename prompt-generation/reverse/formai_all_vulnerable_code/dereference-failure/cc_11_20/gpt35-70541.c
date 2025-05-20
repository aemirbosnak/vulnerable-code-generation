//FormAI DATASET v1.0 Category: Networking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

// Function to handle errors
void error(const char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]) {
	
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <port>\n", argv[0]);
		exit(1);
	}
	
	int sockfd, newsockfd, portno, client_sockets[MAX_CLIENTS];
	char buffer[BUFFER_SIZE];
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen = sizeof(cli_addr);
	fd_set read_fds;
	
	// Create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		error("Error opening socket");
	}
	
	// Clear address structure
	bzero((char*)&serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	
	// Set up server address
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	
	// Bind socket to address
	if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
		error("Error binding socket to address");
	}
	
	// Listen for incoming connections
	if (listen(sockfd, 5) == -1) {
		error("Error listening for incoming connections");
	}
	
	// Initialize client_sockets array
	for (int i = 0; i < MAX_CLIENTS; i++) {
		client_sockets[i] = 0;
	}
	
	while (1) {
		
		// Clear file descriptor set
		FD_ZERO(&read_fds);
		
		// Add server socket to set
		FD_SET(sockfd, &read_fds);
		
		// Add all active client sockets to set
		for (int i = 0; i < MAX_CLIENTS; i++) {
			if (client_sockets[i] > 0) {
				FD_SET(client_sockets[i], &read_fds);
			}
		}
		
		// Select file descriptors that have data ready to be read
		if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) < 0) {
			error("Error selecting file descriptors");
		}
		
		// Check if server socket is in set
		if (FD_ISSET(sockfd, &read_fds)) {
			// Accept incoming connection
			newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
			if (newsockfd < 0) {
				error("Error accepting incoming connection");
			}
			// Add new socket to client_sockets array
			for (int i = 0; i < MAX_CLIENTS; i++) {
				if (client_sockets[i] == 0) {
					client_sockets[i] = newsockfd;
					break;
				}
			}
			printf("New client connected\n");
		}
		
		// Check all active client sockets for data
		for (int i = 0; i < MAX_CLIENTS; i++) {
			if (client_sockets[i] > 0 && FD_ISSET(client_sockets[i], &read_fds)) {
				// Clear buffer
				bzero(buffer, BUFFER_SIZE);
				// Read data from socket
				int nbytes = read(client_sockets[i], buffer, BUFFER_SIZE);
				if (nbytes < 0) {
					error("Error reading from socket");
				}
				if (nbytes == 0) {
					// Connection closed by client
					close(client_sockets[i]);
					client_sockets[i] = 0;
					printf("Client disconnected\n");
				}
				else {
					// Echo data back to client
					for (int j = 0; j < MAX_CLIENTS; j++) {
						if (client_sockets[j] > 0 && client_sockets[j] != client_sockets[i]) {
							nbytes = write(client_sockets[j], buffer, strlen(buffer));
							if (nbytes < 0) {
								error("Error writing to socket");
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}