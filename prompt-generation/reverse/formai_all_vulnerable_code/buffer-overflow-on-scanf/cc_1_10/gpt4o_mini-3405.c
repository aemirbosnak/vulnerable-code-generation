//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Creature {
    char name[50];
    int powerLevel;
    struct Creature *next;
} Creature;

Creature* createCreature(const char *name, int powerLevel) {
    Creature* newCreature = (Creature*)malloc(sizeof(Creature));
    strcpy(newCreature->name, name);
    newCreature->powerLevel = powerLevel;
    newCreature->next = NULL;
    return newCreature;
}

void addCreature(Creature **head, const char *name, int powerLevel) {
    Creature *newCreature = createCreature(name, powerLevel);
    if (*head == NULL) {
        *head = newCreature;
    } else {
        Creature *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCreature;
    }
    printf("A new creature named %s with power level %d has entered the realm!\n", name, powerLevel);
}

void displayCreatures(Creature *head) {
    if (head == NULL) {
        printf("The realm is empty; there are no creatures to display.\n");
        return;
    }
    printf("Creatures in the realm:\n");
    Creature *temp = head;
    while (temp != NULL) {
        printf("Creature Name: %s, Power Level: %d\n", temp->name, temp->powerLevel);
        temp = temp->next;
    }
}

void deleteCreature(Creature **head, const char *name) {
    if (*head == NULL) {
        printf("The realm is devoid of creatures. Cannot delete.\n");
        return;
    }

    Creature *temp = *head, *prev = NULL;

    if (strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
        printf("%s has been banished from the realm!\n", name);
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("No creature named %s found in the realm.\n", name);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("%s has been banished from the realm!\n", name);
}

void freeCreatures(Creature *head) {
    Creature *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Creature *creatures = NULL;
    int choice;
    char name[50];
    int powerLevel;

    do {
        printf("\n--- Welcome to the Realm of Mystical Creatures ---\n");
        printf("1. Add a creature\n");
        printf("2. Display creatures\n");
        printf("3. Banish a creature\n");
        printf("4. Exit\n");
        printf("Choose your action: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter the creature's name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter the creature's power level: ");
                scanf("%d", &powerLevel);
                addCreature(&creatures, name, powerLevel);
                break;
            case 2:
                displayCreatures(creatures);
                break;
            case 3:
                printf("Enter the name of the creature to banish: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                deleteCreature(&creatures, name);
                break;
            case 4:
                printf("Exiting the realm, all creatures will be set free...\n");
                freeCreatures(creatures);
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}