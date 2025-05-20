//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 1024) // 1 GB

typedef struct file_header {
    char magic[4];
    int file_size;
} FileHeader;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        return 1;
    }

    FileHeader header;
    fread(&header, sizeof(header), 1, input_file);

    if (strncmp(header.magic, "DATA", 4)!= 0) {
        printf("Invalid file format\n");
        return 1;
    }

    char *data = malloc(header.file_size);
    if (data == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    fread(data, header.file_size, 1, input_file);

    int num_records = 0;
    int record_size = 0;

    for (int i = 0; i < header.file_size; i++) {
        if (data[i] == '\n') {
            num_records++;
        }
        if (i == header.file_size - 1 || data[i] == '\n') {
            record_size = i + 1;
        }
    }

    if (num_records == 0) {
        printf("File is empty\n");
        return 1;
    }

    int max_record_size = record_size;
    if (max_record_size > MAX_FILE_SIZE) {
        printf("File is too large\n");
        return 1;
    }

    char *output_data = malloc(max_record_size);
    if (output_data == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    int output_size = 0;
    for (int i = 0; i < header.file_size; i++) {
        if (data[i] == '\n') {
            int record_length = i - output_size + 1;
            if (record_length > max_record_size) {
                printf("Record is too large\n");
                return 1;
            }
            memcpy(output_data + output_size, data + output_size, record_length);
            output_size += record_length;
        }
    }

    fwrite(&header, sizeof(header), 1, output_file);
    fwrite(output_data, output_size, 1, output_file);

    free(data);
    free(output_data);

    fclose(input_file);
    fclose(output_file);

    printf("Data recovery successful\n");

    return 0;
}