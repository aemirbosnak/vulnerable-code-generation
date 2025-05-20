//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

int main() {
    char filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    FILE *file;
    WordCount words[MAX_NUM_WORDS];
    int num_words = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, " \n\t\r");
        while (token!= NULL) {
            strcpy(word, token);
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_NUM_WORDS) {
                    printf("Too many words in the file.\n");
                    fclose(file);
                    return 1;
                }
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, " \n\t\r");
        }
    }

    fclose(file);

    printf("Word count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}