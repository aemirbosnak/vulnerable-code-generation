#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_http_request(char *request) {
    char *method, *url, *version;
    char buffer[BUFFER_SIZE];

    sscanf(request, "%s %s %s", method, url, version);

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);

    /* Additional headers */
    gets(buffer);
    printf("Headers:\n%s\n", buffer);

    char body[BUFFER_SIZE];
    fgets(body, BUFFER_SIZE, stdin);
    printf("Body: %s", body);
}

int main() {
    char request[BUFFER_SIZE];
    printf("Enter an HTTP request:\n");
    fgets(request, BUFFER_SIZE, stdin);

    parse_http_request(request);

    return 0;
}
