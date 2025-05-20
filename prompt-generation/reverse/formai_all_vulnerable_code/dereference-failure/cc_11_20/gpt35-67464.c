//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80

struct node {
    char *ip_address;
    struct node *next;
};

typedef struct node Node;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        exit(1);
    }

    // Get host information
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Could not get host information");
        exit(1);
    }

    // Create socket address
    struct sockaddr_in server;
    server.sin_addr = *((struct in_addr*)host->h_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
        printf("Could not connect to server");
        exit(1);
    }

    // Send request to server
    char *message;
    message = "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Could not send request to server");
        exit(1);
    }

    Node *head = NULL;
    Node *current = NULL;
    char *buffer = malloc(5000*sizeof(char));
    int n;
    while((n = recv(socket_desc, buffer, 5000, 0)) > 0) {
        char *p = strstr(buffer, "href=\"");
        while (p != NULL) {
            if (strncmp(p + 6, "http://", 7) == 0) {
                char *q = strchr(p + 6, '/');
                if (q == NULL)
                    q = strchr(p + 6, '\0');
                *q = '\0';
                if (current == NULL) {
                    head = malloc(sizeof(Node));
                    head->ip_address = strdup(p + 6);
                    head->next = NULL;
                    current = head;
                }
                else {
                    current->next = malloc(sizeof(Node));
                    current->next->ip_address = strdup(p + 6);
                    current->next->next = NULL;
                    current = current->next;
                }
            }
            p = strstr(p + 5, "href=\"");
        }
        memset(buffer, 0, sizeof(buffer));
    }

    printf("List of IP addresses found:\n");
    current = head;
    while (current != NULL) {
        printf("%s\n", current->ip_address);
        current = current->next;
    }

    close(socket_desc);
    exit(0);
}