//Falcon-180B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 100

typedef struct {
    char line[MAX_LINE_LENGTH];
    int length;
} Line;

Line lines[MAX_LINES];
int num_lines = 0;

void read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines >= MAX_LINES) {
            printf("Error: too many lines in file\n");
            exit(1);
        }
        lines[num_lines].length = strlen(line);
        strcpy(lines[num_lines].line, line);
        num_lines++;
    }

    fclose(file);
}

void write_file(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not create file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s\n", lines[i].line);
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    printf("Enter the name of the input file: ");
    scanf("%s", lines[0].line);
    read_file(lines[0].line);

    printf("Enter the name of the output file: ");
    scanf("%s", lines[1].line);
    write_file(lines[1].line);

    return 0;
}