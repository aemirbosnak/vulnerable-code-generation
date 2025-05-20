#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_request(char *buffer) {
    char method[8], url[256], version[16];
    char *params, *value;

    sscanf(buffer, "%s %s %s", method, url, version);

    params = strchr(url, '?');
    if (params) *params++ = '\0';

    if (params) {
        int len = strlen(params);
        for (int i = 0; i < len; ++i) {
            if (params[i] == '&') {
                params[i] = '\0';
                value = &params[i + 1];
                while (*value && *value != '=') ++value;
                *value = '\0';
                printf("Param: %s, Value: %s\n", params, value);
                params = &params[i + strlen(value) + 1];
            }
        }
    }
}

int main(int argc, char **argv) {
    char buffer[BUFFER_SIZE];
    printf("Enter HTTP request:\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    parse_request(buffer);
    return 0;
}
