//Falcon-180B DATASET v1.0 Category: Database querying ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64
#define MAX_QUERY_SIZE 256
#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} WordCount;

void loadWords(FILE *file, WordCount *words) {
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    int wordCount = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            strcpy(word, token);
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            int found = 0;
            for (int j = 0; j < wordCount; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                if (wordCount >= MAX_WORDS) {
                    printf("Error: Maximum number of words exceeded.\n");
                    exit(1);
                }

                strcpy(words[wordCount].word, word);
                words[wordCount].count = 1;
                wordCount++;
            }

            token = strtok(NULL, ",.?!;:");
        }
    }
}

void queryWords(WordCount *words, int numWords, char *query) {
    char *tokens[MAX_QUERY_SIZE];
    int numTokens = 0;

    char *token = strtok(query, " ");
    while (token!= NULL) {
        if (numTokens >= MAX_QUERY_SIZE) {
            printf("Error: Maximum number of query tokens exceeded.\n");
            exit(1);
        }

        strcpy(tokens[numTokens], token);
        numTokens++;

        token = strtok(NULL, " ");
    }

    int totalCount = 0;
    for (int i = 0; i < numWords; i++) {
        int found = 0;
        for (int j = 0; j < numTokens; j++) {
            if (strcmp(tokens[j], words[i].word) == 0) {
                printf("%s: %d\n", words[i].word, words[i].count);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%s: 0\n", words[i].word);
        }

        totalCount += words[i].count;
    }

    printf("Total count: %d\n", totalCount);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <text_file> <query>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    WordCount words[MAX_WORDS];
    loadWords(file, words);
    fclose(file);

    queryWords(words, argc - 2, argv[2]);

    return 0;
}