//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_WORD_LEN 50
#define MAX_USERS 10
#define DICTIONARY_SIZE 1000

char *dictionary[DICTIONARY_SIZE]; // Sample dictionary
int word_count = 0;

// Function to read words into the dictionary
void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word) != EOF) {
        dictionary[word_count] = strdup(word);
        word_count++;
    }
    fclose(file);
}

// Function to check if a word is in the dictionary
int is_word_in_dictionary(const char *word) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Structure to hold user data
typedef struct {
    int user_id;
    char text[200];
    char errors[10][MAX_WORD_LEN]; // Stores misspelled words
    int error_count;
} UserData;

// Function for spell checking
void *spell_checker(void *arg) {
    UserData *user_data = (UserData *)arg;
    char *word;
    user_data->error_count = 0;

    // Break the user text into words
    word = strtok(user_data->text, " ");
    while (word != NULL) {
        // Normalize the word to lower case
        char normalized[MAX_WORD_LEN];
        int j = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            if (isalpha(word[i])) {
                normalized[j++] = tolower(word[i]);
            }
        }
        normalized[j] = '\0'; // Null-terminate the string

        // Check if the word is in the dictionary
        if (!is_word_in_dictionary(normalized)) {
            strcpy(user_data->errors[user_data->error_count], normalized);
            user_data->error_count++;
        }
        word = strtok(NULL, " ");
    }

    return NULL;
}

// Function to print errors
void print_errors(UserData *user_data) {
    printf("User %d: Misspelled words:\n", user_data->user_id);
    for (int i = 0; i < user_data->error_count; i++) {
        printf("%s\n", user_data->errors[i]);
    }
}

// Main function
int main() {
    // Load the dictionary from a file
    load_dictionary("dictionary.txt");

    pthread_t threads[MAX_USERS];
    UserData users[MAX_USERS];
    int user_count = 0, input;

    printf("Spell Checker Multiplayer Game!\n");
    printf("Enter the number of players (1-%d): ", MAX_USERS);
    scanf("%d", &user_count);
    getchar(); // Clear the newline from input

    for (int i = 0; i < user_count; i++) {
        users[i].user_id = i + 1;
        printf("User %d, enter your text: ", users[i].user_id);
        fgets(users[i].text, sizeof(users[i].text), stdin);
        users[i].text[strcspn(users[i].text, "\n")] = 0; // Remove newline

        // Create threads to check spelling
        pthread_create(&threads[i], NULL, spell_checker, &users[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < user_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results
    for (int i = 0; i < user_count; i++) {
        print_errors(&users[i]);
    }

    // Free allocated memory for the dictionary
    for (int i = 0; i < word_count; i++) {
        free(dictionary[i]);
    }

    return 0;
}