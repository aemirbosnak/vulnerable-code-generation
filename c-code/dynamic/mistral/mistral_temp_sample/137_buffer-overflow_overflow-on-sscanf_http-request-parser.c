#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024
#define BUFFER_SIZE 256

typedef struct {
    char method[8];
    char url[256];
    char version[10];
} HttpRequest;

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    HttpRequest request;

    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    sscanf(buffer, "%s %s %s", request.method, request.url, request.version);

    printf("Method: %s\n", request.method);
    printf("URL: %s\n", request.url);
    printf("Version: %s\n", request.version);

    // Buffer overflow vulnerability here
    char *payload = "A" ;
    strcat(request.method, payload);

    return 0;
}
