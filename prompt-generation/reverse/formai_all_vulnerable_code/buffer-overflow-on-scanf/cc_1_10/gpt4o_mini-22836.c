//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Creature {
    char name[50];
    struct Creature* next;
};

struct Creature* head = NULL;

// Function to create a new creature
struct Creature* createCreature(const char* name) {
    struct Creature* newCreature = (struct Creature*)malloc(sizeof(struct Creature));
    if (newCreature == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newCreature->name, name);
    newCreature->next = NULL;
    return newCreature;
}

// Function to add a creature to the end of the list
void addCreature(const char* name) {
    struct Creature* newCreature = createCreature(name);
    if (head == NULL) {
        head = newCreature;
    } else {
        struct Creature* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCreature;
    }
    printf("Creature '%s' has been added to the realm!\n", name);
}

// Function to display all creatures
void displayCreatures() {
    if (head == NULL) {
        printf("There are no creatures in the realm.\n");
        return;
    }

    struct Creature* temp = head;
    printf("Creatures in the realm:\n");
    while (temp != NULL) {
        printf("- %s\n", temp->name);
        temp = temp->next;
    }
}

// Function to remove a creature by name
void removeCreature(const char* name) {
    if (head == NULL) {
        printf("No creatures to remove.\n");
        return;
    }
    
    struct Creature* temp = head;
    struct Creature* prev = NULL;

    // Check if the head needs to be removed
    if (strcmp(temp->name, name) == 0) {
        head = temp->next; // Move head to next creature
        free(temp);
        printf("Creature '%s' has been vanquished from the realm!\n", name);
        return;
    }
    
    // Search for the creature to be removed
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Creature '%s' not found in the realm.\n", name);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Creature '%s' has been vanquished from the realm!\n", name);
}

// Function to free all creatures in the list
void freeCreatures() {
    struct Creature* temp = head;
    while (temp != NULL) {
        struct Creature* nextCreature = temp->next;
        free(temp);
        temp = nextCreature;
    }
    head = NULL;
    printf("The realm has been cleared of all creatures.\n");
}

int main() {
    int choice;
    char name[50];
    
    while (1) {
        printf("\n--- Mythical Creatures Realm ---\n");
        printf("1. Add Creature\n");
        printf("2. Display Creatures\n");
        printf("3. Remove Creature\n");
        printf("4. Clear Realm\n");
        printf("5. Exit\n");
        printf("Choose an action: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character
        
        switch (choice) {
            case 1:
                printf("Enter the name of the creature: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline
                addCreature(name);
                break;
            case 2:
                displayCreatures();
                break;
            case 3:
                printf("Enter the name of the creature to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; 
                removeCreature(name);
                break;
            case 4:
                freeCreatures();
                break;
            case 5:
                freeCreatures();
                printf("Exiting the realm. Until next time!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    
    return 0;
}