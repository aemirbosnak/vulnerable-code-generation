#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
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

    // Null pointer dereference vulnerability
    char *header = strtok(NULL, "\r\n");
    while (header) {
        printf("Header: %s\n", header);
        header = strtok(NULL, "\r\n");
    }

    // Dereference null pointer
    char *data = NULL;
    printf("Data: %s\n", data); // This will cause a segmentation fault
}

int main() {
    char request[MAX_LINE_LENGTH];
    fgets(request, sizeof(request), stdin);
    parse_request(request);
    return 0;
}
