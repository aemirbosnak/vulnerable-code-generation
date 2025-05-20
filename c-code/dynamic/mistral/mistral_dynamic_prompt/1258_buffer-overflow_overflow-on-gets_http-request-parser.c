#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void parse_request(char* buffer) {
    char method[MAX_BUFFER_SIZE], url[MAX_BUFFER_SIZE], version[MAX_BUFFER_SIZE];

    sscanf(buffer, "%s %s %s", method, url, version);

    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("Version: %s\n", version);

    gets(buffer); // vulnerable code
}

int main(int argc, char* argv[]) {
    char input[MAX_BUFFER_SIZE];

    printf("HTTP Request Parser\n");
    printf("Enter HTTP request: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    parse_request(input);

    return 0;
}
