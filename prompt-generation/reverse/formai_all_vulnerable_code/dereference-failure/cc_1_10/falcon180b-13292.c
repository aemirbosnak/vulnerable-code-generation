//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define MAX_FILE_SIZE (10 * 1024 * 1024)

struct block {
    int is_allocated;
    int block_number;
    char data[BLOCK_SIZE];
};

int main(int argc, char *argv[]) {
    FILE *file;
    struct block *disk;
    int disk_size;
    int i, j, k;
    char filename[100];

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    strcat(filename, ".dat");

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: input file not found.\n");
        return 1;
    }

    disk = (struct block *)malloc(MAX_FILE_SIZE / BLOCK_SIZE * sizeof(struct block));
    if (disk == NULL) {
        printf("Error: not enough memory.\n");
        return 1;
    }

    disk_size = 0;

    while (!feof(file)) {
        fread(&disk[disk_size], sizeof(struct block), 1, file);
        disk_size++;
    }

    fclose(file);

    for (i = 0; i < disk_size; i++) {
        if (disk[i].is_allocated == 1) {
            printf("File name: ");
            for (j = 0; j < strlen(disk[i].data); j++) {
                printf("%c", disk[i].data[j]);
            }
            printf("\n");
        }
    }

    return 0;
}