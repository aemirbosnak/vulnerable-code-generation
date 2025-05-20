#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_http_request(char *request) {
    char method[8], url[256], version[16];
    char *ptr;
    sscanf(request, "%s %s %s", method, url, version);

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);

    ptr = strstr(url, "host=");
    if (ptr) {
        memcpy(ptr + 5, request + strlen(method) + strlen(" ") + strlen(version) + 1, strlen(ptr) - (ptr - request));
        printf("Modified URL: %s\n", url);
    }
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);
    parse_http_request(buffer);
    return 0;
}
