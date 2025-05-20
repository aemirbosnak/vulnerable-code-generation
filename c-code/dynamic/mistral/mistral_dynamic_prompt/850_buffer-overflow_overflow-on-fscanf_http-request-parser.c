#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void analyze_http_request(char *buffer) {
    char method[10];
    char url[256];
    char version[20];
    char header[1024];
    char *ptr;

    fscanf(stdin, "%s %s %s\n", method, url, version);

    strcpy(header, "\n");

    while (fscanf(stdin, "%s: %255s\n", ptr, buffer) == 2) {
        strcat(header, ptr);
        strcat(header, ": ");
        strcat(header, buffer);
        strcat(header, "\n");
    }

    // Buffer overflow vulnerability intentionally created here
    printf("Request Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("HTTP Version: %s\n", version);
    printf("Headers:\n%s", header);
}

int main() {
    char buffer[10];
    char request[4096];

    printf("Parse HTTP Request:\n");
    fgets(request, sizeof(request), stdin);

    analyze_http_request(request);

    return 0;
}
