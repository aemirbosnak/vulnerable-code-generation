//FormAI DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indent_level = 0;

void printTabs(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
}

int isOpeningTag(char* line) {
    return line[0] == '<' && line[1] != '/';
}

int isClosingTag(char* line) {
    return line[0] == '<' && line[1] == '/';
}

void beautify(char* filename) {
    FILE *fp;
    char line[1000];

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file");
        exit(1);
    }

    while (fgets(line, 1000, fp)) {
        if (isOpeningTag(line)) {
            printTabs(indent_level);
            printf("%s", line);
            indent_level++;
        }
        else if (isClosingTag(line)) {
            indent_level--;
            printTabs(indent_level);
            printf("%s", line);
        }
        else {
            printTabs(indent_level);
            printf("%s", line);
        }
    }

    fclose(fp);
}

int main() {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("\n");

    beautify(filename);

    return 0;
}