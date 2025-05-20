//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a magical creature
typedef struct Creature {
    char name[30];
    int powerLevel;
    struct Creature* next;
} Creature;

// Function to create a new creature node
Creature* createCreature(char* name, int powerLevel) {
    Creature* newCreature = (Creature*)malloc(sizeof(Creature));
    strcpy(newCreature->name, name);
    newCreature->powerLevel = powerLevel;
    newCreature->next = NULL;
    return newCreature;
}

// Function to insert a creature at the end of the list
void insertCreature(Creature** head, char* name, int powerLevel) {
    Creature* newCreature = createCreature(name, powerLevel);
    if (*head == NULL) {
        *head = newCreature;
        return;
    }
    Creature* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newCreature;
}

// Function to delete a creature by name
void deleteCreature(Creature** head, char* name) {
    Creature* temp = *head;
    Creature* prev = NULL;
    
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Creature %s not found!\n", name);
        return;
    }
    
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    
    free(temp);
    printf("Creature %s has been vanquished!\n", name);
}

// Function to display all creatures
void displayCreatures(Creature* head) {
    if (head == NULL) {
        printf("No magical creatures in your realm.\n");
        return;
    }
    
    printf("Creatures in your realm:\n");
    Creature* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Power Level: %d\n", temp->name, temp->powerLevel);
        temp = temp->next;
    }
}

// Function to free all creatures
void freeCreatures(Creature* head) {
    Creature* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Creature* myRealm = NULL;
    int choice;
    char name[30];
    int powerLevel;

    printf("Welcome to the Realm of Magical Creatures!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add Creature\n");
        printf("2. Remove Creature\n");
        printf("3. Display Creatures\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter creature name: ");
                scanf("%s", name);
                printf("Enter creature's power level: ");
                scanf("%d", &powerLevel);
                insertCreature(&myRealm, name, powerLevel);
                printf("Creature %s added with power level %d!\n", name, powerLevel);
                break;
            case 2:
                printf("Enter the name of the creature to remove: ");
                scanf("%s", name);
                deleteCreature(&myRealm, name);
                break;
            case 3:
                displayCreatures(myRealm);
                break;
            case 4:
                printf("Leaving the realm. Until next time!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 4);

    freeCreatures(myRealm);
    return 0;
}