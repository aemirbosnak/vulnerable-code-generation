#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

void parse_request(char *request) {
    char method[8];
    char path[MAX_REQUEST_SIZE];
    char version[16];

    sscanf(request, "%7s %*[^ ] %*[^ ]", method);
    if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0) {
        return;
    }

    int i = strlen(method) + 1;
    while (request[i] == ' ') {
        i++;
    }
    int j = i;
    while (request[j] != ' ' && request[j] != '\n' && request[j] != '\r') {
        path[j - i] = request[j];
        j++;
    }
    path[j - i] = '\0';

    if (strlen(path) >= MAX_REQUEST_SIZE) {
        printf("Path too long\n");
        return;
    }

    i = j;
    while (request[i] == ' ') {
        i++;
    }
    j = i;
    while (request[j] != '\n' && request[j] != '\r') {
        version[j - i] = request[j];
        j++;
    }
    version[j - i] = '\0';

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
