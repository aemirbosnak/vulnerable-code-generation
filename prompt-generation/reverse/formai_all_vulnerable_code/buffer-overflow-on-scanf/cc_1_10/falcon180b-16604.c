//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 16

// Function to count the frequency of a word in a string
int count_word_frequency(char *str, char *word) {
    int count = 0;
    char *start = str;
    while ((start = strstr(start, word))!= NULL) {
        count++;
        start += strlen(word);
    }
    return count;
}

// Function to print the top n frequent words in a string
void print_top_n_words(char *str, int n) {
    int word_counts[MAX_WORD_SIZE] = { 0 };
    char words[MAX_WORD_SIZE][MAX_LINE_SIZE] = { "" };
    int num_words = 0;
    char *start = str;
    char *word;
    while ((word = strtok(start, " \t\r\n\f\v\""))!= NULL) {
        start = NULL;
        int i;
        for (i = 0; i < num_words && strcmp(words[i], word)!= 0; i++) {
            // Do nothing
        }
        if (i == num_words) {
            strcpy(words[num_words], word);
            word_counts[num_words] = count_word_frequency(str, word);
            num_words++;
            if (num_words == MAX_WORD_SIZE) {
                break;
            }
        }
    }
    printf("Top %d frequent words:\n", n);
    for (int i = 0; i < num_words && i < n; i++) {
        printf("%s: %d\n", words[i], word_counts[i]);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char filename[MAX_LINE_SIZE];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    int num_lines = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        num_lines++;
        if (num_lines % 1000 == 0) {
            print_top_n_words(line, 10);
        }
    }
    fclose(fp);
    return 0;
}