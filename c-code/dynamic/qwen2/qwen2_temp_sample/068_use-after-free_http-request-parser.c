#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

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
    free(url); // Freeing memory that will be used later
}

int main() {
    char buffer[BUFFER_SIZE];
    fgets(buffer, sizeof(buffer), stdin);

    parse_request(buffer);

    // Trigger use-after-free
    printf("%s\n", buffer); // Using freed memory

    return 0;
}
