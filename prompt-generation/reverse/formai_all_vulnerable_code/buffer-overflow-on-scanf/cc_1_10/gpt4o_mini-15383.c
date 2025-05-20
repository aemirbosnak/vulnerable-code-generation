//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Character structure for the cases
typedef struct {
    char name[50];
    char role[50];
} Character;

// Function to add characters
void addCharacter(Character **characters, int *size) {
    printf("Enter character name: ");
    char name[50];
    getchar(); // To clear the newline from the buffer
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    printf("Enter character role: ");
    char role[50];
    fgets(role, 50, stdin);
    role[strcspn(role, "\n")] = 0; // Remove newline character

    // Reallocate memory for new character
    *characters = realloc(*characters, (*size + 1) * sizeof(Character));
    if (*characters == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Setting character details
    strcpy((*characters)[*size].name, name);
    strcpy((*characters)[*size].role, role);
    (*size)++;
    printf("Character added successfully!\n");
}

// Function to search for a character
void searchCharacter(Character *characters, int size) {
    printf("Enter character name to search: ");
    char name[50];
    getchar(); // To clear the newline from the buffer
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    for (int i = 0; i < size; i++) {
        if (strcmp(characters[i].name, name) == 0) {
            printf("Character Found: %s, Role: %s\n", characters[i].name, characters[i].role);
            return;
        }
    }
    printf("Character not found in the database.\n");
}

// Function to clean up allocated memory
void cleanup(Character *characters) {
    free(characters);
    printf("Memory cleaned up successfully.\n");
}

int main() {
    Character *characters = NULL;
    int size = 0;
    int choice;

    printf("Welcome to the Case of the Missing Characters!\n");

    do {
        printf("\n1. Add Character\n2. Search Character\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCharacter(&characters, &size);
                break;
            case 2:
                searchCharacter(characters, size);
                break;
            case 3:
                printf("Exiting program. ");
                cleanup(characters);
                return 0;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 3);

    cleanup(characters);
    return 0;
}