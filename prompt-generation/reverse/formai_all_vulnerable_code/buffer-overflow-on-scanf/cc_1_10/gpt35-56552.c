//FormAI DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    printf("Greetings! I am a curious networking chatbot.\n");
    printf("Would you like me to demonstrate a networking program for you?\n");

    char response[10];
    scanf("%s", response);

    if (response[0] == 'y')
    {
        printf("Fantastic! Let me show you a program that sends and receives data between two machines.\n");

        // create a socket
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);

        // define the server address
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(9002);
        server_address.sin_addr.s_addr = INADDR_ANY;

        // bind the socket to the server address
        bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

        // listen for incoming connections
        listen(server_socket, 5);

        // accept a client connection
        int client_socket = accept(server_socket, NULL, NULL);

        // send data to the client
        char message[256] = "Hello, client! This is a message from the server.";
        send(client_socket, message, sizeof(message), 0);

        // receive data from the client
        char response[256];
        recv(client_socket, &response, sizeof(response), 0);
        printf("The client sent the following message: %s\n", response);

        // close the sockets
        close(client_socket);
        close(server_socket);

        printf("There you have it! I hope you found this networking example interesting.\n");
    }
    else
    {
        printf("Oh, that's too bad. Maybe another time then!\n");
    }

    return 0;
}