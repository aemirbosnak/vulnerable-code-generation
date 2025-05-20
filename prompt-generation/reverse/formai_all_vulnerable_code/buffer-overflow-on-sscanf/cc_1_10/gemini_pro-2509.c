//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9000
#define BUFSIZE 1024

struct product {
	int id;
	char name[256];
	int quantity;
	float price;
};

int main() {
	int server_fd, client_fd;
	struct sockaddr_in server_addr, client_addr;
	socklen_t client_addr_size;
	char buf[BUFSIZE];

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0) {
		perror("socket");
		exit(1);
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORT);

	if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		perror("bind");
		exit(1);
	}

	if (listen(server_fd, 5) < 0) {
		perror("listen");
		exit(1);
	}

	while (1) {
		client_addr_size = sizeof(client_addr);
		client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_size);
		if (client_fd < 0) {
			perror("accept");
			continue;
		}

		memset(buf, 0, BUFSIZE);
		recv(client_fd, buf, BUFSIZE, 0);
		printf("Received: %s\n", buf);

		struct product product;
		memset(&product, 0, sizeof(product));
		sscanf(buf, "%d %s %d %f", &product.id, product.name, &product.quantity, &product.price);

		// Process the product here

		memset(buf, 0, BUFSIZE);
		sprintf(buf, "%d %s %d %f", product.id, product.name, product.quantity, product.price);
		send(client_fd, buf, BUFSIZE, 0);

		close(client_fd);
	}

	close(server_fd);

	return 0;
}