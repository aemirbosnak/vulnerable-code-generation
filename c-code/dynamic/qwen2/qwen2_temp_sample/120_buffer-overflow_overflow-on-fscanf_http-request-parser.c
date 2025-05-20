#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void parse_request(char *request) {
    char method[16];
    char url[256];
    int port = 80;

    // Simulate parsing an HTTP request
    sscanf(request, "%s %s", method, url);

    // Vulnerability: No bounds checking on url
    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
}

int main() {
    char buffer[100];

    printf("Enter HTTP request:\n");
    fgets(buffer, sizeof(buffer), stdin);

    parse_request(buffer);

    return 0;
}
