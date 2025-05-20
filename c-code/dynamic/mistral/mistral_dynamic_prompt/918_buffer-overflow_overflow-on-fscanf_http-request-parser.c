#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256

void parse_http_request(char *buffer) {
    char method[MAX_BUFFER];
    char url[MAX_BUFFER];
    char version[MAX_BUFFER];
    char *token;

    // Buffer overflow vulnerability intentionally introduced
    fscanf(stdin, "%s %s %s\n", method, url, version);
    printf("Request Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("HTTP Version: %s\n", version);

    // Add more functionality here...

    // Potential malicious code execution in real-world scenario
    char attacker_input[MAX_BUFFER];
    sprintf(attacker_input, "%s\0xdeaddbbad\0x00%s", method, url);
    system(attacker_input);
}

int main(int argc, char **argv) {
    char buffer[MAX_BUFFER];

    printf("HTTP Request Parser Tool\n");
    printf("Enter HTTP request:\n");

    fgets(buffer, MAX_BUFFER, stdin);
    parse_http_request(buffer);

    return 0;
}
