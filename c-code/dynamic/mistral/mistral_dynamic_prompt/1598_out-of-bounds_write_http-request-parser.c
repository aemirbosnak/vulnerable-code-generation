#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_http_request(char *request) {
    char *method, *url, *version;
    int len = strlen(request);

    method = malloc(len * sizeof(char));
    strncpy(method, request, len);
    method[len] = '\0';

    if (strncmp(method, "GET /", 5) == 0) {
        url = &method[4];
        len = strlen(url);

        if (url[len - 2] == ' ') {
            url[len - 2] = '\0';
            version = &url[len - 1];
        } else {
            version = "";
        }

        printf("Method: %s\n", method);
        printf("URL: %s\n", url);
        printf("HTTP Version: %s\n", version);

        // Potential out-of-bounds write vulnerability
        char *payload = malloc(strlen(url) + 100);
        strcpy(payload, "Payload: ");
        strcat(payload, url);
        strcat(payload, "\n");
        printf("%s", payload);
    }

    free(method);
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <HTTP request>\n", argv[0]);
        return 1;
    }

    strcpy(buffer, argv[1]);
    parse_http_request(buffer);

    return 0;
}
