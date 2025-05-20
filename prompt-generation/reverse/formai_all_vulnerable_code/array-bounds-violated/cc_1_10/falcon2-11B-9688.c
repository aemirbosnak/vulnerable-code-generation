//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 100
#define MAX_FILE_NAME 100

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s file1 file2 [file3...]\n", argv[0]);
        exit(1);
    }

    int num_files = argc - 3;
    char* files[num_files];

    for (int i = 1; i < argc; i++) {
        files[i - 1] = argv[i];
    }

    int num_lines = 0;
    char line[MAX_LINE_LENGTH];

    FILE* fp1 = fopen(files[0], "r");
    if (fp1 == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n", files[0], strerror(errno));
        exit(1);
    }

    FILE* fp2 = fopen(files[1], "r");
    if (fp2 == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n", files[1], strerror(errno));
        exit(1);
    }

    while (fgets(line, sizeof(line), fp1)!= NULL) {
        if (fgets(line, sizeof(line), fp2) == NULL) {
            fprintf(stdout, "Line %d is unique to file '%s'\n", num_lines + 1, files[0]);
        } else if (strcmp(line, line)!= 0) {
            fprintf(stdout, "Line %d is different between file '%s' and file '%s'\n", num_lines + 1, files[0], files[1]);
        } else {
            num_lines++;
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}