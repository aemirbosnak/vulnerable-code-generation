#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Subnet Mask>\n", argv[0]);
        return 1;
    }

    unsigned int ip[4], subnet[4];
    sscanf(argv[1], "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(argv[2], "%u.%u.%u.%u", &subnet[0], &subnet[1], &subnet[2], &subnet[3]);

    unsigned int broadcast[4];
    for (int i = 0; i < 4; i++) {
        broadcast[i] = ip[i] | (~subnet[i]);
    }

    printf("Broadcast Address: ");
    for (int i = 0; i < 4; i++) {
        printf("%d", broadcast[i]);
        if (i < 3) printf(".");
    }
    printf("\n");

    return 0;
}
