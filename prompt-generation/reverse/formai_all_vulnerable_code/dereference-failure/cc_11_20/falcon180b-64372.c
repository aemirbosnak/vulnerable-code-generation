//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word_t;

int main() {
    char input_string[200];
    char *word;
    FILE *fp;
    int i, j, len, count = 0;
    Word_t words[MAX_WORDS];

    printf("Enter the file name: ");
    scanf("%s", input_string);

    // Open the file
    fp = fopen(input_string, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the file and store words in an array
    while (fscanf(fp, "%s", word)!= EOF) {
        len = strlen(word);
        if (len > MAX_WORD_LENGTH) {
            printf("Error: Word length exceeds maximum limit.\n");
            exit(1);
        }
        strcpy(words[count].word, word);
        words[count].count = 1;
        count++;
    }

    // Close the file
    fclose(fp);

    // Sort the array in alphabetical order
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                Word_t temp;
                strcpy(temp.word, words[i].word);
                temp.count = words[i].count;
                strcpy(words[i].word, words[j].word);
                words[i].count = words[j].count;
                strcpy(words[j].word, temp.word);
                words[j].count = temp.count;
            }
        }
    }

    // Print the sorted array
    printf("Sorted words:\n");
    for (i = 0; i < count; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }

    // Check for spelling mistakes
    printf("\nEnter the word to check: ");
    scanf("%s", word);
    len = strlen(word);
    if (len > MAX_WORD_LENGTH) {
        printf("Error: Word length exceeds maximum limit.\n");
        exit(1);
    }

    for (i = 0; i < count; i++) {
        if (strcmp(word, words[i].word) == 0) {
            printf("%s is spelled correctly.\n", word);
            exit(0);
        }
    }

    printf("%s is spelled incorrectly.\n", word);

    return 0;
}