#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void parse_response(char *response) {
    char ip[16];
    int port;
    if (sscanf(response, "IP: %15s Port: %d", ip, &port) == 2) {
        printf("IP: %s\nPort: %d\n", ip, port);
    }
}

int main() {
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    parse_response(buffer);
    return 0;
}
