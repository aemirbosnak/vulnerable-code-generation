#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
    char method[8];
    char url[256];
    char version[16];
} HttpRequest;

int main(int argc, char *argv[]) {
    HttpRequest req;
    char buffer[BUFFER_SIZE];

    printf("HTTP request parser v1.0\n");

    if (argc != 2) {
        printf("Usage: %s <HTTP request>\n", argv[0]);
        return 1;
    }

    strcpy(buffer, argv[1]);

    sscanf(buffer, "%s %s %s", req.method, req.url, req.version);

    printf("Method: %s\n", req.method);
    printf("URL: %s\n", req.url);
    printf("Version: %s\n", req.version);

    return 0;
}
