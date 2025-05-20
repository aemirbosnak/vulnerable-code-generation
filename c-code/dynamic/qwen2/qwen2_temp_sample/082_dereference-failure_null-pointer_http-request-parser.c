#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void parse_request(char *request) {
    char *method = strtok(request, " ");
    if (method == NULL) return;

    char *url = strtok(NULL, " ");
    if (url == NULL) return;

    char *version = strtok(NULL, "\r\n");
    if (version == NULL) return;

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);

    // Simulate parsing headers
    while (1) {
        char line[MAX_LINE_LENGTH];
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        if (strcmp(line, "\r\n") == 0) break;
        printf("Header: %s", line);
    }
}

int main() {
    char request[MAX_LINE_LENGTH];

    printf("Enter HTTP request:\n");
    if (fgets(request, sizeof(request), stdin) == NULL) {
        fprintf(stderr, "Failed to read input.\n");
        return EXIT_FAILURE;
    }

    parse_request(request);

    return EXIT_SUCCESS;
}
