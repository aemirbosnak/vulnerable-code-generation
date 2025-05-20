//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * This program reads a text file, counts the occurrences of each unique word,
 * and prints them in descending order according to their frequency.
 * It ignores punctuation and capitalization.
 */

// define a structure for each unique word with its frequency
struct word {
    char str[50];
    int freq;
};

// function to compare two words by their frequency
int compare_words(const void* a, const void* b) {
    struct word *w1 = (struct word*) a;
    struct word *w2 = (struct word*) b;
    return (w2->freq - w1->freq);
}

// function to remove punctuation from a given string
void remove_punct(char *s) {
    char *src = s, *dst = s;
    while (*src) {
        if (ispunct((unsigned char)*src)) {
            src++;
        } else if (isupper((unsigned char)*src)) {
            *dst++ = tolower((unsigned char)*src++);
        } else if (src == dst) {
            src++; dst++;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';
}

// function to check if a given word is already in the array
int is_duplicate(struct word *words, int len, char *str) {
    int i;
    for (i=0; i<len; i++) {
        if (strcmp(words[i].str, str) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    FILE *fp;
    char filename[50], word[50];
    struct word words[100];
    int i, len = 0;

    // ask user to enter the filename
    printf("Enter the filename to read: ");
    scanf("%s", filename);

    // open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // read words from the file and update the frequency of each word
    while (fscanf(fp, "%s", word) != EOF) {
        remove_punct(word);
        int idx = is_duplicate(words, len, word);
        if (idx == -1) {
            // add new word to the array
            strcpy(words[len].str, word);
            words[len].freq = 1;
            len++;
        } else {
            // update frequency of existing word
            words[idx].freq++;
        }
    }

    // sort the array of words by their frequency
    qsort(words, len, sizeof(struct word), compare_words);

    // print the words and their frequency in descending order
    printf("\nWord frequency in \"%s\":\n", filename);
    for (i=0; i<len; i++) {
        printf("%s: %d\n", words[i].str, words[i].freq);
    }

    // close the file
    fclose(fp);

    return 0;
}