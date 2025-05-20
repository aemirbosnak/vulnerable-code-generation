//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 42069

int main()
{
    // Creating a socket: It's like building a happy little home for our communication.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Socket couldn't be built! Oops!");
        return -1;
    }

    // IP and port for where we want to send our cheerful messages
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connecting our happy little home to the address we want to talk to
    int connect_status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connect_status < 0)
    {
        perror("Couldn't connect to the happy chat room! Woe is me!");
        return -1;
    }

    // Now let's paint the town red with our messages!
    while (1)
    {
        // Get the cheerful message ready
        char message[1024];
        printf("**Beam me up, Scotty!**\nEnter your happy message: ");
        scanf("%s", message);

        // Send the message with a big smile
        int send_status = send(sockfd, message, strlen(message), 0);
        if (send_status < 0)
        {
            perror("Message didn't make it to outer space! Houston, we have a problem!");
            return -1;
        }

        // Receive the reply with a hearty handshake
        char buffer[1024];
        int recv_status = recv(sockfd, buffer, 1024, 0);
        if (recv_status < 0)
        {
            perror("Message didn't land on our spaceship! Mayday, mayday!");
            return -1;
        }

        // Display the message with a twinkle in our eye
        printf("**Message received from the stars:** %s\n", buffer);
    }

    // Closing the socket when we're done spreading joy
    close(sockfd);
    printf("**Mission accomplished! We're out of this world!**\n");
    return 0;
}