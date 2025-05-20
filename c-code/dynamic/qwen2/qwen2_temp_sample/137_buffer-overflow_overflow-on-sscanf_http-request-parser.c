#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void parse_request(char *request) {
    char method[10], path[256], version[10];
    int port;
    char host[256];

    if (sscanf(request, "%9s %255s HTTP/%9s", method, path, version) != 3) {
        return;
    }

    if (strcmp(version, "1.1") != 0 && strcmp(version, "1.0") != 0) {
        return;
    }

    if (sscanf(path, "http://%[^:]:%d/%255s", host, &port, path) == 3) {
        printf("Method: %s\n", method);
        printf("Path: %s\n", path);
        printf("Host: %s\n", host);
        printf("Port: %d\n", port);
    } else {
        if (sscanf(path, "http://%[^/]/%255s", host, path) == 2) {
            printf("Method: %s\n", method);
            printf("Path: %s\n", path);
            printf("Host: %s\n", host);
        }
    }
}

int main() {
    char request[] = "GET /path/to/resource HTTP/1.1\r\nHost: example.com:8080";
    parse_request(request);
    return 0;
}
