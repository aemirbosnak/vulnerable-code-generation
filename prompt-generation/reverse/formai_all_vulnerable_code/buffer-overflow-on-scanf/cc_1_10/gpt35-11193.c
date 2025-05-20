//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

struct device {
    char name[20];
    char ip[20];
};

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    struct device new_device = {"", ""};
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Read device information from node
    printf("Enter device name: ");
    scanf("%s", new_device.name);
    printf("Enter device IP address: ");
    scanf("%s", new_device.ip);

    // Convert struct to string and send to server
    char message[50];
    sprintf(message, "%s:%s", new_device.name, new_device.ip);
    send(sock, message, strlen(message), 0);
    printf("Device information sent to server\n");
    return 0;
}