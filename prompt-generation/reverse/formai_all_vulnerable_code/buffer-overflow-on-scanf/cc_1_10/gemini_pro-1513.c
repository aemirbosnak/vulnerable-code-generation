//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the palindrome checking result
struct PalindromeResult {
    int is_palindrome;
    char* word;
};

// Thread function to check if a word is a palindrome
void* check_palindrome(void* arg) {
    struct PalindromeResult* result = (struct PalindromeResult*)arg;

    // Convert the word to lowercase for case-insensitive comparison
    char* lowercase_word = malloc(strlen(result->word) + 1);
    strcpy(lowercase_word, result->word);
    for (int i = 0; lowercase_word[i] != '\0'; i++) {
        lowercase_word[i] = tolower(lowercase_word[i]);
    }

    // Check if the word is a palindrome
    int is_palindrome = 1;
    int length = strlen(lowercase_word);
    for (int i = 0; i < length / 2; i++) {
        if (lowercase_word[i] != lowercase_word[length - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }

    // Update the result structure with the palindrome checking result
    result->is_palindrome = is_palindrome;

    // Free the allocated memory
    free(lowercase_word);

    return NULL;
}

int main() {
    // Get the input words from the user
    int num_words;
    printf("Enter the number of words to check: ");
    scanf("%d", &num_words);

    char** words = malloc(num_words * sizeof(char*));
    for (int i = 0; i < num_words; i++) {
        printf("Enter word %d: ", i + 1);
        char* word = malloc(100);
        scanf("%s", word);
        words[i] = word;
    }

    // Create a thread pool to check the palindromes in parallel
    pthread_t* threads = malloc(num_words * sizeof(pthread_t));
    struct PalindromeResult* results = malloc(num_words * sizeof(struct PalindromeResult));
    for (int i = 0; i < num_words; i++) {
        results[i].word = words[i];
        pthread_create(&threads[i], NULL, check_palindrome, &results[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_words; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the palindrome checking results
    for (int i = 0; i < num_words; i++) {
        if (results[i].is_palindrome) {
            printf("%s is a palindrome\n", results[i].word);
        } else {
            printf("%s is not a palindrome\n", results[i].word);
        }
    }

    // Free the allocated memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    free(threads);
    free(results);

    return 0;
}