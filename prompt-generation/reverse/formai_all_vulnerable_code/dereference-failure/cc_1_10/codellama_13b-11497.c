//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: scientific
// C HTML Beautifier Program
// Scientific Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

// Structure to store a line of HTML
struct HTMLLine {
    char* line;
    int length;
};

// Function to remove excess whitespace
void removeWhitespace(char* line) {
    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == ' ') {
            int j = i + 1;
            while (line[j] == ' ') {
                j++;
            }
            int k = j;
            while (line[k] != '\0') {
                line[i] = line[k];
                i++;
                k++;
            }
            line[i] = '\0';
        }
        else {
            i++;
        }
    }
}

// Function to convert tabs to spaces
void convertTabs(char* line) {
    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == '\t') {
            int j = i + 1;
            while (line[j] != '\0') {
                line[j] = ' ';
                j++;
            }
        }
        i++;
    }
}

// Function to insert newlines
void insertNewlines(char* line) {
    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == '<') {
            if (line[i + 1] == '/') {
                line[i] = '\n';
                line[i + 1] = ' ';
            }
            else {
                line[i] = '\n';
            }
        }
        i++;
    }
}

// Function to format HTML code
void formatHTML(char* line) {
    removeWhitespace(line);
    convertTabs(line);
    insertNewlines(line);
}

// Main function
int main() {
    // Open file for reading
    FILE* fp = fopen("input.html", "r");

    // Check if file opened successfully
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Create array to store lines
    struct HTMLLine lines[MAX_LINE_LENGTH];

    // Read lines from file
    int i = 0;
    while (fgets(lines[i].line, MAX_LINE_LENGTH, fp) != NULL) {
        lines[i].length = strlen(lines[i].line);
        formatHTML(lines[i].line);
        i++;
    }

    // Close file
    fclose(fp);

    // Open file for writing
    fp = fopen("output.html", "w");

    // Check if file opened successfully
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Write formatted lines to file
    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        if (lines[i].length > 0) {
            fprintf(fp, "%s", lines[i].line);
        }
    }

    // Close file
    fclose(fp);

    return 0;
}