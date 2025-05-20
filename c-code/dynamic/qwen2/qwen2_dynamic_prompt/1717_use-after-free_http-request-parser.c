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
    char *data = (char *)malloc(100);
    strcpy(data, "Sensitive data");

    free(data); // Freeing the memory

    // Using freed memory
    printf("Data: %s\n", data); // Use-after-free
}

int main() {
    char request[MAX_LINE_LENGTH];
    fgets(request, sizeof(request), stdin);

    parse_request(request);

    return 0;
}
