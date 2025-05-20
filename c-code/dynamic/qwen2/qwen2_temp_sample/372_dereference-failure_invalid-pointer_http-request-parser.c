#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

// Simulated function to parse a simple HTTP request
void parse_http_request(char *buffer) {
    char *method = strtok(buffer, " ");
    if (method == NULL) return;

    char *url = strtok(NULL, " ");
    if (url == NULL) return;

    // Dereference failure here: accessing an invalid pointer
    printf("Method: %s, URL: %s\n", method, url);
}

int main() {
    FILE *file = fopen("http_requests.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        parse_http_request(buffer);
    }

    fclose(file);
    return EXIT_SUCCESS;
}
