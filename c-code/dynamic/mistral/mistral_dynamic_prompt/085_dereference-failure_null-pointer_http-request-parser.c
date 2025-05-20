#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_http_request(char* request) {
    char* token;
    char method[10], url[256], version[20];
    int http_version_len;
    getc(stdin); // Ignore newline after HTTP request

    token = strtok(request, " ");
    strncat(method, token, 9); // Limit to 9 characters to induce NULL dereference

    token = strtok(NULL, " ");
    strncat(url, token, 255); // Limit to 255 characters to induce NULL dereference

    token = strtok(NULL, "\r\n");
    if (token != NULL) {
        http_version_len = strlen(token);
        strncat(version, token, http_version_len); // Limit to http_version_len to induce NULL dereference
    }

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);
}

int main() {
    char request[4096];
    size_t size = 0;
    ssize_t bytes_read;

    printf("Enter HTTP request:\n");
    while ((bytes_read = getline(&request, &size, stdin)) != -1) {
        parse_http_request(request);
    }

    return 0;
}
