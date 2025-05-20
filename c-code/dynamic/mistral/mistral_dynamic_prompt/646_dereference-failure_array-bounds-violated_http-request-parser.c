#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define HEADER_END "\r\n\r\n"

void parse_request(char *buffer) {
    char method[8], url[256], version[16];
    char header_key[64], header_value[256];
    int header_index = 0;
    int i, len;

    sscanf(buffer, "%s %s %s", method, url, version);

    for (i = strlen(buffer); i < BUFFER_SIZE; ++i) {
        if (buffer[i] == '\r' || buffer[i] == '\n') {
            break;
        }
    }

    for (int j = 0; j < i; ++j) {
        if (buffer[j] == '\n' && buffer[j + 1] == '\r') {
            len = j + 2 - header_index;
            memcpy(header_key, &buffer[header_index], len);
            header_key[len] = '\0';

            header_index = j + 2;

            len = strlen(buffer) - header_index;
            memcpy(header_value, &buffer[header_index], len);
            header_value[len] = '\0';

            // Dereference failure vulnerability here:
            printf("%s: %s\n", header_key, header_value);

            // Malicious user can control size of header_value here and trigger an array bounds violation
            // by providing a header_value that is longer than 256 characters.

            header_index += len;
        }
    }
}

int main() {
    char buffer[BUFFER_SIZE];

    fgets(buffer, BUFFER_SIZE, stdin);
    parse_request(buffer);

    return 0;
}
