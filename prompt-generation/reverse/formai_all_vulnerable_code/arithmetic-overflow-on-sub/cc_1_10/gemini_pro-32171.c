//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A visionary string manipulation program that explores the depths of linguistic abstraction.

// Defines a custom data type for representing words.
typedef struct Word {
    char *string;
    int length;
} Word;

// Creates a new word with the given string.
Word *new_word(char *string) {
    Word *word = malloc(sizeof(Word));
    word->string = strdup(string);
    word->length = strlen(string);
    return word;
}

// Frees the memory allocated for the given word.
void free_word(Word *word) {
    free(word->string);
    free(word);
}

// Compares two words lexicographically.
int compare_words(Word *a, Word *b) {
    return strcmp(a->string, b->string);
}

// Prints the given word to the standard output.
void print_word(Word *word) {
    printf("%s", word->string);
}

// Reverses the characters in the given word.
void reverse_word(Word *word) {
    int i, j;
    char temp;
    for (i = 0, j = word->length - 1; i < j; i++, j--) {
        temp = word->string[i];
        word->string[i] = word->string[j];
        word->string[j] = temp;
    }
}

// Sorts an array of words lexicographically.
void sort_words(Word **words, int n) {
    qsort(words, n, sizeof(Word *), (int (*)(const void *, const void *))compare_words);
}

// Finds the longest word in an array of words.
Word *find_longest_word(Word **words, int n) {
    Word *longest = NULL;
    int i;
    for (i = 0; i < n; i++) {
        if (words[i]->length > longest->length) {
            longest = words[i];
        }
    }
    return longest;
}

// Finds the shortest word in an array of words.
Word *find_shortest_word(Word **words, int n) {
    Word *shortest = NULL;
    int i;
    for (i = 0; i < n; i++) {
        if (words[i]->length < shortest->length) {
            shortest = words[i];
        }
    }
    return shortest;
}

// Creates an array of words from the given string.
Word **create_words(char *string) {
    char *token;
    char *rest = string;
    int n = 0;
    Word **words = NULL;

    while ((token = strtok_r(rest, " ", &rest))) {
        words = realloc(words, (n + 1) * sizeof(Word *));
        words[n++] = new_word(token);
    }

    return words;
}

// Frees the memory allocated for the given array of words.
void free_words(Word **words, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free_word(words[i]);
    }
    free(words);
}

// The main function.
int main() {
    char *string = "The quick brown fox jumped over the lazy dog";
    Word **words;
    int n;

    // Creates an array of words from the given string.
    words = create_words(string);

    // Sorts the array of words lexicographically.
    sort_words(words, n);

    // Prints the sorted array of words.
    for (n = 0; words[n] != NULL; n++) {
        print_word(words[n]);
        printf(" ");
    }

    printf("\n");

    // Finds the longest and shortest words in the array of words.
    Word *longest = find_longest_word(words, n);
    Word *shortest = find_shortest_word(words, n);

    // Prints the longest and shortest words.
    printf("Longest word: ");
    print_word(longest);
    printf("\n");

    printf("Shortest word: ");
    print_word(shortest);
    printf("\n");

    // Reverses the characters in the longest and shortest words.
    reverse_word(longest);
    reverse_word(shortest);

    // Prints the reversed longest and shortest words.
    printf("Reversed longest word: ");
    print_word(longest);
    printf("\n");

    printf("Reversed shortest word: ");
    print_word(shortest);
    printf("\n");

    // Frees the memory allocated for the array of words.
    free_words(words, n);

    return 0;
}