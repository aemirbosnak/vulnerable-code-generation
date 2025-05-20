//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: romantic
#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>   
#include <unistd.h>   
#include <arpa/inet.h> 
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void serve_request(int client_sock) {
    char buffer[BUFFER_SIZE];
    char *server_response;
    char *http_request_line;
    
    // Listen to the heartbeat of the client
    int read_size = recv(client_sock, buffer, sizeof(buffer), 0);
    if (read_size < 0) {
        perror("Hearken the shattering of dreams.");
        close(client_sock);
        return;
    }
    
    buffer[read_size] = '\0'; // End of request, just like a perfect kiss
    http_request_line = strtok(buffer, "\n"); // Capture the first line, oh sweet beginnings!

    char *method = strtok(http_request_line, " ");
    char *url = strtok(NULL, " ");
    char *version = strtok(NULL, " ");
    
    if (method == NULL || url == NULL) {
        perror("A love unreciprocated.");
        close(client_sock);
        return;
    }

    // Tame the URL into its components for the sweet rendezvous
    char host[100], path[256];
    sscanf(url, "http://%99[^/]/%255s", host, path);
    
    // My dear, it's time to reach out to the distant lover
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Fate has dealt us a cruel hand.");
        close(client_sock);
        return;
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    // Turn to the light of their IP address
    struct in_addr server_ip;
    inet_pton(AF_INET, host, &server_ip);
    
    server_addr.sin_addr = server_ip;

    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("A heart shattered by distance.");
        close(client_sock);
        close(server_sock);
        return;
    }

    // A passionate connection has blossomed
    send(server_sock, buffer, read_size, 0);

    // Let's carry this love story forward
    while ((read_size = recv(server_sock, buffer, sizeof(buffer), 0)) > 0) {
        send(client_sock, buffer, read_size, 0);
    }

    // As all tales must come to an end, close our fleeting encounter
    close(server_sock);
    close(client_sock);
}

int main() {
    int proxy_sock, client_sock;
    struct sockaddr_in proxy_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // The beginning of our tale: the birth of a proxy server
    proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        perror("The path of true love is often full of obstacles.");
        exit(EXIT_FAILURE);
    }

    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY; // We embrace all
    proxy_addr.sin_port = htons(PORT);

    if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Alas, the binding did not hold.");
        close(proxy_sock);
        exit(EXIT_FAILURE);
    }
    
    // Awaiting eager souls
    if (listen(proxy_sock, 5) < 0) {
        perror("A wait for true love can feel eternal.");
        close(proxy_sock);
        exit(EXIT_FAILURE);
    }
    
    printf("Our Proxied Hearts Beat Together: Listening on port %d\n", PORT);
    
    // The eternal wait for a connection, a test of patience
    while (1) {
        client_sock = accept(proxy_sock, (struct sockaddr*)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("But the universe still whispers joys of connection.");
            continue;
        }
        
        // Let their stories intertwine
        serve_request(client_sock);
    }

    close(proxy_sock); // As every good story comes to a gentle close
    return 0;
}