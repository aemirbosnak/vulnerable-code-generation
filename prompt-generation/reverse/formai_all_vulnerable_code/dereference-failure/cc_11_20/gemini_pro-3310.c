//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/utsname.h>

int main(int argc, char *argv[]) {
	#define MAX_RULES 10
	struct rule {
		char *ip;
		int port;
		int proto;
		char *action;
	} rules[MAX_RULES];

	int num_rules = 0;
	int sockfd;
	struct sockaddr_in servaddr, cliaddr;
	//socklen_t len;
    struct utsname os_info;
    char *kernel, *hostname;
     char *incoming_ip, *incoming_port, incoming_proto;
     char *action;

	// Get the kernel and hostname information
	uname(&os_info);
	kernel = os_info.release;
	hostname = os_info.nodename;

	// Get the incoming IP address, port, and protocol
	incoming_ip = argv[1];
	incoming_port = argv[2];
	incoming_proto = argv[3];

	// Get the action to take
	action = argv[4];

	// Create the socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("socket");
		exit(1);
	}

	// Set the socket address
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(1234);

	// Bind the socket to the address
	if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
		perror("bind");
		exit(1);
	}

	// Listen for connections
	if (listen(sockfd, 5) == -1) {
		perror("listen");
		exit(1);
	}

	while (1) {
		// Accept connections
		int len = sizeof(cliaddr);
		int connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
		if (connfd == -1) {
			perror("accept");
			exit(1);
		}

		// Get the incoming IP address, port, and protocol
		incoming_ip = inet_ntoa(cliaddr.sin_addr);
		incoming_port = ntohs(cliaddr.sin_port);
		incoming_proto = "tcp";

		// Check the firewall rules
		int allow = 0;
		for (int i = 0; i < num_rules; i++) {
		struct rule rule = rules[i];
  		if (strcmp(incoming_ip, rule.ip) == 0 && incoming_port == rule.port && incoming_proto == rule.proto) {
			if (strcmp(rule.action, "allow") == 0) {
			allow = 1;
			}
		}
		}

		// Take the appropriate action
		if (allow) {
            printf("Allowing connection from %s:%d\n", incoming_ip, incoming_port);
    		// Send a message to the client
			char *message = "Welcome to the server!\n";
			write(connfd, message, strlen(message));
        } else {
            printf("Denying connection from %s:%d\n", incoming_ip, incoming_port);
			// Send a message to the client
    		char *message = "Connection denied!\n";
    		write(connfd, message, strlen(message));
        }

		// Close the connection
		close(connfd);
	}

	// Close the socket
	close(sockfd);

	return 0;
}