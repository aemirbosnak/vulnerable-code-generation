//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: curious
// Welcome to a curious C TCP/IP Programming example program!
// This program will set up a server and client connection to exchange messages in a "secret language" using a Caesar cipher.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define PORT 8080 // chose a random port number
#define SHIFT 3 // chose a random shift amount for the Caesar cipher

char *encode(char *plaintext)
{
    int i = 0;
    char *ciphertext = (char *)malloc(sizeof(char) * (strlen(plaintext) + 1));
    while (plaintext[i] != '\0')
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = (plaintext[i] - 'a' + SHIFT) % 26 + 'a'; // apply Caesar cipher shift
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = (plaintext[i] - 'A' + SHIFT) % 26 + 'A';
        }
        else
        {
            ciphertext[i] = plaintext[i]; // leave all non-alphabetic characters untouched
        }
        i++;
    }
    ciphertext[i] = '\0';
    return ciphertext;
}

char *decode(char *ciphertext)
{
    int i = 0;
    char *plaintext = (char *)malloc(sizeof(char) * (strlen(ciphertext) + 1));
    while (ciphertext[i] != '\0')
    {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
        {
            plaintext[i] = (ciphertext[i] - 'a' - SHIFT + 26) % 26 + 'a'; // reverse Caesar cipher shift
        }
        else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
        {
            plaintext[i] = (ciphertext[i] - 'A' - SHIFT + 26) % 26 + 'A';
        }
        else
        {
            plaintext[i] = ciphertext[i]; // leave all non-alphabetic characters untouched
        }
        i++;
    }
    plaintext[i] = '\0';
    return plaintext;
}

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char input[1024];
    char *secret_input = "";
    int choice = 0;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("Welcome to the secret language server!\n\n");
    while (1)
    {
        printf("Type 1 to send a message or type 2 to receive a message: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter a message to encode: ");
            scanf(" %[^\n]s", input);
            secret_input = encode(input);
            send(new_socket, secret_input, strlen(secret_input), 0);
            printf("Your secret message has been sent!\n\n");
        }
        else if (choice == 2)
        {
            valread = read(new_socket, buffer, 1024);
            printf("Received secret message: %s\n\n", buffer);
            printf("Decoded message: %s\n\n", decode(buffer));
        }
        else
        {
            printf("Invalid choice. Try again.\n\n");
        }
    }
    return 0;
}