//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Case {
    char title[100];
    char description[256];
    struct Case* next;
} Case;

Case* head = NULL;

// Function declarations
void addCase();
void displayCases();
void deleteCase();
void findCase();
void printMenu();

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCase();
                break;
            case 2:
                displayCases();
                break;
            case 3:
                deleteCase();
                break;
            case 4:
                findCase();
                break;
            case 5:
                printf("Elementary, my dear Watson. Exiting.\n");
                exit(0);
            default:
                printf("I daresay, that is not a valid option!\n");
        }
    }

    return 0;
}

void printMenu() {
    printf("\n-- Sherlock Holmes Case Management --\n");
    printf("1. Add a new case\n");
    printf("2. Display all cases\n");
    printf("3. Delete a case\n");
    printf("4. Find a case by title\n");
    printf("5. Exit\n");
}

void addCase() {
    Case* newCase = (Case*)malloc(sizeof(Case));
    if (!newCase) {
        printf("Alas, we have encountered a problem. Memory allocation failed!\n");
        return;
    }

    printf("Enter the case title: ");
    getchar(); // Clear the newline character
    fgets(newCase->title, sizeof(newCase->title), stdin);
    newCase->title[strcspn(newCase->title, "\n")] = '\0'; // Remove newline character

    printf("Enter the case description: ");
    fgets(newCase->description, sizeof(newCase->description), stdin);
    newCase->description[strcspn(newCase->description, "\n")] = '\0'; // Remove newline character

    newCase->next = head;
    head = newCase;

    printf("The case '%s' has been recorded in the annals of your memory, Watson.\n", newCase->title);
}

void displayCases() {
    Case* current = head;
    if (!current) {
        printf("There are currently no cases to display, Watson.\n");
        return;
    }

    printf("\n-- List of Cases --\n");
    while (current) {
        printf("Title: %s\n", current->title);
        printf("Description: %s\n\n", current->description);
        current = current->next;
    }
}

void deleteCase() {
    char title[100];
    printf("Enter the title of the case to delete: ");
    getchar(); // Clear the newline character
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline character

    Case *current = head, *previous = NULL;

    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("The case '%s' is not found in our records, Watson.\n", title);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Case is at the head
    } else {
        previous->next = current->next; // Bypass the current
    }

    free(current);
    printf("The case '%s' has been removed from the records.\n", title);
}

void findCase() {
    char title[100];
    printf("Enter the title of the case to find: ");
    getchar(); // Clear the newline character
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove newline character

    Case* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("Found Case:\nTitle: %s\nDescription: %s\n", current->title, current->description);
            return;
        }
        current = current->next;
    }
    printf("Regretfully, the case '%s' cannot be found in our records, Watson.\n", title);
}