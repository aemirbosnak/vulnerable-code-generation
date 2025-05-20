//FormAI DATASET v1.0 Category: Data recovery tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// function to recover data from a damaged file
void recover_data() {
    FILE *fp;
    char filename[20];
    char *data;
    int size;

    // get input file from user
    printf("Enter the name of the damaged file: ");
    scanf("%s", filename);

    // open the damaged file in binary mode
    fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("\nError: File not found.\n");
        return;
    }

    // get the size of the damaged file
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    // allocate memory for the data
    data = (char*) malloc(sizeof(char) * size);
    if(data == NULL) {
        printf("\nError: Memory allocation failed.\n");
        return;
    }

    // read the data from the damaged file
    fread(data, sizeof(char), size, fp);
    fclose(fp);

    // repair the data
    for(int i = 0; i < size; i++) {
        if(data[i] == '\0') {
            data[i] = 'X';
        }
    }

    // get output file name from user
    char output_file[20];
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // create new file and write repaired data to it
    fp = fopen(output_file, "wb");
    if(fp == NULL) {
        printf("\nError: File creation failed.\n");
        return;
    }
    fwrite(data, sizeof(char), size, fp);
    fclose(fp);

    printf("\nData has been successfully recovered from the damaged file.\n");
}

int main() {
    printf("Welcome to the Data Recovery Tool!\n");
    printf("==================================\n");
    recover_data();
    return 0;
}