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
    while (fgets(request, MAX_LINE_LENGTH, stdin)) {
        if (strcmp(request, "\r\n") == 0) break;
        printf("Header: %s", request);
    }
}

int main() {
    char request[MAX_LINE_LENGTH];
    printf("Enter HTTP request:\n");
    fgets(request, MAX_LINE_LENGTH, stdin);

    parse_request(request);

    return 0;
}
