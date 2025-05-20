#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char response[100];
    int port;

    printf("Enter FTP server's passive mode response: ");
    fgets(response, sizeof(response), stdin);

    if (sscanf(response, "227 Entering Passive Mode (%*[^,],%d,%d)", &port) != 2) {
        fprintf(stderr, "Failed to parse response\n");
        return 1;
    }

    printf("Parsed port: %d\n", port);
    return 0;
}
