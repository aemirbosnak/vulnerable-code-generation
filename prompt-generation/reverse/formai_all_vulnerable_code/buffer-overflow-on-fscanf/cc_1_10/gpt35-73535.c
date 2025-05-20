//FormAI DATASET v1.0 Category: Text Summarizer ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Global variables */

#define MAX_WORDS 500      /* Maximum number of words */
#define MAX_WORD_LEN 20    /* Maximum length of a word */

char word_list[MAX_WORDS][MAX_WORD_LEN]; /* 2D array to store words */
int word_count[MAX_WORDS];               /* Array to store word frequency */
int total_words = 0;                     /* Total words processed */

/* Function declarations */

void read_input(FILE * input_file);
void count_word_frequency();
void sort_words();
void print_summary(int num_words);

/* Main function */

int main(int argc, char * argv[]) {

    /* Check command line argument */
    if (argc < 3) {
        printf("Usage: %s <input_file> <num_words>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Open input file */
    FILE * input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Read input file and count word frequency */
    read_input(input_file);
    count_word_frequency();

    /* Sort word frequency array */
    sort_words();

    /* Print summary */
    int num_words = atoi(argv[2]);
    print_summary(num_words);

    /* Close input file */
    fclose(input_file);

    return 0;
}

/* Function to read input file */

void read_input(FILE * input_file) {
    char buffer[MAX_WORD_LEN];
    while (fscanf(input_file, "%s", buffer) == 1) {
        strcpy(word_list[total_words], buffer);
        total_words++;
    }
}

/* Function to count word frequency */

void count_word_frequency() {
    int i, j;
    for (i = 0; i < total_words; i++) {
        if (word_count[i] == 0) {
            word_count[i] = 1;
            for (j = i+1; j < total_words; j++) {
                if (strcmp(word_list[i], word_list[j]) == 0) {
                    word_count[i]++;
                    word_count[j] = -1;
                }
            }
        }
    }
}

/* Function to sort word frequency array */

void sort_words() {
    int i, j, temp_count;
    char temp_word[MAX_WORD_LEN];
    for (i = 0; i < total_words-1; i++) {
        for (j = i+1; j < total_words; j++) {
            if (word_count[j] > word_count[i]) {
                temp_count = word_count[i];
                word_count[i] = word_count[j];
                word_count[j] = temp_count;
                strcpy(temp_word, word_list[i]);
                strcpy(word_list[i], word_list[j]);
                strcpy(word_list[j], temp_word);
            }
        }
    }
}

/* Function to print summary */

void print_summary(int num_words) {
    int i;
    printf("\n--- Summary ---\n\n");
    for (i = 0; i < num_words; i++) {
        if (word_count[i] > 0) {
            printf("%-20s %d\n", word_list[i], word_count[i]);
        }
    }
    printf("\n");
}