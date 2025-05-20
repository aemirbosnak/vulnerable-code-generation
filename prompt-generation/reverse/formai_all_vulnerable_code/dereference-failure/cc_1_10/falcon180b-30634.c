//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

// Struct to hold information about each line
typedef struct {
    char *text;
    int length;
} Line;

// Function to read in a line of text from the user
Line readLine() {
    char input[MAX_LINE_LENGTH];
    Line line;
    printf("Enter a line of text (up to %d characters): ", MAX_LINE_LENGTH - 1);
    fgets(input, MAX_LINE_LENGTH, stdin);
    line.text = strdup(input);
    line.length = strlen(line.text);
    return line;
}

// Function to print a line of text
void printLine(Line line) {
    printf("%s\n", line.text);
}

// Function to compare two lines of text
int compareLines(const void *a, const void *b) {
    Line lineA = *(Line *)a;
    Line lineB = *(Line *)b;
    return strcmp(lineA.text, lineB.text);
}

// Main function
int main() {
    // Initialize an array to hold lines of text
    Line lines[MAX_LINES];
    int numLines = 0;

    // Read in lines of text from the user
    while (numLines < MAX_LINES) {
        printf("Enter a line of text or type 'done' to finish:\n");
        char command[MAX_LINE_LENGTH];
        fgets(command, MAX_LINE_LENGTH, stdin);
        if (strcmp(command, "done") == 0) {
            break;
        }
        lines[numLines++] = readLine();
    }

    // Sort the lines of text alphabetically
    qsort(lines, numLines, sizeof(Line), compareLines);

    // Print out the sorted lines of text
    for (int i = 0; i < numLines; i++) {
        printLine(lines[i]);
    }

    return 0;
}