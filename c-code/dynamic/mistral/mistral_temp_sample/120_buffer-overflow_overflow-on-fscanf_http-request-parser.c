#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_request(char *buffer) {
    char method[8], url[256], version[16];
    char request[BUFFER_SIZE];

    // HTTP request format: Method SP Request-URI SP HTTP-Version CRLF
    // Method SP Request-URI SP HTTP-Version CRLF [Header] CRLF [Body]

    fscanf(buffer, "%s %s %s\n", method, url, version);
    strcpy(request, buffer + strlen(method) + strlen(url) + strlen(version) + 4); // Move to request body

    // Here you could add logic to parse headers and body, but we will just ignore it
    // and overflow the request buffer instead

    // Overflow the request buffer with a NUL character (0x00)
    char overflow[100] = "";
    strcat(request, overflow);
}

int main() {
    char buffer[BUFFER_SIZE];

    printf("Enter an HTTP request:\n");
    fgets(buffer, BUFFER_SIZE, stdin);

    parse_request(buffer);

    return 0;
}
