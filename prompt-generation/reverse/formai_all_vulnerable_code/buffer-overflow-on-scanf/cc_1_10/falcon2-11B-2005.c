//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 1024

// Function to tokenize a string into individual words
void tokenize_string(char* str, char* word[], int* n) {
    char* token = strtok(str, " \t\n");
    int i = 0;
    while (token!= NULL) {
        strcpy(word[i], token);
        token = strtok(NULL, " \t\n");
        i++;
    }
    *n = i;
}

// Function to count the occurrences of each word in a hash table
void count_word_occurrences(char* word, int* occurrences, int* n) {
    int hash_value = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_value += (word[i] - 'a' + 1) * (i + 1);
    }
    *occurrences = hash_value % *n;
}

// Function to print the top 10 most common words
void print_top_10_words(int occurrences[], char* words[], int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        if (occurrences[i] >= 10) {
            printf("%s : %d\n", words[i], occurrences[i]);
        }
    }
}

int main() {
    char input_file[MAX_FILE_SIZE];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    // Open the input file for reading
    FILE* fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error opening the input file\n");
        return 1;
    }

    // Allocate memory for word array and occurrences array
    char* words[MAX_FILE_SIZE];
    int n = 0;
    int occurrences[MAX_FILE_SIZE];

    // Read words from the input file and count their occurrences
    char word[MAX_WORD_LENGTH];
    while (fgets(word, MAX_WORD_LENGTH, fp)!= NULL) {
        tokenize_string(word, words, &n);
        for (int i = 0; i < n; i++) {
            count_word_occurrences(words[i], &occurrences[i], n);
        }
    }

    // Close the input file
    fclose(fp);

    // Print the top 10 most common words
    print_top_10_words(occurrences, words, n);

    return 0;
}