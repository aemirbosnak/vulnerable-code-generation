//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compare(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char *word;
    int count = 0;
    WordFrequency words[MAX_WORDS];

    if ((fp = fopen("resume.txt", "r")) == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        word = strtok(line, " ");

        while (word!= NULL) {
            count++;

            if (count >= MAX_WORDS) {
                printf("Maximum number of words reached\n");
                exit(1);
            }

            int i;
            for (i = 0; i < count; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }

            if (i == count) {
                strcpy(words[count].word, word);
                words[count].frequency = 1;
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    qsort(words, count, sizeof(WordFrequency), compare);

    printf("Word\t\tFrequency\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\n", words[i].word, words[i].frequency);
    }

    return 0;
}