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

    // Deliberate null pointer dereference vulnerability
    char *header = strtok(NULL, "\r\n");
    while (header != NULL) {
        printf("Header: %s\n", header);
        header = strtok(NULL, "\r\n");
    }

    // Null pointer dereference
    char *body = strtok(NULL, "\r\n");
    printf("Body: %s\n", body); // This will cause a segmentation fault if body is NULL
}

int main() {
    char request[MAX_LINE_LENGTH];
    fgets(request, sizeof(request), stdin);

    parse_request(request);

    return 0;
}
