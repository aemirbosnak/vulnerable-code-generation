#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char response[10];
    printf("Enter PASV response: ");
    scanf("%s", response);
    int port;
    sscanf(response, "227 Entering Passive Mode (%*[^,],%d,%d)", &port);
    printf("Port: %d\n", port);
    return 0;
}
