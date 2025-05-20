#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_http_request(char *buffer) {
    char method[8], url[256], version[16];
    int status_code;
    char *headers, *content;
    size_t len;

    fscanf(stdin, "%s %s %s\n", method, url, version);
    fscanf(stdin, "HTTP/1.1 %d\n", &status_code);
    fgets(headers, BUFFER_SIZE, stdin);
    fgets(content, BUFFER_SIZE, stdin);

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);
    printf("Status Code: %d\n", status_code);
    printf("Headers:\n%s", headers);
    printf("Content:\n%s", content);
}

int main() {
    char input[BUFFER_SIZE];
    printf("Enter an HTTP request:\n");
    fgets(input, BUFFER_SIZE, stdin);

    parse_http_request(input);

    return 0;
}
