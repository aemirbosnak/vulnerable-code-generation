//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_SIZE 10

typedef struct WordCount {
    char *word;
    int count;
    struct WordCount *next;
} WordCount;

// Function prototypes
WordCount* create_word_count(const char *word);
void add_word_count(WordCount **head, const char *word);
void free_word_count_list(WordCount *head);
void print_word_counts(WordCount *head);
void to_lower_case(char *word);
int is_end_of_word(char c);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordCount *head = NULL;
    char word[MAX_WORD_LENGTH];
    int index = 0;

    while (fscanf(file, "%s", word) != EOF) {
        to_lower_case(word);
        // Add word to the linked list or update its count
        add_word_count(&head, word);
    }

    fclose(file);
    
    // Print the word counts
    print_word_counts(head);
    free_word_count_list(head);
    
    return EXIT_SUCCESS;
}

WordCount* create_word_count(const char *word) {
    WordCount *new_word = malloc(sizeof(WordCount));
    if (!new_word) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    new_word->word = malloc(strlen(word) + 1);
    if (!new_word->word) {
        perror("Memory allocation failed");
        free(new_word);
        exit(EXIT_FAILURE);
    }
    
    strcpy(new_word->word, word);
    new_word->count = 1;
    new_word->next = NULL;
    
    return new_word;
}

void add_word_count(WordCount **head, const char *word) {
    WordCount *current = *head;
    WordCount *previous = NULL;
    
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        
        previous = current;
        current = current->next;
    }

    WordCount *new_word = create_word_count(word);
    if (previous == NULL) {
        *head = new_word; // Insert at the head
    } else {
        previous->next = new_word; // Insert at the end
    }
}

void print_word_counts(WordCount *head) {
    WordCount *current = head;
    printf("\nWord Frequency Count:\n");
    printf("========================\n");
    
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

void free_word_count_list(WordCount *head) {
    WordCount *temp;
    
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->word);
        free(temp);
    }
}

void to_lower_case(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower((unsigned char)word[i]);
    }
}

int is_end_of_word(char c) {
    return isspace(c) || ispunct(c) || c == '\0';
}