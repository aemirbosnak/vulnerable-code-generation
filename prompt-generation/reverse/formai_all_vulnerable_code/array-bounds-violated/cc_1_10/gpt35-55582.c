//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 8192

// Define a function to send a request to the network device and return the response
char* send_request(char* ip_address, int port, char* request) {
    int sockfd, numbytes;
    char buf[MAX_BUF_SIZE];
    struct sockaddr_in dest;
    char* response = NULL;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set the attributes of the destination address
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    dest.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the network device
    if (connect(sockfd, (struct sockaddr*)&dest, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the request to the device
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the response from the device
    if ((numbytes = recv(sockfd, buf, MAX_BUF_SIZE - 1, 0)) == -1) {
        perror("recv");
        exit(1);
    }
    buf[numbytes] = '\0';
    response = strdup(buf);

    // Close the socket
    close(sockfd);

    return response;
}

int main(int argc, char* argv[]) {
    char* response;

    // Send a request to a device with IP address 192.168.0.1 on port 22
    response = send_request("192.168.0.1", 22, "GET / HTTP/1.0\r\n\r\n");

    // Print the response
    printf("%s\n", response);

    // Free the memory allocated for the response
    free(response);

    return 0;
}