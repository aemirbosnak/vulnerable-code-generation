//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256
#define WORD_LENGTH 50
#define ARRAY_SIZE (MAX_CHAR * WORD_LENGTH)

typedef struct WordCount {
    char word[WORD_LENGTH];
    int count;
} WordCount;

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int isAlphabetic(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    FILE *file;
    char filename[50], line[1024], c;
    WordCount wordList[MAX_CHAR];
    int index, flag;

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file)) {
        toLowerCase(line);
        index = 0;
        flag = 1;
        for (int i = 0; line[i] != '\0'; i++) {
            if (isspace(line[i])) {
                if (flag) {
                    strcpy(wordList[index].word, "");
                    index++;
                    flag = 0;
                }
                continue;
            }
            if (isAlphabetic(line[i])) {
                wordList[index].word[strlen(wordList[index].word)] = line[i];
            } else {
                if (strlen(wordList[index].word) > 0) {
                    wordList[index].count++;
                    flag = 1;
                }
            }
        }
        if (strlen(wordList[index].word) > 0) {
            wordList[index].count++;
        }
    }
    fclose(file);

    printf("\nWord Frequency:\n");
    for (int i = 0; i < MAX_CHAR; i++) {
        if (strlen(wordList[i].word) > 0) {
            printf("%s : %d\n", wordList[i].word, wordList[i].count);
        }
    }

    return EXIT_SUCCESS;
}