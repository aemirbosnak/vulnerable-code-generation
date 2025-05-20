//Falcon-180B DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILE_NAME_LENGTH 20

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    FILE *file;
    int line_num;
} File;

void clear_line(char *line) {
    int i;
    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        line[i] = '\0';
    }
}

void print_line(char *line, int line_num) {
    int i;
    printf("%d: ", line_num);
    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        if (line[i]!= '\0') {
            printf("%c", line[i]);
        }
    }
    printf("\n");
}

int main() {
    int i;
    char filename[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    File file;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file.file = fopen(filename, "r");

    if (file.file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    // Read lines of file
    while (fgets(line, MAX_LINE_LENGTH, file.file)!= NULL) {
        // Process line
        clear_line(line);
        if (line[0] == '#') {
            // Comment line, do not print
        } else if (line[0] == '@') {
            // Label line, print label and line number
            printf("%s ", line);
        } else {
            // Instruction line, print line number and instruction
            print_line(line, i);
            i++;
        }
    }

    // Close file
    fclose(file.file);

    return 0;
}