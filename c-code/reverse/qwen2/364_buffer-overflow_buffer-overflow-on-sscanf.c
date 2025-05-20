#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <subnet_mask>\n", argv[0]);
        return 1;
    }

    unsigned int ip_parts[4], subnet_parts[4];
    sscanf(argv[1], "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
    sscanf(argv[2], "%u.%u.%u.%u", &subnet_parts[0], &subnet_parts[1], &subnet_parts[2], &subnet_parts[3]);

    unsigned int broadcast_parts[4];
    for (int i = 0; i < 4; i++) {
        broadcast_parts[i] = ip_parts[i] | (~subnet_parts[i]);
    }

    printf("Broadcast Address: %u.%u.%u.%u\n", broadcast_parts[0], broadcast_parts[1], broadcast_parts[2], broadcast_parts[3]);

    return 0;
}
