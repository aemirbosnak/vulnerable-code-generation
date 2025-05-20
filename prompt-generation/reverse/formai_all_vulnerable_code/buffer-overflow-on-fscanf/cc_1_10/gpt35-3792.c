//FormAI DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY "dictionary.txt"

// Linked list structure for word node
struct node {
    char *word;
    struct node *next;
};

// Function to insert word into linked list
struct node* insert_word(struct node *head, const char *word) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->word = malloc(strlen(word) + 1);
    strcpy(new_node->word, word);
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to load words from dictionary file into linked list as a hash table
int load_dictionary(struct node **hash_table, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    char word[46];
    int index;
    int count = 0;
    while (fscanf(file, "%s", word) != EOF) {
        index = tolower(word[0]) - 'a';
        hash_table[index] = insert_word(hash_table[index], word);
        count++;
    }
    fclose(file);
    return count;
}

// Function to free linked list memory
void free_list(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->word);
        free(temp);
    }
}

// Recursive function to check if word is spelled correctly
int check_spelling(const char *word, struct node *head) {
    if (head == NULL) {
        return 0;
    }
    int result = strcmp(word, head->word);
    if (result == 0) {
        return 1;
    } else if (result < 0) {
        return 0;
    } else {
        return check_spelling(word, head->next);
    }
}

int main(void) {
    struct node *hash_table[26] = {NULL};
    int dictionary_words_count = load_dictionary(hash_table, DICTIONARY);
    if (dictionary_words_count == 0) {
        printf("Could not load dictionary file.\n");
        return 1;
    }
    char input[46];
    printf("Enter a word to check spelling (Enter QUIT to exit):\n");
    while (scanf("%45s", input) == 1) {
        if (strcmp(input, "QUIT") == 0) {
            break;
        }
        int index = tolower(input[0]) - 'a';
        int result = check_spelling(input, hash_table[index]);
        if (result == 1) {
            printf("%s is spelled correctly.\n", input);
        } else {
            printf("%s is misspelled.\n", input);
        }
    }
    for (int i = 0; i < 26; i++) {
        free_list(hash_table[i]);
    }
    return 0;
}