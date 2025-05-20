//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000

// Function to count the number of words in a line
int countWords(char line[]) {
    int count = 0;
    char word[MAX_WORD_LEN] = {'\0'};
    char *ptr = strtok(line, " \t\n\r\f\v");
    while (ptr!= NULL) {
        strcpy(word, ptr);
        if (strlen(word) > 0) {
            count++;
        }
        ptr = strtok(NULL, " \t\n\r\f\v");
    }
    return count;
}

// Function to count the number of lines in a file
int countLines(FILE *fp) {
    int count = 0;
    char line[MAX_LINE_LEN] = {'\0'};
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        count++;
    }
    return count;
}

int main() {
    FILE *fp;
    char filename[MAX_LINE_LEN];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open the file in read mode
    fp = fopen(filename, "r");

    // Check if the file is opened successfully
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return -1;
    }

    // Count the number of lines in the file
    int numLines = countLines(fp);

    // Count the number of words in each line
    int numWords = 0;
    char line[MAX_LINE_LEN] = {'\0'};
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        numWords += countWords(line);
    }

    // Calculate the average number of words per line
    float avgWordsPerLine = (float)numWords / numLines;

    // Close the file
    fclose(fp);

    // Print the results
    printf("Number of lines in the file: %d\n", numLines);
    printf("Number of words in the file: %d\n", numWords);
    printf("Average number of words per line: %.2f\n", avgWordsPerLine);

    return 0;
}