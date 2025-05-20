//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[1024];
    char word[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter the name of the file to count words in: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *p = strtok(line, ",.?!;:");
        while (p!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Too many words in file.\n");
                fclose(file);
                return 1;
            }
            strcpy(words[numWords].word, p);
            words[numWords].count = 1;
            numWords++;
            p = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}