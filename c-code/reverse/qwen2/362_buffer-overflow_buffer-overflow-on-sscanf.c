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

    unsigned int ip[4], subnet_mask[4];
    sscanf(argv[1], "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(argv[2], "%u.%u.%u.%u", &subnet_mask[0], &subnet_mask[1], &subnet_mask[2], &subnet_mask[3]);

    for (int i = 0; i < 4; i++) {
        ip[i] &= subnet_mask[i];
    }

    printf("Broadcast Address: %u.%u.%u.%u\n", ip[0], ip[1], ip[2], ip[3]);

    return 0;
}
