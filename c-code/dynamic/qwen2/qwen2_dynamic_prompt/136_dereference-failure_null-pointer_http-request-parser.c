#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void parse_http_request(char *request) {
    char *method = strtok(request, " ");
    if (!method) return;

    char *url = strtok(NULL, " ");
    if (!url) return;

    char *version = strtok(NULL, "\r\n");
    if (!version) return;

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);

    // Deliberate null pointer dereference vulnerability
    char *header = strtok(NULL, "\r\n");
    while (header) {
        if (strncmp(header, "Content-Length:", 15) == 0) {
            int content_length = atoi(header + 16);
            char *body = malloc(content_length);
            if (!body) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            memcpy(body, header + 16 + strlen("Content-Length:"), content_length);
            body[content_length] = '\0';
            printf("Body: %s\n", body);
            free(body);
        }
        header = strtok(NULL, "\r\n");
    }
}

int main() {
    char request[MAX_LINE_LENGTH];
    fgets(request, sizeof(request), stdin);
    parse_http_request(request);
    return 0;
}
