//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct word_count {
    char word[MAX_WORD_LEN];
    int count;
};

int main() {
    FILE *file;
    char line[MAX_WORD_LEN * 10];
    int num_words = 0;
    struct word_count word_counts[MAX_WORDS];

    printf("Enter the filename: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *word = strtok(line, " \t\n\r\f\v,.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Maximum number of words reached\n");
                    exit(1);
                }
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, " \t\n\r\f\v,.?!;:");
        }
    }

    fclose(file);

    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}