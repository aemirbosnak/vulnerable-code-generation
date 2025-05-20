//FormAI DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 1000

typedef struct Node {
    char* word;
    struct Node* next;
} Node;

Node* hash_table[TABLE_SIZE];

// Hash function
int hash(char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += tolower(word[i]);
    }
    return sum % TABLE_SIZE;
}

// Insert a word into the hash table
void insert(char* word) {
    int index = hash(word);
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->word = strdup(word);
    new_node->next = NULL;
    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        Node* temp = hash_table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Check if a word is in the hash table
bool check(char* word) {
    int index = hash(word);
    Node* temp = hash_table[index];
    while (temp != NULL) {
        if (strcmp(temp->word, word) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Free memory allocated for the hash table
void cleanup() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hash_table[i];
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp->word);
            free(temp);
            temp = next;
        }
        hash_table[i] = NULL;
    }
}

int main() {
    // Read in the dictionary file
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open dictionary file\n");
        return 1;
    }
    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        insert(word);
    }
    fclose(fp);

    // Prompt the user to enter a sentence
    printf("Enter a sentence to spell check:\n");
    char sentence[1000];
    fgets(sentence, 1000, stdin);

    // Split the sentence into words
    char* token = strtok(sentence, " \n");
    while (token != NULL) {
        // Remove punctuation from the word
        int i, j;
        for (i = 0, j = 0; token[i]; i++) {
            if (isalpha(token[i]))
                token[j++] = tolower(token[i]);
        }
        token[j] = '\0';

        // Check if the word is in the dictionary
        if (!check(token)) {
            // Generate suggestions for the misspelled word
            printf("Possible suggestions for '%s':\n", token);
            for (int i = 0; i < strlen(token); i++) {
                char temp = token[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == temp) {
                        continue;
                    }
                    token[i] = c;
                    if (check(token)) {
                        printf("%s\n", token);
                    }
                }
                token[i] = temp;
            }
        }

        // Get the next word
        token = strtok(NULL, " \n");
    }

    // Free memory allocated for the hash table
    cleanup();

    return 0;
}