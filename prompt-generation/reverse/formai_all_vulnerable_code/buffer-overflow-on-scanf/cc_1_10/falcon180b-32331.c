//Falcon-180B DATASET v1.0 Category: Recursive ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000

int countWords(char *str);
int countChars(char *str);
int countLines(char *str);
int countParagraphs(char *str);

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    int words = countWords(str);
    int chars = countChars(str);
    int lines = countLines(str);
    int paragraphs = countParagraphs(str);

    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);
    printf("Lines: %d\n", lines);
    printf("Paragraphs: %d\n", paragraphs);

    return 0;
}

int countWords(char *str) {
    int count = 0;
    char *word = strtok(str, " \t\r\n\f\v.?!;:,");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " \t\r\n\f\v.?!;:,");
    }
    return count;
}

int countChars(char *str) {
    int count = 0;
    for (int i = 0; str[i]!= '\0'; i++) {
        count++;
    }
    return count;
}

int countLines(char *str) {
    int count = 0;
    char *line = strtok(str, "\n");
    while (line!= NULL) {
        count++;
        line = strtok(NULL, "\n");
    }
    return count;
}

int countParagraphs(char *str) {
    int count = 0;
    char *paragraph = strtok(str, "\n\n");
    while (paragraph!= NULL) {
        count++;
        paragraph = strtok(NULL, "\n\n");
    }
    return count;
}