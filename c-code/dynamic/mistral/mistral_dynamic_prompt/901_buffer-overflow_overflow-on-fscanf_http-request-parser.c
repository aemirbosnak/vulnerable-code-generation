#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_request(char *buf) {
    char method[8], url[256], version[16];
    int length;

    fscanf(stdin, "%s %s %s\n", method, url, version);

    // Overflow on fscanf for url
    length = strlen(url) + 1;
    strcpy(url + length, buf);
}

int main() {
    char buffer[10];
    char *request = (char *) malloc(8 + 256 + 16 + 10);
    int i;

    for (i = 0; i < 10; i++)
        fscanf(stdin, "%c", &buffer[i]);

    parse_request(buffer);

    free(request);
    return 0;
}
