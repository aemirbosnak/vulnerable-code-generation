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

    int content_length = 0;
    char *content_length_str = strstr(request, "Content-Length: ");
    if (content_length_str != NULL) {
        sscanf(content_length_str + 16, "%d", &content_length);
    }

    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Version: %s\n", version);
    printf("Content-Length: %d\n", content_length);
}

int main() {
    char request[MAX_LINE_LENGTH] = "GET / HTTP/1.1\r\nHost: example.com\r\nContent-Length: ";
    int large_number = 9007199254740992; // Large number to cause overflow
    sprintf(request + strlen(request), "%d\r\n\r\n", large_number);

    parse_request(request);

    return 0;
}
