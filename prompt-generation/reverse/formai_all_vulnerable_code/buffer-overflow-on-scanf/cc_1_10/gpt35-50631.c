//FormAI DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file_data {
    char type[10];
    char name[50];
    int size;
} file_data;

int main() {
    FILE *input, *output;
    int i, num_files;
    char filename[50];
    file_data *data;

    printf("Enter input file name: ");
    scanf("%s", filename);

    input = fopen(filename, "r");

    if (input == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    fread(&num_files, sizeof(int), 1, input);

    data = (file_data *) malloc(num_files * sizeof(file_data));

    fread(data, sizeof(file_data), num_files, input);

    fclose(input);

    for (i = 0; i < num_files; i++) {
        printf("File %d:\n", i + 1);
        printf("\tType: %s\n", data[i].type);
        printf("\tName: %s\n", data[i].name);
        printf("\tSize: %d bytes\n", data[i].size);
    }

    printf("Enter index of file to recover: ");
    scanf("%d", &i);

    sprintf(filename, "recovered_%s", data[i-1].name);

    output = fopen(filename, "w");

    if (output == NULL) {
        printf("Error: Could not create output file\n");
        exit(1);
    }

    fseek(input, sizeof(int) + (i-1) * sizeof(file_data), SEEK_SET);

    int file_size = data[i-1].size;
    int bytes_read;
    char buffer[512];

    while (file_size > 0 && !feof(input)) {
        bytes_read = fread(buffer, sizeof(char), 512, input);
        fwrite(buffer, sizeof(char), bytes_read, output);
        file_size -= bytes_read;
    }

    fclose(input);
    fclose(output);

    printf("File %d successfully recovered as %s\n", i, filename);

    return 0;
}