#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char response[] = "227 Entering Passive Mode (192,168,1,1,123,45).";
    int ip[4], port_high, port_low;
    sscanf(response, "(%d,%d,%d,%d,%d,%d)", &ip[0], &ip[1], &ip[2], &ip[3], &port_high, &port_low);
    int data_port = (port_high * 256) + port_low;
    printf("Data port: %d\n", data_port);
    return 0;
}
