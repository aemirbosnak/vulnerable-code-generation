//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

// Function to compare two files and return true if they are identical
bool compare_files(FILE* file1, FILE* file2) {
    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    bool identical = true;

    while (fgets(buffer1, BUFFER_SIZE, file1)!= NULL &&
           fgets(buffer2, BUFFER_SIZE, file2)!= NULL) {
        if (strcmp(buffer1, buffer2)!= 0) {
            identical = false;
            break;
        }
    }

    return identical;
}

// Function to synchronize two files
void synchronize_files(const char* source_file, const char* destination_file) {
    FILE* source = fopen(source_file, "r");
    FILE* destination = fopen(destination_file, "w");

    if (source == NULL || destination == NULL) {
        printf("Error: could not open one of the files.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    bool identical = true;

    while (fgets(buffer, BUFFER_SIZE, source)!= NULL) {
        fputs(buffer, destination);

        if (identical) {
            identical = compare_files(source, destination);
        }
    }

    fclose(source);
    fclose(destination);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s source_file destination_file [sync]\n", argv[0]);
        return 1;
    }

    const char* source_file = argv[1];
    const char* destination_file = argv[2];
    bool sync = false;

    if (strcmp(argv[3], "sync") == 0) {
        sync = true;
    }

    FILE* source = fopen(source_file, "r");
    FILE* destination = fopen(destination_file, "r");

    if (source == NULL || destination == NULL) {
        printf("Error: could not open one of the files.\n");
        exit(1);
    }

    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    bool identical = true;

    while (fgets(buffer1, BUFFER_SIZE, source)!= NULL &&
           fgets(buffer2, BUFFER_SIZE, destination)!= NULL) {
        if (strcmp(buffer1, buffer2)!= 0) {
            identical = false;
            break;
        }
    }

    if (identical) {
        printf("The files are already synchronized.\n");
    } else {
        if (sync) {
            rewind(source);
            rewind(destination);
            synchronize_files(source_file, destination_file);
            printf("The files have been synchronized.\n");
        } else {
            printf("The files are not synchronized.\n");
        }
    }

    fclose(source);
    fclose(destination);

    return 0;
}