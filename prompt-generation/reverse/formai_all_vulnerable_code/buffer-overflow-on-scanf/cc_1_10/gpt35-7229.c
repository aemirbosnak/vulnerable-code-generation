//FormAI DATASET v1.0 Category: Data recovery tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000 // Maximum size of file

int main()
{
    FILE *file;
    char filename[100];
    char *buffer = malloc(sizeof(char) * SIZE); // Allocate memory for buffer

    printf("Enter the name of the file you want to recover: ");
    scanf("%s", filename);

    file = fopen(filename, "rb"); // Open file in binary mode

    if (file == NULL) {
        printf("Error: Could not open file %s", filename);
        exit(EXIT_FAILURE);
    }

    long int filesize = 0;
    fseek(file, 0L, SEEK_END); // Move file pointer to end of file
    filesize = ftell(file); // Get the current position of file pointer
    rewind(file); // Reset file pointer to the beginning of file

    // Read file content into buffer
    size_t read = fread(buffer, 1, filesize, file);
    if (read != filesize) {
        printf("Error: Could not read file %s", filename);
        fclose(file);
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Close file
    fclose(file);

    // Create new file to store recovered data
    char new_filename[strlen(filename) + 5];
    sprintf(new_filename, "%s.rec", filename); // Add ".rec" to the end of filename
    FILE *new_file = fopen(new_filename, "wb");
    if (new_file == NULL) {
        printf("Error: Could not create file %s", new_filename);
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Write recovered data into new file
    size_t written = fwrite(buffer, 1, filesize, new_file);
    if (written != filesize) {
        printf("Error: Could not write recovered data to file %s.rec", filename);
        fclose(new_file);
        free(buffer);
        remove(new_filename); // Delete incomplete recovered file
        exit(EXIT_FAILURE);
    }

    // Close new file
    fclose(new_file);

    printf("Data successfully recovered to %s\n", new_filename);

    // Free buffer memory
    free(buffer);

    return 0;
}