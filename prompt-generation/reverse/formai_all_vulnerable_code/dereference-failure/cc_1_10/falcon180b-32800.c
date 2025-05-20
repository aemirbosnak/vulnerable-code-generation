//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE 1000000 // 1MB

typedef struct {
    char filename[16];
    uint8_t data[BLOCK_SIZE];
} file_t;

void write_file(const char* filename, const void* data, uint32_t size) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    fwrite(data, size, 1, file);
    fclose(file);
}

void read_file(const char* filename, void* data, uint32_t size) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    fread(data, size, 1, file);
    fclose(file);
}

int main() {
    printf("Data recovery tool\n");

    uint8_t* buffer = malloc(BLOCK_SIZE);
    if (!buffer) {
        printf("Error: could not allocate buffer\n");
        return 1;
    }

    printf("Enter the name of the file to recover: ");
    scanf("%s", buffer);

    uint32_t file_size = 0;
    uint32_t block_count = 0;

    while (file_size < MAX_FILE_SIZE) {
        char filename[16] = {0};
        sprintf(filename, "%s.%d", buffer, block_count);
        printf("Recovering block %d...\n", block_count);

        file_t file;
        read_file(filename, &file, sizeof(file));

        if (file.filename[0] == 0) {
            printf("End of file reached\n");
            break;
        }

        if (strncmp(file.filename, buffer, 16)!= 0) {
            printf("Error: file names do not match\n");
            exit(1);
        }

        if (file_size + BLOCK_SIZE > MAX_FILE_SIZE) {
            printf("Error: file is too large\n");
            exit(1);
        }

        write_file(buffer, file.data, BLOCK_SIZE);
        file_size += BLOCK_SIZE;
        block_count++;
    }

    printf("Recovery complete\n");
    free(buffer);
    return 0;
}