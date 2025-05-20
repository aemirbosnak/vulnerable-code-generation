#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <subnet_mask>\n", argv[0]);
        return 1;
    }

    unsigned int ip[4], subnet[4];
    if (sscanf(argv[1], "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]) != 4 ||
        sscanf(argv[2], "%u.%u.%u.%u", &subnet[0], &subnet[1], &subnet[2], &subnet[3]) != 4) {
        fprintf(stderr, "Invalid IP or subnet mask format.\n");
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        if (ip[i] > 255 || subnet[i] > 255) {
            fprintf(stderr, "IP or subnet mask out of range.\n");
            return 1;
        }
    }

    unsigned int broadcast[4];
    for (int i = 0; i < 4; i++) {
        broadcast[i] = (ip[i] & subnet[i]) | (~subnet[i]);
    }

    printf("Broadcast Address: %u.%u.%u.%u\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

    return 0;
}
