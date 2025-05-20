//Falcon-180B DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 10000

struct Line {
    char text[MAX_LINE_LENGTH];
    int length;
};

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    struct Line lines[MAX_NUM_LINES];
    int num_lines = 0;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(lines[num_lines].text, MAX_LINE_LENGTH, file)!= NULL) {
        lines[num_lines].length = strlen(lines[num_lines].text);
        num_lines++;
    }

    fclose(file);

    printf("Enter the name of the file to write: ");
    scanf("%s", filename);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s", lines[i].text);
    }

    fclose(file);

    return 0;
}