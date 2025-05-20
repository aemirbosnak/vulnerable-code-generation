//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *message = "Romeo: Good morrow, fair Juliet. I have a great TCP/IP program that will make us communicate with ease!";
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Romeo sends a message to Juliet.
    send(sock, message, strlen(message), 0);
    printf("Romeo: My message to you is sent!\n");

    // Juliet reads the message from Romeo.
    valread = read(sock, buffer, 1024);
    buffer[valread] = '\0';
    printf("\nJuliet: Oh dear Romeo, that's very impressive! Your message was: %s\n", buffer);

    // Juliet replies back to Romeo.
    message = "Juliet: TCP/IP programming is not new to me. But sure, let's communicate with ease!";
    send(sock, message, strlen(message), 0);
    printf("Juliet: I have replied back to you, my dear Romeo!\n");

    // Romeo reads the reply from Juliet.
    valread = read(sock, buffer, 1024);
    buffer[valread] = '\0';
    printf("\nRomeo: Beautiful Juliet, I have received your message, which is: %s\n", buffer);

    // Close the connection.
    printf("Romeo: Our conversation is complete. Farewell, my sweet Juliet.\n");
    close(sock);
    return 0;
}