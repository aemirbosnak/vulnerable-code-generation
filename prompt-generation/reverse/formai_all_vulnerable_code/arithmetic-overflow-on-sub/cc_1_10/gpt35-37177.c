//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define SERVER_IP "1.1.1.1"

int main(){
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr)<=0){
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        perror("connection error");
        return -1;
    }

    // Get the start time
    clock_t start_time = clock();

    // Send data to the server
    char *message = "Hello from the client\r\n";
    if(send(sock, message, strlen(message), 0) != strlen(message)){
        perror("send error");
        return -1;
    }

    // Receive data from the server
    if ((valread = read(sock, buffer, BUFFER_SIZE)) < 0){
        perror("read error");
        return -1;
    }

    // Get the end time
    clock_t end_time = clock();

    // Calculate the total time taken
    double total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Server Response: %s\n", buffer);
    printf("Time Taken: %.2f sec\n", total_time);

    // Close the socket
    close(sock);

    return 0;
}