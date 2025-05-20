//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXBUFFER 1024

// Function to encrypt the data using a special algorithm
char* encryptData(char* data){
    char* encryptedData = (char*) malloc(strlen(data) + 1);
    int i;
    for(i=0;i<strlen(data);i++){
        encryptedData[i] = data[i] + 3; // Add 3 to each character's ASCII value
    }
    encryptedData[strlen(data)] = '\0';
    return encryptedData;
}

// Function to decrypt the data using the same special algorithm
char* decryptData(char* data){
    char* decryptedData = (char*) malloc(strlen(data) + 1);
    int i;
    for(i=0;i<strlen(data);i++){
        decryptedData[i] = data[i] - 3; // Subtract 3 from each character's ASCII value
    }
    decryptedData[strlen(data)] = '\0';
    return decryptedData;
}

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[MAXBUFFER] = {0};
    char* message = (char*) malloc(MAXBUFFER);

    // Ask user for the message to send
    printf("Enter your secret message: ");
    scanf("%[^\t\n]", message);

    // Encrypt the message before sending it over the network
    char* encryptedMessage = encryptData(message);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Send the encrypted message to the server
    send(sock , encryptedMessage , strlen(encryptedMessage) , 0 );
    printf("Message sent to server\n");

    // Wait for the response from the server
    valread = read( sock , buffer, MAXBUFFER);

    // Decrypt the response received from the server
    char* decryptedResponse = decryptData(buffer);

    printf("%s\n",decryptedResponse);

    // Free the dynamically allocated memory
    free(message);
    free(encryptedMessage);
    free(decryptedResponse);
    return 0;
}