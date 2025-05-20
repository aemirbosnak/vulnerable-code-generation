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

    // Deliberate null pointer dereference vulnerability
    char *header = strtok(NULL, "\r\n");
    while (header) {
        if (strncmp(header, "Content-Length:", 15) == 0) {
            char *length_str = header + 16;
            int content_length = atoi(length_str);
            char *body = malloc(content_length);
            if (!body) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            memcpy(body, request + strlen(method) + strlen(uri) + strlen(version) + 2 + strlen(header) + 2, content_length);
            body[content_length] = '\0';
            printf("Body: %s\n", body);
            free(body);
        }
        header = strtok(NULL, "\r\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <http_request_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char request[MAX_LINE_LENGTH * 10];

    while (fgets(line, sizeof(line), file)) {
        strcat(request, line);
    }

    fclose(file);

    parse_request(request);

    return 0;
}
