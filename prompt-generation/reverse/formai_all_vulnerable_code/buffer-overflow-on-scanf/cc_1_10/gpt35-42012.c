//FormAI DATASET v1.0 Category: HTML beautifier ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4

int count_spaces(char *line) {
    int count = 0;
    for(int i = 0; i < strlen(line); i++) {
        if(line[i] == ' ') {
            count++;
        }
        else if(line[i] == '\t') {
            count += TAB_SIZE;
        }
        else {
            break;
        }
    }
    return count;
}

void beautify(char *filename) {
    // Open the file
    FILE *fp;
    fp = fopen(filename, "r+");
    if(fp == NULL) {
        printf("Cannot open the file.\n");
        exit(1);
    }

    int current_indent = 0;
    char line[256];
    char updated_line[256];
    while(fgets(line, sizeof(line), fp)) {
        int line_indent = count_spaces(line);
        if(line_indent < current_indent) {
            current_indent = line_indent;
        }
        strcpy(updated_line, "");
        for(int i = 0; i < current_indent; i++) {
            strncat(updated_line, " ", sizeof(updated_line) - strlen(updated_line) - 1);
        }
        strncat(updated_line, line + line_indent, sizeof(updated_line) - strlen(updated_line) - 1);
        printf("%s", updated_line);
    }

    fclose(fp);
}

int main() {
    char filename[256];
    printf("Enter the filename: ");
    scanf("%s", filename);

    beautify(filename);

    return 0;
}