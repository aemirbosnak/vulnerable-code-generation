//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_REQUEST_LEN 1000
#define MAX_RESPONSE_LEN 10000

typedef struct {
    char *hostname;
    char *path;
    int port;
} URL;

char *get_ip(char *hostname) {
    struct hostent* host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        return NULL;
    }
    struct in_addr **addr_list = (struct in_addr **) host_entry->h_addr_list;
    char *ip = malloc(INET_ADDRSTRLEN);
    inet_ntop(AF_INET, addr_list[0], ip, INET_ADDRSTRLEN);
    return ip;
}

char *url_encode(char *str) {
    int size = strlen(str);
    char *enc_str = malloc(size * 3 + 1);
    int j = 0;
    for (int i = 0; i < size; i++) {
        char ch = str[i];
        if ((ch >= '0' && ch <= '9') ||
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                ch == '-' || ch == '_' || ch == '.' || ch == '~') {
            enc_str[j++] = ch;
        } else {
            j += sprintf(enc_str + j, "%%%X", ch);
        }
    }
    enc_str[j] = '\0';
    return enc_str;
}

char *http_get(char *hostname, int port, char *path) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return NULL;
    }
    char *ip = get_ip(hostname);
    if (ip == NULL) {
        perror("gethostbyname");
        close(sock);
        return NULL;
    }
    struct sockaddr_in server = {.sin_family = AF_INET, .sin_port = htons(port)};
    inet_pton(AF_INET, ip, &server.sin_addr);
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect");
        close(sock);
        free(ip);
        return NULL;
    }
    free(ip);

    char request[MAX_REQUEST_LEN];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    if (send(sock, request, strlen(request), 0) < 0) {
        perror("send");
        close(sock);
        return NULL;
    }

    char response[MAX_RESPONSE_LEN] = {'\0'};
    char buffer[1000];
    int received_len;
    while ((received_len = recv(sock, buffer, 999, 0)) > 0) {
        buffer[received_len] = '\0';
        strcat(response, buffer);
    }
    close(sock);

    return strdup(response);
}

int main() {
    URL google = {.hostname = "www.google.com", .path = "/", .port = 80};

    char *response = http_get(google.hostname, google.port, google.path);
    if (response == NULL) {
        printf("Request failed\n");
        return 1;
    }

    // Print the response
    printf("%s", response);

    free(response);

    return 0;
}