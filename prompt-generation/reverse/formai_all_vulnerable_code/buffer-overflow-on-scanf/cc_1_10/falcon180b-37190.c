//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

typedef struct WordFrequency WordFrequency;

void read_file(FILE *fp, WordFrequency *word_freq) {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_length = 0;
    int i;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                if (word_length == MAX_WORD_LENGTH - 1) {
                    break;
                }
                word[word_length++] = tolower(line[i]);
            } else {
                if (word_length > 0) {
                    word[word_length] = '\0';
                    for (int j = 0; j < strlen(word); j++) {
                        if (isalpha(word[j])) {
                            word[j] = tolower(word[j]);
                        }
                    }
                    if (strlen(word) > 0) {
                        for (int j = 0; j < MAX_WORD_LENGTH; j++) {
                            word_freq[j].word[j] = word[j];
                        }
                        word_freq[i].frequency++;
                    }
                    word_length = 0;
                }
            }
        }
    }
}

void print_word_frequency(WordFrequency *word_freq) {
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word_freq[i].frequency > 0) {
            printf("%s : %d\n", word_freq[i].word, word_freq[i].frequency);
        }
    }
}

int main() {
    FILE *fp;
    WordFrequency word_freq[MAX_WORD_LENGTH];
    char filename[MAX_LINE_LENGTH];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(fp, word_freq);

    fclose(fp);

    printf("Word frequency:\n");
    print_word_frequency(word_freq);

    return 0;
}