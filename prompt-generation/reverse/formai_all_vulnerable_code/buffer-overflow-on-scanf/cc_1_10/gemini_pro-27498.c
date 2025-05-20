//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

int main() {
	int sockfd, n;
	struct sockaddr_in servaddr;
	char buf[4096], *host;
	unsigned short port;
	
	printf("Enter the host: ");
	scanf("%s", buf);
	host = buf;

	printf("Enter the port: ");
	scanf("%hu", &port);

	// Create the socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	// Set the server address
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = inet_addr(host);

	// Connect to the server
	if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
		perror("connect");
		exit(EXIT_FAILURE);
	}

	printf("Connected to the server\n");

	// Send some data to the server
	const char *message = "Hello, world!\n";
	n = write(sockfd, message, strlen(message));
	if (n == -1) {
		perror("write");
		exit(EXIT_FAILURE);
	}

	// Receive some data from the server
	n = read(sockfd, buf, sizeof(buf) - 1);
	if (n == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}

	buf[n] = '\0';
	printf("Received %d bytes from the server: %s\n", n, buf);

	// Close the socket
	close(sockfd);

	return 0;
}