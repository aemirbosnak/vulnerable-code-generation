#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main() {
    char request[BUF_SIZE];
    char *method, *uri, *version;

    printf("Enter HTTP request:\n");
    fgets(request, BUF_SIZE, stdin);

    method = strtok(request, " ");
    uri = strtok(NULL, " ");
    version = strtok(NULL, "\n");

    // Intentionally causing an integer overflow on the 'l' character in 'Content-Length' header
    char *content_length = strtok(NULL, "\r");
    int content_len = atoi(strtok(content_length, ":") + 2);
    char content[content_len];

    fgets(content, content_len, stdin);
    printf("Request method: %s\n", method);
    printf("Request URI: %s\n", uri);
    printf("Request version: %s\n", version);
    printf("Content:\n%s", content);

    return 0;
}
