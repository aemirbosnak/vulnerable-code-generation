//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    char hostname[256];
    int sockfd, result, i;
    struct sockaddr_in server_addr;

    printf("Good evening, Mr. Holmes. Prepare to solve the case of the silent server.\n");

    // Get the hostname from the user
    printf("Please enter the hostname of the server: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Check if the connection is successful
    if (result == -1)
    {
        printf("The connection to the server failed.\n");
        return 1;
    }

    // Send a ping message to the server
    char message[] = "Ping!";
    send(sockfd, message, sizeof(message), 0);

    // Receive the server's response
    char response[256];
    recv(sockfd, response, sizeof(response), 0);

    // Print the server's response
    printf("The server's response is: %s\n", response);

    // Close the socket
    close(sockfd);

    // Conclusion
    printf("The case of the silent server has been solved. The server is alive and well.\n");

    return 0;
}