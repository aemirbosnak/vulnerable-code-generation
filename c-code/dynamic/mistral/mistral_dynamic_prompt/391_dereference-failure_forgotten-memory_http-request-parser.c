#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_http_request(char* buffer) {
    char* line = strtok(buffer, "\r\n");
    char method[10], uri[200], version[16];
    char* query;

    sscanf(line, "%s %s %s", method, uri, version);

    line = strtok(NULL, "\r\n");
    char header_key[100], header_value[2048];
    while (line && strcmp(line, "\r")) {
        sscanf(line, "%s: %s", header_key, header_value);

        if (!strcmp(header_key, "Host")) {
            char* host = strtok(header_value, " ");
            if (host) {
                char ip[32];
                inet_pton(AF_INET, host, (void*)ip);
                printf("IP: %s\n", ip);
            }
        }

        line = strtok(NULL, "\r\n");
    }

    line = strtok(NULL, "\r\n");
    char body[4096];
    if (line) {
        strcpy(body, line);
        printf("Body: %s\n", body);

        char* data = malloc(strlen(body) + 1);
        strcpy(data, body);
        free(data); // Memory leak
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <http request>\n", argv[0]);
        return 1;
    }

    char* request = argv[1];
    parse_http_request(request);

    return 0;
}
