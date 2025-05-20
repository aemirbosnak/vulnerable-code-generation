//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
// define the maximum number of files that can be scanned at once

int main(int argc, char *argv[]) {

    // check that the program is being run with the correct number of arguments
    if (argc < 2) {
        printf("Usage: %s [file1] [file2] ... [fileN]\n", argv[0]);
        exit(1);
    }

    // declare variables
    char *virus_signature = "VIRUS"; // this is our virus signature
    char *filename; // this will hold the name of the current file being scanned
    char *file_contents; // this will hold the contents of the current file being scanned
    FILE *file; // this will hold the file pointer for the current file being scanned
    size_t file_size; // this will hold the size of the current file being scanned
    int i, j, is_virus; // declare some integers we will use later

    // loop through all the files passed as arguments
    for (i = 1; i < argc; i++) {

        // first, attempt to open the file
        filename = argv[i];
        file = fopen(filename, "rb");

        // if the file doesn't exist or can't be opened, print an error message and move on to the next file
        if (file == NULL) {
            printf("Error: could not open file %s\n", filename);
            continue;
        }

        // if the file is larger than MAX_FILES bytes, skip it
        fseek(file, 0L, SEEK_END);
        file_size = ftell(file);
        if (file_size > MAX_FILES) {
            printf("Skipping file %s: file is too large\n", filename);
            fclose(file);
            continue;
        }
        rewind(file);

        // allocate memory to hold the file contents
        file_contents = (char*) malloc(file_size + 1);
        if (file_contents == NULL) {
            printf("Error: out of memory\n");
            exit(1);
        }

        // read the file contents into the buffer
        fread(file_contents, 1, file_size, file);
        file_contents[file_size] = '\0'; // add null terminator to the end of the file contents

        // close the file
        fclose(file);

        // now we will scan the file for the virus signature
        is_virus = 0; // initialize variable to false
        for (j = 0; j < file_size - 4; j++) {
            if (file_contents[j] == virus_signature[0] &&
                file_contents[j+1] == virus_signature[1] &&
                file_contents[j+2] == virus_signature[2] &&
                file_contents[j+3] == virus_signature[3])
            {
                is_virus = 1;
                break;
            }
        }

        // free the memory that was allocated for the file contents
        free(file_contents);

        // print the scan results for this file
        if (is_virus) {
            printf("Virus detected in file %s\n", filename);
        } else {
            printf("No virus detected in file %s\n", filename);
        }
    }

    return 0;
}