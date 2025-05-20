//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scan_file(char *filename);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int result = scan_file(argv[1]);

    if (result == 0) {
        printf("The file is safe.\n");
    } else if (result == 1) {
        printf("Warning: file contains a virus.\n");
    } else {
        printf("Error: could not open file.\n");
    }

    return 0;
}

// define the virus signature here
char virus_sig[] = "c0d3m0nkey";

int scan_file(char *filename) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        return -1;
    }

    // get the file size
    fseek(file, 0L, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // allocate memory for file contents
    char *file_contents = (char*) malloc(file_size + 1);

    if (file_contents == NULL) {
        fclose(file);
        return -1;
    }

    // read the file into memory
    fread(file_contents, sizeof(char), file_size, file);
    file_contents[file_size] = '\0';

    // check for virus signature
    if (strstr(file_contents, virus_sig) != NULL) {
        free(file_contents);
        fclose(file);
        return 1;
    }

    free(file_contents);
    fclose(file);

    return 0;
}