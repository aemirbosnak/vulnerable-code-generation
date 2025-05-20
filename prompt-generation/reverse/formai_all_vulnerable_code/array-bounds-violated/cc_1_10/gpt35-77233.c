//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define MAX_MSG_LENGTH 200

void error(char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]) 
{
	int client_socket, server_port, server_addr_length, n;
	char server_ip[20], message[MAX_MSG_LENGTH], server_response[MAX_MSG_LENGTH];
	struct sockaddr_in server_address;
	
	if(argc != 3) {
		fprintf(stderr,"Usage: %s Server_IP_Address Server_Port_Number\n", argv[0]);
		exit(1);
	}

	server_addr_length = sizeof(server_address);
	memset(&server_address, 0, server_addr_length);

	// set server address details
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(atoi(argv[2]));
	
	if(inet_pton(AF_INET, argv[1], &server_address.sin_addr)<=0) {
		error("Invalid address/ Address not supported");
	}

	// create socket
	if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		error("Failed to create socket");
	}

	// connect to server
	if (connect(client_socket, (struct sockaddr *)&server_address, server_addr_length) < 0) {
		error("Failed to connect to server");
	}

	// communicate with server
	printf("Enter message: ");
	fgets(message, MAX_MSG_LENGTH, stdin);

	// send message to server
	if (send(client_socket, message, strlen(message), 0) < 0) {
		error("Failed to send message to server");
	}

	// receive response from server
	if ((n = recv(client_socket, server_response, MAX_MSG_LENGTH, 0)) < 0) {
		error("Failed to receive response from server");
	}

	server_response[n] = '\0';
	printf("Server response: %s\n", server_response);

	close(client_socket);
	return 0;
}