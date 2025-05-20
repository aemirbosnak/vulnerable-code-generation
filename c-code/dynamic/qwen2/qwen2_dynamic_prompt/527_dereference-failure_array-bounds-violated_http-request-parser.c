#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void parse_request(char *request) {
    char method[MAX_LINE_LENGTH];
    char path[MAX_LINE_LENGTH];
    char version[MAX_LINE_LENGTH];

    sscanf(request, "%s %s %s", method, path, version);

    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Version: %s\n", version);
}

int main() {
    char buffer[MAX_LINE_LENGTH];
    fgets(buffer, sizeof(buffer), stdin);

    parse_request(buffer);

    return 0;
}
