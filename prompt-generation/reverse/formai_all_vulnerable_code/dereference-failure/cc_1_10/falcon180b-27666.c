//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 100

// Function to remove leading/trailing whitespace from string
void trim(char* str) {
    int len = strlen(str);
    char* end = str + len - 1;

    while (isspace(*end)) {
        *end = '\0';
        end--;
    }

    while (isspace(*str)) {
        str++;
    }
}

// Function to split string into words
int split(char* line, char* words[], int max_words) {
    int num_words = 0;
    char* word = strtok(line, " ");

    while (word!= NULL && num_words < max_words) {
        strcpy(words[num_words], word);
        num_words++;
        word = strtok(NULL, " ");
    }

    return num_words;
}

// Function to count frequency of words
int count_frequency(char* words[], int num_words) {
    int freq[26] = {0};

    for (int i = 0; i < num_words; i++) {
        char* word = words[i];
        trim(word);

        if (strlen(word) > 0) {
            char first_char = tolower(word[0]);

            if (isalpha(first_char)) {
                freq[first_char - 'a']++;
            }
        }
    }

    return freq[0];
}

// Function to print frequency of words
void print_frequency(int freq[], int max_freq) {
    for (int i = 0; i < max_freq; i++) {
        printf("%c: %d\n", i + 'a', freq[i]);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];

    // Read log file
    FILE* fp = fopen("logfile.txt", "r");

    if (fp == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }

    // Count frequency of words
    int freq[26] = {0};
    int num_lines = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        num_lines++;

        // Split line into words
        int num_words = split(line, words, MAX_NUM_WORDS);

        // Count frequency of words
        freq[count_frequency(words, num_words)]++;
    }

    // Print frequency of words
    printf("Frequency of words:\n");
    print_frequency(freq, 26);

    fclose(fp);
    return 0;
}