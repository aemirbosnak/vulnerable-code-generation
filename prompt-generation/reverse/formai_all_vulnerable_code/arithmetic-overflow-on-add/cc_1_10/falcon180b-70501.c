//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define MAX_WORD_LEN 100

// Function to read a file and store its contents in a buffer
char* readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    rewind(file);

    char* buffer = (char*) malloc(fileSize + 1);
    if (buffer == NULL) {
        printf("Error: could not allocate memory for buffer\n");
        exit(1);
    }

    int numCharsRead = fread(buffer, sizeof(char), fileSize, file);
    if (numCharsRead!= fileSize) {
        printf("Error: could not read entire file\n");
        exit(1);
    }

    buffer[fileSize] = '\0'; // Add null terminator to end of buffer
    fclose(file);

    return buffer;
}

// Function to count the number of words in a buffer
int countWords(char* buffer) {
    int numWords = 0;
    char* wordStart = buffer;

    while (*wordStart!= '\0') {
        if (isalpha(*wordStart)) {
            char* wordEnd = wordStart;
            while (isalnum(*wordEnd)) {
                wordEnd++;
            }
            numWords++;
            wordStart = wordEnd;
        } else {
            wordStart++;
        }
    }

    return numWords;
}

// Function to print a buffer with a given number of words per line
void printBuffer(char* buffer, int numWordsPerLine) {
    int numWords = countWords(buffer);
    int numLines = numWords / numWordsPerLine + (numWords % numWordsPerLine!= 0);

    for (int i = 0; i < numLines; i++) {
        int startIndex = i * numWordsPerLine;
        int endIndex = startIndex + numWordsPerLine - 1;
        if (endIndex >= numWords) {
            printf("%s\n", buffer + startIndex);
        } else {
            printf("%s ", buffer + startIndex);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* buffer = readFile(argv[1]);
    printBuffer(buffer, 80); // 80 characters per line

    free(buffer);
    return 0;
}