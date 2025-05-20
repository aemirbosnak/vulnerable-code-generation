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

    char *url = strtok(NULL, " ");
    if (!url) return;

    char *version = strtok(NULL, "\r\n");
    if (!version) return;

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
    fgets(request, sizeof(request), stdin);

    parse_request(request);

    return 0;
}
