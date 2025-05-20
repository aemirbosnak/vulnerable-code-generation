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

    int header_count = 0;
    while (fgets(request, MAX_LINE_LENGTH, stdin)) {
        if (strcmp(request, "\r\n") == 0) break;
        header_count++;
    }

    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Version: %s\n", version);
    printf("Header Count: %d\n", header_count);
}

int main() {
    char request[MAX_LINE_LENGTH];
    fgets(request, MAX_LINE_LENGTH, stdin);
    parse_request(request);
    return 0;
}
