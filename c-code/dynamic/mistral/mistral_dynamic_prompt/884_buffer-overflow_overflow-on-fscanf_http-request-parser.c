#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

void parse_request(char *input) {
    char method[MAX_BUFFER];
    char url[MAX_BUFFER];
    char version[MAX_BUFFER];
    char buffer[1]; // Intentionally small buffer for buffer overflow

    if (sscanf(input, "%s %s %s\n%s", method, url, version, buffer) == 3) {
        printf("Method: %s\n", method);
        printf("URL: %s\n", url);
        printf("HTTP Version: %s\n", version);
    } else {
        printf("Invalid HTTP request format.\n");
    }
}

int main(int argc, char *argv[]) {
    char input[MAX_BUFFER];

    if (argc < 2) {
        printf("Usage: %s <HTTP request>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);
    parse_request(input);

    return 0;
}
