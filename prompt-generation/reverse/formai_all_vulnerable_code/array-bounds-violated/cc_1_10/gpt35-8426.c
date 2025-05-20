//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char const *argv[])
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		printf("Error: socket creation failed!\n");
		return -1;
	}

	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("Error: connection failed!\n");
		return -1;
	}

	printf("Connected to server at %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

	char buffer[BUFSIZE];
	memset(buffer, 0, BUFSIZE);

	while (1)
	{
		printf("Enter a message:\n");

		if (fgets(buffer, BUFSIZE, stdin) == NULL)
			break;

		if (strlen(buffer) == 1)
			continue;

		int sent_bytes = send(sock, buffer, strlen(buffer), 0);
		if (sent_bytes == -1)
		{
			printf("Error: failed to send message!\n");
			break;
		}

		int recv_bytes = recv(sock, buffer, BUFSIZE, 0);
		if (recv_bytes == -1)
		{
			printf("Error: failed to receive message!\n");
			break;
		}

		buffer[recv_bytes] = '\0';

		printf("Server response: %s\n", buffer);
	}

	close(sock);
	return 0;
}