//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct word_node {
    char* word;
    struct word_node* next;
} word_node;

typedef struct dictionary {
    word_node* head;
} dictionary;

// Function prototypes
void print_menu();
void add_word(dictionary* dict);
void remove_word(dictionary* dict);
void find_word(dictionary* dict);
void check_spelling(dictionary* dict);
void free_dictionary(dictionary* dict);

// Main function
int main() {
    // Create a dictionary
    dictionary* dict = (dictionary*)malloc(sizeof(dictionary));
    dict->head = NULL;

    // Print the menu
    print_menu();

    // Get the user's choice
    int choice;
    scanf("%d", &choice);

    // Process the user's choice
    while (choice != 5) {
        switch (choice) {
            case 1:
                add_word(dict);
                break;
            case 2:
                remove_word(dict);
                break;
            case 3:
                find_word(dict);
                break;
            case 4:
                check_spelling(dict);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        // Print the menu
        print_menu();

        // Get the user's choice
        scanf("%d", &choice);
    }

    // Free the dictionary
    free_dictionary(dict);

    return 0;
}

// Function definitions
void print_menu() {
    printf("1. Add a word to the dictionary\n");
    printf("2. Remove a word from the dictionary\n");
    printf("3. Find a word in the dictionary\n");
    printf("4. Check the spelling of a word\n");
    printf("5. Quit\n");
}

void add_word(dictionary* dict) {
    // Get the word from the user
    char word[100];
    printf("Enter the word you want to add: ");
    scanf("%s", word);

    // Create a new word node
    word_node* new_node = (word_node*)malloc(sizeof(word_node));
    new_node->word = strdup(word);
    new_node->next = NULL;

    // Add the new node to the dictionary
    if (dict->head == NULL) {
        dict->head = new_node;
    } else {
        word_node* current_node = dict->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    // Print a confirmation message
    printf("The word \"%s\" has been added to the dictionary.\n", word);
}

void remove_word(dictionary* dict) {
    // Get the word from the user
    char word[100];
    printf("Enter the word you want to remove: ");
    scanf("%s", word);

    // Find the word in the dictionary
    word_node* current_node = dict->head;
    word_node* previous_node = NULL;
    while (current_node != NULL && strcmp(current_node->word, word) != 0) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    // Check if the word was found
    if (current_node == NULL) {
        printf("The word \"%s\" was not found in the dictionary.\n", word);
        return;
    }

    // Remove the word from the dictionary
    if (previous_node == NULL) {
        dict->head = current_node->next;
    } else {
        previous_node->next = current_node->next;
    }

    // Free the memory allocated for the word node
    free(current_node->word);
    free(current_node);

    // Print a confirmation message
    printf("The word \"%s\" has been removed from the dictionary.\n", word);
}

void find_word(dictionary* dict) {
    // Get the word from the user
    char word[100];
    printf("Enter the word you want to find: ");
    scanf("%s", word);

    // Find the word in the dictionary
    word_node* current_node = dict->head;
    while (current_node != NULL && strcmp(current_node->word, word) != 0) {
        current_node = current_node->next;
    }

    // Check if the word was found
    if (current_node == NULL) {
        printf("The word \"%s\" was not found in the dictionary.\n", word);
        return;
    }

    // Print a confirmation message
    printf("The word \"%s\" was found in the dictionary.\n", word);
}

void check_spelling(dictionary* dict) {
    // Get the word from the user
    char word[100];
    printf("Enter the word you want to check the spelling of: ");
    scanf("%s", word);

    // Find the word in the dictionary
    word_node* current_node = dict->head;
    while (current_node != NULL && strcmp(current_node->word, word) != 0) {
        current_node = current_node->next;
    }

    // Check if the word was found
    if (current_node == NULL) {
        printf("The word \"%s\" was not found in the dictionary.\n", word);
        return;
    }

    // Print a confirmation message
    printf("The word \"%s\" is spelled correctly.\n", word);
}

void free_dictionary(dictionary* dict) {
    // Free the memory allocated for the word nodes
    word_node* current_node = dict->head;
    while (current_node != NULL) {
        word_node* next_node = current_node->next;
        free(current_node->word);
        free(current_node);
        current_node = next_node;
    }

    // Free the memory allocated for the dictionary
    free(dict);
}