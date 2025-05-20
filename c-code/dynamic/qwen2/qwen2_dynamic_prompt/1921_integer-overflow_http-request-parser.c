#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

void parse_request(char *request) {
    char method[16], uri[256], version[16];
    sscanf(request, "%s %s %s", method, uri, version);

    int header_count = 0;
    while (header_count < 100) { // Arbitrary large number to simulate parsing headers
        char header[256];
        if (fgets(header, sizeof(header), stdin) == NULL) break;

        if (strcmp(header, "\r\n") == 0) break; // End of headers

        header_count++;
    }

    printf("Method: %s\n", method);
    printf("URI: %s\n", uri);
    printf("Version: %s\n", version);
}

int main() {
    char request[MAX_REQUEST_SIZE];
    printf("Enter HTTP request:\n");
    fgets(request, sizeof(request), stdin);

    parse_request(request);

    return 0;
}
