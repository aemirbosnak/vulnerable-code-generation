#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_http_request(char* request) {
    char* method = strtok(request, " ");
    char* uri = strtok(NULL, " ");
    char* http_version = strtok(NULL, "\n");

    printf("Method: %s\n", method);
    printf("URI: %s\n", uri);
    printf("HTTP Version: %s\n", http_version);

    // Simulate parsing headers
    while (1) {
        char* header_line = fgets(request, sizeof(request), stdin);
        if (header_line == NULL || *header_line == '\n') break;
        printf("Header: %s", header_line);
    }
}

int main() {
    char* request = (char*)malloc(1024);
    printf("Enter HTTP Request:\n");
    fgets(request, sizeof(request), stdin);

    parse_http_request(request);

    // Use-after-free vulnerability
    printf("%s\n", request);  // Use freed memory

    free(request);
    return 0;
}
