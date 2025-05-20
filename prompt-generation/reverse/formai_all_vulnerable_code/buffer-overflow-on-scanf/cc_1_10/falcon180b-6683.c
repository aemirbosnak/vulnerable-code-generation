//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct word_count {
    char word[MAX_WORD_LEN];
    int count;
};

int main() {
    FILE *file;
    char line[1000];
    char *word;
    struct word_count counts[MAX_WORDS];
    int num_words = 0;
    int i;

    printf("Enter filename: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        num_words = 0;
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Too many words in line.\n");
                exit(1);
            }
            strcpy(counts[num_words].word, word);
            counts[num_words].count = 1;
            num_words++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", counts[i].word, counts[i].count);
    }

    return 0;
}