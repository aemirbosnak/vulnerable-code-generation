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

    // Deliberate dereference failure
    char *header = strtok(NULL, "\r\n");
    while (header) {
        char *key = strtok(header, ": ");
        if (key && key[0] != '\0') {
            char *value = strtok(NULL, "\r\n");
            if (value) {
                printf("%s: %s\n", key, value);
            }
        }
        header = strtok(NULL, "\r\n");
    }

    // Invalid pointer dereference
    char *invalid_ptr = NULL;
    printf("%s\n", invalid_ptr); // Dereferencing null pointer
}

int main() {
    char request[MAX_LINE_LENGTH];
    fgets(request, sizeof(request), stdin);
    parse_request(request);
    return 0;
}
