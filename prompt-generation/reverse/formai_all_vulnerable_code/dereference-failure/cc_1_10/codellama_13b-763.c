//Code Llama-13B DATASET v1.0 Category: Website Uptime Monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT 80
#define MAX_HOSTNAME_LEN 256
#define MAX_BUFFER_LEN 1024

struct hostent *host;
struct sockaddr_in server_addr;
int sock;
char *hostname;
char *buffer;

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: failed to resolve hostname %s\n", hostname);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: failed to create socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = *(uint32_t *)host->h_addr_list[0];

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: failed to connect to host %s\n", hostname);
        return 1;
    }

    buffer = (char *)malloc(MAX_BUFFER_LEN);
    if (buffer == NULL) {
        printf("Error: failed to allocate memory\n");
        return 1;
    }

    while (1) {
        time_t start_time = time(NULL);
        if (send(sock, "GET / HTTP/1.0\r\n\r\n", 19, 0) == -1) {
            printf("Error: failed to send request\n");
            return 1;
        }

        int bytes_received = recv(sock, buffer, MAX_BUFFER_LEN, 0);
        if (bytes_received == -1) {
            printf("Error: failed to receive response\n");
            return 1;
        }

        time_t end_time = time(NULL);
        printf("Request took %d seconds\n", (int)(end_time - start_time));

        printf("Response:\n");
        printf("%s\n", buffer);

        sleep(5);
    }

    return 0;
}