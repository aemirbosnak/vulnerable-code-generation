#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_LINE 8192

void parse_request(char *buf) {
    char method[10];
    char url[2048];
    char version[20];
    char header[4096];
    char body[8192];

    sscanf(buf, "%s %s %s\n", method, url, version);

    // Overflow on fscanf for headers
    fscanf(stdin, "%s ", header);
    strcat(header, buf);

    sscanf(header, "%s", body);

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);
    printf("Body: %s\n", body);
}

int main(int argc, char *argv[]) {
    char buffer[MAX_LINE];

    while (fgets(buffer, MAX_LINE, stdin)) {
        parse_request(buffer);
    }

    return 0;
}
