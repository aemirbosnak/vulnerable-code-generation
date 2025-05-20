//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 100

typedef struct {
    char file_name[FILE_NAME_SIZE];
    int file_size;
} file_t;

int read_block(FILE *fp, void *buffer, int block_num) {
    fseek(fp, block_num * BLOCK_SIZE, SEEK_SET);
    return fread(buffer, BLOCK_SIZE, 1, fp);
}

int write_block(FILE *fp, const void *buffer, int block_num) {
    fseek(fp, block_num * BLOCK_SIZE, SEEK_SET);
    return fwrite(buffer, BLOCK_SIZE, 1, fp);
}

int main() {
    FILE *fp;
    char *filename = "test.bin";
    file_t *file_table;
    int num_files;

    fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    file_table = malloc(BLOCK_SIZE);
    if (!file_table) {
        printf("Error: could not allocate memory for file table\n");
        return 1;
    }

    if (read_block(fp, file_table, 0)!= 1) {
        printf("Error: could not read file table\n");
        return 1;
    }

    num_files = file_table->file_size / sizeof(file_t);

    for (int i = 0; i < num_files; i++) {
        file_t *file = (file_t *) (file_table + i * sizeof(file_t));
        char *file_data;

        file_data = malloc(file->file_size);
        if (!file_data) {
            printf("Error: could not allocate memory for file data\n");
            return 1;
        }

        if (read_block(fp, file_data, file->file_size / BLOCK_SIZE)!= file->file_size / BLOCK_SIZE) {
            printf("Error: could not read file data\n");
            return 1;
        }

        printf("Recovered file: %s\n", file->file_name);
        printf("File size: %d bytes\n", file->file_size);
        printf("File data:\n");
        for (int j = 0; j < file->file_size; j++) {
            printf("%02X ", (unsigned char) file_data[j]);
            if (j % 16 == 15) {
                printf("\n");
            }
        }
        printf("\n");

        free(file_data);
    }

    free(file_table);
    fclose(fp);

    return 0;
}