//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY_BLOCKS 1000

struct memory_block {
    char *name;
    int size;
    int used;
};

int main() {
    int num_blocks = 0;
    struct memory_block blocks[MAX_MEMORY_BLOCKS];

    while (1) {
        printf("Enter block name (or press Enter to exit): ");
        char name[100];
        scanf("%s", name);

        if (strcmp(name, "") == 0) {
            break;
        }

        if (num_blocks >= MAX_MEMORY_BLOCKS) {
            printf("Error: maximum number of blocks reached\n");
            exit(1);
        }

        blocks[num_blocks].name = strdup(name);
        blocks[num_blocks].size = 0;
        blocks[num_blocks].used = 0;

        num_blocks++;
    }

    while (1) {
        printf("\n");
        for (int i = 0; i < num_blocks; i++) {
            printf("%s: %d bytes used out of %d bytes\n", blocks[i].name, blocks[i].used, blocks[i].size);
        }

        printf("Enter block name to update usage: ");
        char name[100];
        scanf("%s", name);

        int found = 0;
        for (int i = 0; i < num_blocks; i++) {
            if (strcmp(blocks[i].name, name) == 0) {
                printf("Enter new usage (in bytes): ");
                scanf("%d", &blocks[i].used);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Error: block not found\n");
        }
    }

    return 0;
}