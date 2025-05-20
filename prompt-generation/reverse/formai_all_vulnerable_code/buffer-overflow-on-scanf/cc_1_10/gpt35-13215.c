//FormAI DATASET v1.0 Category: HTML beautifier ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isChar(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

void printIndent(int indent) {
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
}

int main() {
    char filename[50];
    printf("Enter the name of the file to be beautified: ");
    scanf("%s", filename);

    FILE* fileToBeBeautified = fopen(filename, "r");
    if (fileToBeBeautified == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    FILE* beautifiedFile = fopen("beautified.html", "w");
    if (beautifiedFile == NULL) {
        printf("Could not create beautified file\n");
        fclose(fileToBeBeautified);
        return 1;
    }

    char c = fgetc(fileToBeBeautified);
    int indent = 0;
    bool newLine = true;
    while (c != EOF) {
        if (newLine) {
            if (c == '<') {
                printIndent(indent);
                fputc(c, beautifiedFile);
                c = fgetc(fileToBeBeautified);
                if (c == '/') {
                    indent -= 4;
                } else {
                    indent += 4;
                }
            } else if (isChar(c)) {
                printIndent(indent);
                fputc(c, beautifiedFile);
            } else if (isDigit(c)) {
                printIndent(indent);
                fputc(c, beautifiedFile);
            } else {
                fputc(c, beautifiedFile);
            }
            newLine = false;
        } else {
            fputc(c, beautifiedFile);
            if (c == '\n') {
                newLine = true;
            }
        }
        c = fgetc(fileToBeBeautified);
    }

    fclose(fileToBeBeautified);
    fclose(beautifiedFile);
    printf("Beautified file created as beautified.html\n");

    return 0;
}