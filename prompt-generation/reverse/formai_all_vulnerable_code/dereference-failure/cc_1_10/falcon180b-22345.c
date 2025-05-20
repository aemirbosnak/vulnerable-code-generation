//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char *file_path;
    FILE *file;
    int line_number;
} File;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    File file1 = { 0 };
    File file2 = { 0 };

    file1.file_path = argv[1];
    file2.file_path = argv[2];

    file1.file = fopen(file1.file_path, "r");
    file2.file = fopen(file2.file_path, "r");

    if (file1.file == NULL || file2.file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];

    int line_count = 0;

    while (fgets(line1, MAX_LINE_LENGTH, file1.file)!= NULL) {
        line_count++;
        file1.line_number = line_count;

        while (fgets(line2, MAX_LINE_LENGTH, file2.file)!= NULL) {
            file2.line_number = line_count;

            int cmp = strcmp(line1, line2);

            if (cmp == 0) {
                printf("Line %d: %s\n", file1.line_number, line1);
            } else if (cmp < 0) {
                printf("Line %d (file1): %s\n", file1.line_number, line1);
            } else {
                printf("Line %d (file2): %s\n", file2.line_number, line2);
            }
        }
    }

    fclose(file1.file);
    fclose(file2.file);

    return 0;
}