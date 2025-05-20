//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *filename;
    int length;
    char *data;
} File;

int main() {
    char *filename = "example.txt";
    int length = 0;
    char *data = NULL;

    // Read in the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    data = malloc(length + 1);
    fread(data, 1, length, fp);
    fclose(fp);

    // Create a File struct
    File file;
    file.filename = filename;
    file.length = length;
    file.data = data;

    // Save the File struct to a binary file
    FILE *fout = fopen("file.bin", "wb");
    if (fout == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }
    fwrite(&file, sizeof(file), 1, fout);
    fclose(fout);

    // Read in the binary file
    File file2;
    FILE *fin = fopen("file.bin", "rb");
    if (fin == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    fread(&file2, sizeof(file2), 1, fin);
    fclose(fin);

    // Print out the file data
    printf("Filename: %s\n", file2.filename);
    printf("Length: %d\n", file2.length);
    printf("Data:\n%s\n", file2.data);

    // Free memory
    free(data);
    free(file2.filename);
    free(file2.data);

    return 0;
}