//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT 80

// Function to resolve hostname to IP address
int resolve_host(const char *hostname, struct sockaddr_in *addr) {
    struct hostent *host;
    if ((host = gethostbyname(hostname)) == NULL) {
        printf("Failed to resolve hostname %s\n", hostname);
        return FALSE;
    }
    memcpy(&addr->sin_addr, host->h_addr, host->h_length);
    addr->sin_family = AF_INET;
    return TRUE;
}

// Function to send a packet and receive a response
int send_and_receive(int sock, const char *packet, char *response, int max_response_size) {
    int bytes_sent, bytes_received;
    if ((bytes_sent = send(sock, packet, strlen(packet), 0)) == -1) {
        printf("Failed to send packet\n");
        return FALSE;
    }
    memset(response, 0, max_response_size);
    if ((bytes_received = recv(sock, response, max_response_size, 0)) == -1) {
        printf("Failed to receive response\n");
        return FALSE;
    }
    response[bytes_received] = '\0';
    return TRUE;
}

// Function to perform a ping test
int ping_test(const char *hostname) {
    int sock;
    struct sockaddr_in addr;
    char response[1024];
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Failed to create socket\n");
        return FALSE;
    }
    if (!resolve_host(hostname, &addr)) {
        close(sock);
        return FALSE;
    }
    if (!send_and_receive(sock, "GET / HTTP/1.0\r\n\r\n", response, sizeof(response))) {
        close(sock);
        return FALSE;
    }
    close(sock);
    if (strstr(response, "200 OK")!= NULL) {
        printf("Ping test successful\n");
        return TRUE;
    } else {
        printf("Ping test failed\n");
        return FALSE;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }
    ping_test(argv[1]);
    return 0;
}