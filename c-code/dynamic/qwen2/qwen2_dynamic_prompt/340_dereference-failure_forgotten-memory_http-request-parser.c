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

    // Simulate parsing headers
    while (1) {
        char line[MAX_LINE_LENGTH];
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        if (strcmp(line, "\r\n") == 0) break;

        char *header_name = strtok(line, ": ");
        if (!header_name) continue;

        char *header_value = strtok(NULL, "\r\n");
        if (!header_value) continue;

        printf("Header: %s - Value: %s\n", header_name, header_value);
    }
}

int main() {
    char request[MAX_LINE_LENGTH];
    printf("Enter HTTP request:\n");
    if (fgets(request, sizeof(request), stdin) == NULL) {
        fprintf(stderr, "Failed to read input.\n");
        return 1;
    }

    parse_request(request);

    return 0;
}
