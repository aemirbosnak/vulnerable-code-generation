#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char response[] = "227 Entering Passive Mode (192,168,1,1,4,5)";
    int ip[4], port;
    sscanf(response, "%*s %d,%d,%d,%d,%d,%d", &ip[0], &ip[1], &ip[2], &ip[3], &port, &port);
    printf("IP: %d.%d.%d.%d Port: %d\n", ip[0], ip[1], ip[2], ip[3], (port << 8) | port);
    return 0;
}
