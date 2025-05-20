//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 30
#define MAX_NUM_WORDS 5000
#define MAX_NUM_CHARACTERS 10000

char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
int num_words = 0;
int num_characters = 0;

void read_words(FILE *file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_NUM_WORDS) {
            printf("Error: Too many words!\n");
            exit(1);
        }
        strcpy(words[num_words], word);
        num_words++;
        num_characters += strlen(word);
    }
}

void count_words(FILE *file) {
    char ch;
    int in_word = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalnum(ch)) {
            in_word = 1;
        } else if (in_word) {
            in_word = 0;
            if (num_words >= MAX_NUM_WORDS) {
                printf("Error: Too many words!\n");
                exit(1);
            }
            strcpy(words[num_words], "");
            num_words++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }
    read_words(file);
    fclose(file);
    count_words(file);
    fclose(file);
    printf("Number of words: %d\n", num_words);
    printf("Number of characters: %d\n", num_characters);
    return 0;
}