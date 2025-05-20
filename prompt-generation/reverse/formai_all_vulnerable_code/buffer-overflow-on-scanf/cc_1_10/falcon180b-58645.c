//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024 * 1024 * 100 // 100 MB

typedef struct {
    char *data;
    size_t size;
} FileData;

int read_file(const char *filename, FileData *data) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    data->size = ftell(file);
    fseek(file, 0, SEEK_SET);

    data->data = malloc(data->size);
    if (!data->data) {
        printf("Error allocating memory for file data\n");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(data->data, 1, data->size, file);
    if (bytes_read!= data->size) {
        printf("Error reading file data\n");
        free(data->data);
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}

int write_file(const char *filename, const FileData *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file %s for writing\n", filename);
        return 1;
    }

    size_t bytes_written = fwrite(data->data, 1, data->size, file);
    if (bytes_written!= data->size) {
        printf("Error writing file data\n");
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}

int main() {
    char input_filename[256];
    char output_filename[256];

    printf("Enter input file name: ");
    scanf("%s", input_filename);

    FileData input_data;
    if (read_file(input_filename, &input_data)) {
        return 1;
    }

    if (input_data.size > MAX_FILE_SIZE) {
        printf("Input file is too large (%zu bytes)\n", input_data.size);
        free(input_data.data);
        return 1;
    }

    char *recovered_data = malloc(input_data.size);
    if (!recovered_data) {
        printf("Error allocating memory for recovered data\n");
        free(input_data.data);
        return 1;
    }

    memcpy(recovered_data, input_data.data, input_data.size);
    free(input_data.data);

    printf("Enter output file name: ");
    scanf("%s", output_filename);

    if (write_file(output_filename, &(FileData){.data = recovered_data,.size = input_data.size})) {
        printf("Error writing output file\n");
        free(recovered_data);
        return 1;
    }

    printf("Data recovery successful\n");
    free(recovered_data);
    return 0;
}