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

    // Use-after-free vulnerability
    free(method); // Freeing memory that will be accessed later
}

int main() {
    char *request = malloc(MAX_LINE_LENGTH);
    if (request == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter HTTP request:\n");
    fgets(request, MAX_LINE_LENGTH, stdin);

    parse_request(request);

    free(request); // Freeing allocated memory

    // Accessing freed memory
    printf("Request after free: %s\n", request); // Use-after-free

    return 0;
}
