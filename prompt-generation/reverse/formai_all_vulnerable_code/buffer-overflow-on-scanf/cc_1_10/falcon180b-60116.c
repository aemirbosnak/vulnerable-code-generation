//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char filename[100];
    char line[100];
    int totalWords = 0;
    WordCount words[MAX_WORDS];

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            totalWords++;
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == MAX_WORDS) {
                strcpy(words[totalWords - 1].word, token);
                words[totalWords - 1].count = 1;
            }
            token = strtok(NULL, ",.!?;:");
        }
    }

    printf("Total words: %d\n", totalWords);
    printf("Word frequency:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(file);
    return 0;
}