//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan (1-1024)
#define MAX_HOST_LENGTH 50  // maximum length of hostname

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host_ip>\n", argv[0]);
        return 1;
    }

    // parse host IP address
    char *host_ip = argv[1];
    struct hostent *host;
    host = gethostbyname(host_ip);
    if (host == NULL) {
        printf("Invalid hostname or IP address\n");
        return 2;
    }

    // create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 3;
    }

    // set up the address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0); // 0 indicates all ports
    inet_pton(AF_INET, host_ip, &server_addr.sin_addr);

    // connect to the host
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        close(sock);
        return 4;
    }

    // iterate over the port range
    for (int i = 1; i <= PORT_RANGE; i++) {
        // construct the socket address structure
        struct sockaddr_in client_addr;
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(i);
        inet_pton(AF_INET, host_ip, &client_addr.sin_addr);

        // send a SYN packet to the host
        if (send(sock, &client_addr, sizeof(client_addr), 0) < 0) {
            perror("send() failed");
            continue;
        }

        // receive the response
        int j = 1;
        char buffer[256];
        while (j > 0) {
            int received = recv(sock, buffer, 256, 0);
            if (received < 0) {
                perror("recv() failed");
                break;
            }
            j -= received;
            buffer[j] = '\0';
            printf("Received response from port %d: %s\n", i, buffer);
        }
    }

    // close the socket
    close(sock);

    return 0;
}