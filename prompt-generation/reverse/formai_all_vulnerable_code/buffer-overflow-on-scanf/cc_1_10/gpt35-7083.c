//FormAI DATASET v1.0 Category: Text processing ; Style: real-life
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

// function prototypes
int countWords(char []);
int countCharacters(char []);
int countLines(FILE *);

int main() {
    FILE *fp;
    char filename[MAX_LENGTH], text[MAX_LENGTH];

    printf("Enter filename to open: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: unable to open file\n");
        return 1;
    }

    printf("-------------------------------------------------------------\n");
    printf("File Contents:\n");
    while (fgets(text, MAX_LENGTH, fp) != NULL) {
        fputs(text, stdout);
    }

    printf("\n-------------------------------------------------------------\n\n");

    // Word count
    printf("Word Count: %d\n", countWords(text));

    // Character count
    printf("Character Count: %d\n", countCharacters(text));

    // Line count
    printf("Line Count: %d\n", countLines(fp));

    fclose(fp);
    return 0;
}

// function to count words
int countWords(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count + 1;
}

// function to count characters
int countCharacters(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n' && str[i] != ' ') {
            count++;
        }
    }
    return count;
}

// function to count lines
int countLines(FILE *fp) {
    int count = 0;
    char ch = getc(fp);
    while (ch != EOF) {
        if (ch == '\n') {
            count++;
        }
        ch = getc(fp);
    }
    rewind(fp);
    return count;
}