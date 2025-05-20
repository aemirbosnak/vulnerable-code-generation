//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *data;
    unsigned int size;
} file_t;

int main()
{
    FILE *fp;
    char *buffer;
    unsigned int size;
    file_t *files;
    unsigned int num_files;

    // Open the data file
    fp = fopen("data.dat", "rb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Get the size of the data file
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate a buffer to hold the data
    buffer = malloc(size);
    if (buffer == NULL) {
        perror("malloc");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the data into the buffer
    fread(buffer, 1, size, fp);
    fclose(fp);

    // Parse the data into files
    files = malloc(sizeof(file_t));
    if (files == NULL) {
        perror("malloc");
        free(buffer);
        return EXIT_FAILURE;
    }
    num_files = 0;

    char *p = buffer;
    while (*p != '\0') {
        // Get the name of the file
        char *name = p;
        while (*p != '\0' && *p != '\n') {
            p++;
        }
        *p = '\0';
        p++;

        // Get the size of the file
        unsigned int size = 0;
        while (*p != '\0' && *p != '\n') {
            size *= 10;
            size += *p - '0';
            p++;
        }
        *p = '\0';
        p++;

        // Get the data of the file
        char *data = p;
        while (*p != '\0' && *p != '\n') {
            p++;
        }
        *p = '\0';
        p++;

        // Add the file to the list of files
        files = realloc(files, (num_files + 1) * sizeof(file_t));
        if (files == NULL) {
            perror("realloc");
            free(buffer);
            free(files);
            return EXIT_FAILURE;
        }
        files[num_files].name = name;
        files[num_files].size = size;
        files[num_files].data = data;
        num_files++;
    }

    // Print the list of files
    for (unsigned int i = 0; i < num_files; i++) {
        printf("%s (%u bytes)\n", files[i].name, files[i].size);
    }

    // Free the resources
    free(buffer);
    free(files);

    return EXIT_SUCCESS;
}