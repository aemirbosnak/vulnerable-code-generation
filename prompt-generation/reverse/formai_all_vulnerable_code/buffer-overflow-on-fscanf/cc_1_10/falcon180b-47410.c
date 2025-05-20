//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

// Node structure for the hash table
typedef struct node {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Node;

// Hash table
Node hash_table[MAX_WORDS];

// Function to calculate the hash value of a word
int hash(char *word) {
    int hash_value = 0;
    int i = 0;
    while (word[i]!= '\0') {
        hash_value += tolower(word[i]) - 'a';
        i++;
    }
    return hash_value % MAX_WORDS;
}

// Function to insert a word into the hash table
void insert_word(char *word) {
    int index = hash(word);
    Node *node = &hash_table[index];
    while (node->word[0]!= '\0') {
        if (strcmp(node->word, word) == 0) {
            node->frequency++;
            return;
        }
        node++;
    }
    strcpy(node->word, word);
    node->frequency = 1;
}

// Function to print the hash table
void print_hash_table() {
    int i = 0;
    while (i < MAX_WORDS) {
        Node *node = &hash_table[i];
        while (node->word[0]!= '\0') {
            printf("%s: %d\n", node->word, node->frequency);
            node++;
        }
        i++;
    }
}

// Function to read a file and count the frequency of words
void count_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        insert_word(word);
    }
    fclose(file);
}

int main() {
    count_words("input.txt");
    print_hash_table();
    return 0;
}