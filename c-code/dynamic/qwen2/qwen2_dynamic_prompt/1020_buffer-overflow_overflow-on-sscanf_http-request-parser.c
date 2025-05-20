#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

void parse_request(char *request) {
    char method[16], path[256], version[16];
    if (sscanf(request, "%s %s %s", method, path, version) != 3) {
        printf("Invalid request format\n");
        return;
    }
    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Version: %s\n", version);
}

int main() {
    char request[MAX_REQUEST_SIZE];
    printf("Enter an HTTP request:\n");
    fgets(request, sizeof(request), stdin);
    parse_request(request);
    return 0;
}
