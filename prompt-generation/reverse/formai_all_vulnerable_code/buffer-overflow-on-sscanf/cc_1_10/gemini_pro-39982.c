//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

#define MAX_LINE 1024
#define MAX_HOPS 30

typedef struct {
    int        ttl;
    char        *ip_addr;
    char        *host_name;
    double      rtt;
    int         hops_to;
} hop_info;

int main() {
    int                 sock;
    struct sockaddr_in  server_addr;
    char                line[MAX_LINE];
    char                *host_name;
    struct hostent      *host_ent;
    int                 i, hops;
    hop_info             hop_list[MAX_HOPS];

    // Get the host name
    printf("Enter the host name: ");
    fflush(stdout);
    fgets(line, MAX_LINE, stdin);
    host_name = strtok(line, "\n");

    // Resolve the host name
    host_ent = gethostbyname(host_name);
    if (host_ent == NULL) {
        printf("Error resolving host name\n");
        return 1;
    }

    // Create the socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(33434);
    server_addr.sin_addr = *((struct in_addr *)host_ent->h_addr);

    // Track the hops
    hops = 0;
    for (i = 1; i <= MAX_HOPS; i++) {
        // Set the TTL
        if (setsockopt(sock, IPPROTO_IP, IP_TTL, &i, sizeof(i)) == -1) {
            printf("Error setting TTL\n");
            return 1;
        }

        // Send a message to the server
        if (sendto(sock, "Hello", 5, 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            printf("Error sending message\n");
            return 1;
        }

        // Receive the response from the server
        if (recvfrom(sock, line, MAX_LINE, 0, NULL, NULL) == -1) {
            printf("Error receiving response\n");
            return 1;
        }

        // Parse the response from the server
        sscanf(line, "%s %lf %d", hop_list[hops].ip_addr, &hop_list[hops].rtt, &hop_list[hops].hops_to);

        // Resolve the IP address
        host_ent = gethostbyaddr((char *)&hop_list[hops].ip_addr, 4, AF_INET);
        if (host_ent == NULL) {
            printf("Error resolving IP address\n");
            return 1;
        }
        hop_list[hops].host_name = strdup(host_ent->h_name);

        // Print the hop information
        printf("%2d: %-20s %-20s %5.3f ms %d hops\n", i, hop_list[hops].ip_addr, hop_list[hops].host_name, hop_list[hops].rtt, hop_list[hops].hops_to);

        // Check if we have reached the destination
        if (hop_list[hops].hops_to == 0) {
            break;
        }

        // Increment the hop count
        hops++;
    }

    // Close the socket
    close(sock);

    return 0;
}