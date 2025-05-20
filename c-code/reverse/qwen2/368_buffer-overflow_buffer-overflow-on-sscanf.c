#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) return 1;

    unsigned int ip[4], mask[4];
    sscanf(argv[1], "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(argv[2], "%u.%u.%u.%u", &mask[0], &mask[1], &mask[2], &mask[3]);

    unsigned int broadcast[4];
    for (int i = 0; i < 4; i++) {
        broadcast[i] = ip[i] | (~mask[i]);
    }

    printf("%d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

    return 0;
}
