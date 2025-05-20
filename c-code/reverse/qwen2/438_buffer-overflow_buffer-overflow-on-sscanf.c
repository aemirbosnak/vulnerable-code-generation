#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parsePASVResponse(char *response) {
    int port;
    sscanf(response, "227 Entering Passive Mode (%*[^,],%d,%d)", &port);
}

int main() {
    char response[100];
    printf("Enter PASV response: ");
    fgets(response, sizeof(response), stdin);
    parsePASVResponse(response);
    return 0;
}
