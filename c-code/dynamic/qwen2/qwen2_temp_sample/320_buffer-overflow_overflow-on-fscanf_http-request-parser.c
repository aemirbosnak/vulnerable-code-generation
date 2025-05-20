#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void parse_request(char *request) {
    char method[16], uri[256];
    int port;

    // Vulnerable fscanf calls that could lead to buffer overflows
    fscanf(request, "%s %[^ ]* ", method, uri);
    fscanf(request, "Host: [%*[^:]:%d] ", &port);

    printf("Method: %s\n", method);
    printf("URI: %s\n", uri);
    printf("Port: %d\n", port);
}

int main() {
    char input[1024];

    printf("Enter an HTTP request:\n");
    fgets(input, sizeof(input), stdin);
    
    parse_request(input);

    return 0;
}
