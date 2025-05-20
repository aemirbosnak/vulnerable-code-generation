//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// structure to store word and its frequency
struct Word {
    char str[50];
    int freq;
};

// function to compare two words by their frequency
int cmp(const void *a, const void *b) {
    struct Word *w1 = (struct Word *) a;
    struct Word *w2 = (struct Word *) b;

    return w2->freq - w1->freq;
}

int main() {
    char filename[50];

    // get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Error opening file!\n");
        return 1;
    }

    // array to store words
    struct Word words[1000];
    int n = 0;

    // loop through file
    while (!feof(fp)) {
        char word[50];
        fscanf(fp, "%s", word);

        // convert all characters to lowercase
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }

        // check if word exists in array
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(words[i].str, word) == 0) {
                words[i].freq++;
                flag = 1;
                break;
            }
        }

        // add word to array if it doesn't exist
        if (!flag) {
            strcpy(words[n].str, word);
            words[n].freq = 1;
            n++;
        }
    }

    fclose(fp);

    // sort the array by frequency
    qsort(words, n, sizeof(struct Word), cmp);

    // print the top 10 words
    printf("\nTop 10 words:\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%s - %d\n", words[i].str, words[i].freq);
    }

    return 0;
}