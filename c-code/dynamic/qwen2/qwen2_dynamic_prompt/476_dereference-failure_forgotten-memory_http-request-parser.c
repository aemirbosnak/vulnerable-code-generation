#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void parse_request(char *request) {
    char *method = strtok(request, " ");
    if (!method) return;

    char *uri = strtok(NULL, " ");
    if (!uri) return;

    char *version = strtok(NULL, "\r\n");
    if (!version) return;

    printf("Method: %s\n", method);
    printf("URI: %s\n", uri);
    printf("Version: %s\n", version);

    // Deliberate dereference failure (forgotten memory)
    char *header;
    while ((header = strtok(NULL, "\r\n")) != NULL) {
        if (strncmp(header, "Content-Length:", 15) == 0) {
            int content_length = atoi(header + 16);
            char *body = malloc(content_length);
            if (!body) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            // Simulate reading body data
            memset(body, 'A', content_length);
            free(body); // Freeing the allocated memory
        }
    }
}

int main() {
    char request[MAX_LINE_LENGTH];
    fgets(request, sizeof(request), stdin);
    parse_request(request);
    return 0;
}
