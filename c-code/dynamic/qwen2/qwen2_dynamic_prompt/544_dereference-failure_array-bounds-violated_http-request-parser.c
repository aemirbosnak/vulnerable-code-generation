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

    // Deliberate array bounds violation vulnerability
    int i = 0;
    while (path[i] != ' ') {
        path[i] += 1; // Increment each character in path
        i++;
    }
    path[i] = '\0';

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
