#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

void parse_request(char *request) {
    char method[16];
    char path[256];
    char version[16];

    sscanf(request, "%s %s %s", method, path, version);

    if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0) {
        printf("Unsupported method\n");
        return;
    }

    // Intentional array bounds violation
    int i = strlen(path);
    while (i >= 0) {  // This loop is intended to demonstrate an off-by-one error
        path[i] = 'X';  // Violates bounds by accessing one past the end of the array
        i--;
    }

    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Version: %s\n", version);
}

int main() {
    char request[MAX_REQUEST_SIZE];
    fgets(request, sizeof(request), stdin);

    parse_request(request);

    return 0;
}
