//FormAI DATASET v1.0 Category: Data recovery tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C Data Recovery Tool\n");

    // Prompt user for file name
    char file_name[100];
    printf("Enter file name: ");
    scanf("%s", file_name);

    // Open file
    FILE *fp;
    fp = fopen(file_name, "r");

    // Check if file exists and can be opened
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", file_name);
        exit(1);
    }

    // Determine file size
    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);
    rewind(fp);

    // Allocate memory for file contents
    char *file_contents = (char *)malloc(file_size + 1);

    // Read file contents into memory
    fread(file_contents, file_size, 1, fp);

    // Close file
    fclose(fp);

    // Create recovered file
    char recovered_file_name[100];
    sprintf(recovered_file_name, "recovered_%s", file_name);
    FILE *recovered_file;
    recovered_file = fopen(recovered_file_name, "w");

    // Write file contents to recovered file
    fwrite(file_contents, file_size, 1, recovered_file);

    // Close recovered file
    fclose(recovered_file);

    printf("Data recovery successful! Recovered file saved as %s\n", recovered_file_name);

    // Free memory
    free(file_contents);

    return 0;
}