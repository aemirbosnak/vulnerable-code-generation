//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 30

struct word {
    char word[WORD_LENGTH];
    int count;
};

int main() {
    FILE *file;
    char filename[100];
    char line[100];
    int count = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    struct word words[MAX_WORDS];

    printf("Enter the name of the file to be checked: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, 100, file)!= NULL) {
        count++;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                for (j = i; j < strlen(line); j++) {
                    if (!isalpha(line[j])) {
                        k = j - i;
                        if (k > 0) {
                            strncpy(words[count].word, line + i, k);
                            words[count].word[k] = '\0';
                            words[count].count++;
                        }
                        i = j;
                        break;
                    }
                }
            }
        }
    }

    fclose(file);

    printf("Total number of words: %d\n", count);

    for (i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}