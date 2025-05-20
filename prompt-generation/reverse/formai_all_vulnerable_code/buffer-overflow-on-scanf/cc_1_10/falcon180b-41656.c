//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    FILE *file;
    char filename[100];
    char line[100];
    int i, j, k, count;
    Word words[MAX_WORDS];
    int num_words = 0;

    // ask user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // read file line by line
    while (fgets(line, 100, file)!= NULL) {
        count = 0;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                j = 0;
                while (isalpha(line[i + j])) {
                    j++;
                }
                if (j > 0) {
                    strncpy(words[num_words].word, line + i, j);
                    words[num_words].word[j] = '\0';
                    words[num_words].count++;
                    count++;
                    num_words++;
                }
            }
        }
    }

    // close file
    fclose(file);

    // print results
    printf("Total words: %d\n", num_words);
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}