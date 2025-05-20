//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define SEARCH_LENGTH 20

// Structure to store the list of words
typedef struct {
    char *words[MAX_LENGTH];
    int len;
} word_list;

// Function to insert a word into the list
void insert_word(word_list *list, char *word) {
    if (list->len == MAX_LENGTH) {
        printf("Error: List is full, cannot insert %s\n", word);
        return;
    }
    list->words[list->len] = word;
    list->len++;
}

// Function to search for a word in the list
int search_word(word_list *list, char *word) {
    int i, j;
    for (i = 0; i < list->len; i++) {
        if (strcmp(list->words[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print the list of words
void print_list(word_list *list) {
    int i;
    for (i = 0; i < list->len; i++) {
        printf("%d: %s\n", i, list->words[i]);
    }
}

int main() {
    word_list list;
    char *words[] = {"apple", "banana", "cherry", "date", "elephant"};
    int i;

    // Initialize the list
    for (i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        insert_word(&list, words[i]);
    }

    // Search for a word
    int result = search_word(&list, "banana");
    if (result != -1) {
        printf("Found %s at index %d\n", "banana", result);
    } else {
        printf("Not found\n");
    }

    // Print the list
    print_list(&list);

    return 0;
}