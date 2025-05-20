//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000
#define MAX_FILE_NAME_LEN 1000

// Function to count the number of words in a given string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " \t\n\r\f\v,.?!;:");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " \t\n\r\f\v,.?!;:");
    }
    return count;
}

// Function to read a file and count the number of words in it
int countFileWords(char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return -1;
    }

    int count = 0;
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        count += countWords(line);
    }

    fclose(file);
    return count;
}

int main() {
    char fileName[MAX_FILE_NAME_LEN];
    printf("Enter the name of the file to count words: ");
    scanf("%s", fileName);

    int count = countFileWords(fileName);
    if (count == -1) {
        return 1;
    }

    printf("The file %s contains %d words.\n", fileName, count);
    return 0;
}