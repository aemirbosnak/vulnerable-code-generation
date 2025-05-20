//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 100

// Function declarations
void display_menu();
void add_word(char words[][MAX_WORD_LENGTH], int *count);
void search_word(char words[][MAX_WORD_LENGTH], int count);
void display_words(char words[][MAX_WORD_LENGTH], int count);
void delete_word(char words[][MAX_WORD_LENGTH], int *count);
void clear_input_buffer();

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count = 0;
    int choice;

    while(1) {
        display_menu();
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_word(words, &count);
                break;
            case 2:
                search_word(words, count);
                break;
            case 3:
                display_words(words, count);
                break;
            case 4:
                delete_word(words, &count);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n*** Word Management System ***\n");
    printf("1. Add a Word\n");
    printf("2. Search for a Word\n");
    printf("3. Display All Words\n");
    printf("4. Delete a Word\n");
    printf("5. Exit\n");
}

void add_word(char words[][MAX_WORD_LENGTH], int *count) {
    if (*count >= MAX_WORDS) {
        printf("Cannot add more words. Maximum limit reached.\n");
        return;
    }
    printf("Enter a word to add: ");
    fgets(words[*count], MAX_WORD_LENGTH, stdin);
    words[*count][strcspn(words[*count], "\n")] = 0; // Remove newline character
    (*count)++;
    printf("Word added successfully!\n");
}

void search_word(char words[][MAX_WORD_LENGTH], int count) {
    char search[MAX_WORD_LENGTH];
    printf("Enter the word to search: ");
    fgets(search, MAX_WORD_LENGTH, stdin);
    search[strcspn(search, "\n")] = 0; // Remove newline character

    for (int i = 0; i < count; i++) {
        if (strcmp(words[i], search) == 0) {
            printf("Word '%s' found in the list!\n", search);
            return;
        }
    }
    printf("Word '%s' not found in the list.\n", search);
}

void display_words(char words[][MAX_WORD_LENGTH], int count) {
    if (count == 0) {
        printf("No words to display.\n");
        return;
    }
    printf("Words List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, words[i]);
    }
}

void delete_word(char words[][MAX_WORD_LENGTH], int *count) {
    if (*count == 0) {
        printf("No words to delete.\n");
        return;
    }
    int index;
    printf("Enter the index of the word to delete (1 to %d): ", *count);
    scanf("%d", &index);
    clear_input_buffer();

    if (index < 1 || index > *count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        strcpy(words[i], words[i + 1]);
    }
    (*count)--;
    printf("Word deleted successfully!\n");
}

void clear_input_buffer() {
    while (getchar() != '\n'); // Clear the input buffer
}