//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold data for each Creature
typedef struct Creature {
    int id;
    char name[30];
    char type[30];
    struct Creature* next;
} Creature;

// Function Declarations
void addCreature(Creature** head, int id, const char* name, const char* type);
void viewCreatures(Creature* head);
void deleteCreature(Creature** head, int id);
void freeCreatures(Creature* head);

int main() {
    Creature* head = NULL;
    int choice, id;
    char name[30], type[30];

    printf("Welcome to the Curious Creatures Database!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Creature\n");
        printf("2. View Creatures\n");
        printf("3. Delete Creature\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Creature ID: ");
                scanf("%d", &id);
                printf("Enter Creature Name: ");
                scanf("%s", name);
                printf("Enter Creature Type (e.g., Goblin, Elf): ");
                scanf("%s", type);
                addCreature(&head, id, name, type);
                printf("Creature added!\n");
                break;

            case 2:
                printf("Viewing all Creatures:\n");
                viewCreatures(head);
                break;

            case 3:
                printf("Enter Creature ID to delete: ");
                scanf("%d", &id);
                deleteCreature(&head, id);
                printf("Creature deleted if it existed!\n");
                break;

            case 4:
                printf("Exiting the database. Have a fantastic day!\n");
                freeCreatures(head);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a Creature to the database
void addCreature(Creature** head, int id, const char* name, const char* type) {
    Creature* newCreature = (Creature*)malloc(sizeof(Creature));
    newCreature->id = id;
    strcpy(newCreature->name, name);
    strcpy(newCreature->type, type);
    newCreature->next = *head;
    *head = newCreature;
}

// Function to view all Creatures in the database
void viewCreatures(Creature* head) {
    if (head == NULL) {
        printf("No creatures found in the database.\n");
        return;
    }

    Creature* current = head;
    printf("ID\tName\tType\n");
    printf("---------------------------\n");
    while (current != NULL) {
        printf("%d\t%s\t%s\n", current->id, current->name, current->type);
        current = current->next;
    }
}

// Function to delete a Creature from the database
void deleteCreature(Creature** head, int id) {
    Creature* current = *head;
    Creature* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Creature with ID %d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        *head = current->next; // The creature to delete is the head
    } else {
        previous->next = current->next; // Bypass the current creature
    }
    free(current); // Free the memory
}

// Function to free all Creatures in the linked list
void freeCreatures(Creature* head) {
    Creature* current = head;
    while (current != NULL) {
        Creature* next = current->next;
        free(current);
        current = next;
    }
}