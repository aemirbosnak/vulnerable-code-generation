//Falcon-180B DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 100

typedef struct {
    char word[MAX_LINE_LENGTH];
    int count;
} WordCount;

int main() {
    char filename[MAX_LINE_LENGTH];
    FILE *file;
    char line[MAX_LINE_LENGTH];
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                strcpy(words[num_words].word, token);
                words[num_words].count = 1;
                num_words++;
                if (num_words >= MAX_WORDS) {
                    printf("Reached maximum number of words\n");
                    break;
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    printf("Word count:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(file);
    return 0;
}