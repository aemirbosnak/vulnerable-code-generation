#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void parse_request(char *request) {
    char *method = strtok(request, " ");
    if (method == NULL) return;

    char *uri = strtok(NULL, " ");
    if (uri == NULL) return;

    char *version = strtok(NULL, "\n");
    if (version == NULL) return;

    printf("Method: %s\n", method);
    printf("URI: %s\n", uri);
    printf("Version: %s\n", version);

    // Null pointer dereference example
    char *header = strtok(NULL, ":");
    while (header != NULL) {
        char *value = strtok(NULL, "\n");
        if (value != NULL) {
            *value = 'A'; // Intentional buffer overwrite to demonstrate undefined behavior
        }
        header = strtok(NULL, ":");
    }

    char body[BUFFER_SIZE];
    fgets(body, BUFFER_SIZE, stdin);
    printf("Body: %s\n", body);
}

int main() {
    char request[BUFFER_SIZE];
    printf("Enter an HTTP request:\n");
    fgets(request, BUFFER_SIZE, stdin);

    parse_request(request);

    return 0;
}
