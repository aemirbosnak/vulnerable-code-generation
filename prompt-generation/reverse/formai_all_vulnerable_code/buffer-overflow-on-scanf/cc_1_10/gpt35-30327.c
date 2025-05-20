//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUF_SIZE 2048
#define SERVER_PORT 143

int main(int argc, char* argv[]) {
    int sockfd;
	struct sockaddr_in server_addr;
	char buffer[MAX_BUF_SIZE];
    char username[MAX_BUF_SIZE];
    char password[MAX_BUF_SIZE];
    char command[MAX_BUF_SIZE];

    // Initialize socket structure
    memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);

    // Set server IP address
	if (argc == 2) {
		server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	} else {
		server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	}

    // Create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		printf("Error creating socket\n");
		exit(1);
	}

	// Connect to server
	if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		printf("Error connecting to server\n");
		exit(1);
	}

	// Get user credentials
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Send login command to server
    sprintf(command, "LOGIN %s %s", username, password);
    send(sockfd, command, strlen(command), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    if (strstr(buffer, "OK") == NULL) {
        printf("Error logging in\n");
        exit(1);
    }

    // List all emails
    sprintf(command, "LIST");
    send(sockfd, command, strlen(command), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("\n--- Your inbox ---\n%s\n", buffer);

    // Get email ID to fetch
    int email_id = 0;
    printf("\nEnter email ID to fetch (0 to exit): ");
    scanf("%d", &email_id);
    while (email_id != 0) {
        // Fetch email
        sprintf(command, "FETCH %d", email_id);
        send(sockfd, command, strlen(command), 0);
        memset(buffer, 0, sizeof(buffer));
        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("\n--- Email %d ---\n%s\n", email_id, buffer);
        
        // Get next email ID to fetch
        printf("\nEnter email ID to fetch (0 to exit): ");
        scanf("%d", &email_id);
    }

    // Logout of server
    sprintf(command, "LOGOUT");
    send(sockfd, command, strlen(command), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Logged out successfully\n");

	// Close socket
	close(sockfd);

	return 0;
}