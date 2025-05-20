//Falcon-180B DATASET v1.0 Category: Educational ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

// Function to generate a random word of length n
char *generate_random_word(int n) {
    char *word = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[n] = '\0';
    return word;
}

// Function to compare two words
int compare_words(char *word1, char *word2) {
    int length1 = strlen(word1);
    int length2 = strlen(word2);
    if (length1!= length2) {
        return length1 - length2;
    } else {
        for (int i = 0; i < length1; i++) {
            if (word1[i] > word2[i]) {
                return 1;
            } else if (word1[i] < word2[i]) {
                return -1;
            }
        }
    }
    return 0;
}

// Function to sort an array of words
void sort_words(char **words, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compare_words(words[i], words[j]) > 0) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

// Function to print an array of words
void print_words(char **words, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Generate an array of random words
    char **words = malloc(MAX_WORDS * sizeof(char *));
    int n = 0;
    while (n < MAX_WORDS) {
        char *word = generate_random_word(rand() % (MAX_WORD_LENGTH + 1));
        int m = 0;
        while (m < n && compare_words(words[m], word) <= 0) {
            m++;
        }
        if (m == n) {
            words = realloc(words, (n + 1) * sizeof(char *));
            words[n] = word;
            n++;
        }
    }

    // Sort the array of words
    sort_words(words, n);

    // Print the sorted array of words
    printf("Sorted array of words:\n");
    print_words(words, n);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}