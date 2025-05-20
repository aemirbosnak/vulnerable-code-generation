#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_request(char *buffer) {
    char method[8], url[256], version[9];
    int http_version;
    char header_key[128], header_value[256];
    char temp[BUFFER_SIZE];

    strcpy(temp, buffer);
    sscanf(temp, "%s %s %s %n", method, url, version, &http_version);
    strcpy(temp, &temp[http_version]);

    while (sscanf(temp, "%s: %s%n", header_key, header_value, &http_version) == 2) {
        printf("%s: %s\n", header_key, header_value);
        strcpy(temp, &temp[http_version]);
    }
}

int main(int argc, char **argv) {
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <HTTP request>\n", argv[0]);
        return 1;
    }

    strcpy(buffer, argv[1]);
    parse_request(buffer);

    return 0;
}
