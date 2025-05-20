//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 5000

struct Word {
    char word[50];
    int count;
};

void read_file(FILE *file, struct Word words[]) {
    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        int j = 0;
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (i >= MAX_WORDS) {
                break;
            }
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
            word = strtok(NULL, ",.?!;:");
        }
    }
}

void print_words(struct Word words[], int num_words) {
    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    char filename[50];
    struct Word words[MAX_WORDS];
    int num_words = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    read_file(file, words);
    num_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            num_words++;
        }
    }

    printf("\nTotal number of words: %d\n", num_words);
    printf("\nTop 10 most frequent words:\n");
    print_words(words, num_words);

    fclose(file);
    return 0;
}