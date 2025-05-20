//FormAI DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the unique C Data recovery tool!\n");
    printf("Please enter the name of the file you wish to recover.\n");

    char fname[100];
    scanf("%s", fname);

    FILE* fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s.\n", fname);
        return 1;
    }

    printf("Scanning file for recoverable data...\n");

    fseek(fp, 0, SEEK_END);
    long int filesize = ftell(fp);
    rewind(fp);

    char* data = (char*) malloc(filesize * sizeof(char));
    if (data == NULL) {
        printf("Error: Insufficient memory to recover data from file %s.\n", fname);
        fclose(fp);
        return 1;
    }

    size_t result = fread(data, 1, filesize, fp);
    if (result != filesize) {
        printf("Error: Unable to read data from file %s.\n", fname);
        fclose(fp);
        free(data);
        return 1;
    }

    printf("Data recovery successful! Please enter the name of the file to save the recovered data.\n");

    char output_fname[100];
    scanf("%s", output_fname);

    FILE* output_fp = fopen(output_fname, "w");
    if (output_fp == NULL) {
        printf("Error: Unable to create file %s.\n", output_fname);
        fclose(fp);
        free(data);
        return 1;
    }

    result = fwrite(data, 1, filesize, output_fp);
    if (result != filesize) {
        printf("Error: Unable to write recovered data to file %s.\n", output_fname);
    } else {
        printf("Data recovery successfully saved to file %s!\n", output_fname);
    }

    fclose(fp);
    fclose(output_fp);
    free(data);

    return 0;
}