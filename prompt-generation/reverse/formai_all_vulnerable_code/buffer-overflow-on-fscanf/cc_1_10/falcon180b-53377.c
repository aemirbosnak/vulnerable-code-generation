//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

// Struct to store a line of text
typedef struct {
    char text[MAX_LINE_LENGTH];
    int length;
} Line;

// Struct to store the eBook
typedef struct {
    Line lines[MAX_NUM_LINES];
    int numLines;
} eBook;

// Function to read in the eBook file
eBook readEbook(const char* filename) {
    eBook ebook = {0};
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open eBook file.\n");
        exit(1);
    }

    // Read in the number of lines
    fscanf(fp, "%d\n", &ebook.numLines);

    // Read in each line of text
    for (int i = 0; i < ebook.numLines; i++) {
        Line line = {0};
        fgets(line.text, MAX_LINE_LENGTH, fp);
        line.length = strlen(line.text);
        ebook.lines[i] = line;
    }

    fclose(fp);
    return ebook;
}

// Function to display the eBook
void displayEbook(eBook ebook) {
    for (int i = 0; i < ebook.numLines; i++) {
        printf("%s\n", ebook.lines[i].text);
    }
}

// Function to search for a word in the eBook
int searchEbook(eBook ebook, const char* word) {
    int count = 0;
    for (int i = 0; i < ebook.numLines; i++) {
        char* lineText = ebook.lines[i].text;
        int lineLength = ebook.lines[i].length;
        char* wordStart = strstr(lineText, word);

        while (wordStart!= NULL) {
            count++;
            wordStart = strstr(wordStart + 1, word);
        }
    }
    return count;
}

int main() {
    eBook ebook = readEbook("example.ebook");
    displayEbook(ebook);
    int count = searchEbook(ebook, "the");
    printf("Number of occurrences of 'the': %d\n", count);
    return 0;
}