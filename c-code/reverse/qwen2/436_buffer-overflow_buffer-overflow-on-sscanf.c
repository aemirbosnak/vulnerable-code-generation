#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char response[10];
    int port;

    // Simulate receiving an FTP PASV response
    strcpy(response, "227 Entering Passive Mode (192,168,1,1,123,45)");

    // Vulnerable sscanf call with insufficient buffer size
    sscanf(response, "%*[^()](%d,%d)", &port);

    printf("Port: %d\n", port);
    return 0;
}
