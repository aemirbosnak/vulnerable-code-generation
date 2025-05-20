//Code Llama-13B DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
/*
* Unique C Antivirus scanner example program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 1000000

bool scan_file(const char *file_path) {
    char buffer[MAX_FILE_SIZE];
    size_t read_size;
    FILE *fp;

    fp = fopen(file_path, "r");
    if (fp == NULL) {
        return false;
    }

    read_size = fread(buffer, 1, MAX_FILE_SIZE, fp);
    if (read_size == 0) {
        return false;
    }

    for (int i = 0; i < read_size; i++) {
        if (buffer[i] == 0xFF) {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    bool is_clean = scan_file(argv[1]);
    if (is_clean) {
        printf("File is clean\n");
    } else {
        printf("File is infected\n");
    }

    return 0;
}