//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOVERS 10

typedef struct Lover {
    char name[50];
    int age;
    struct Lover *next;
} Lover;

Lover *lovers = NULL;

void addLover(char *name, int age) {
    Lover *newLover = (Lover *) malloc(sizeof(Lover));
    strcpy(newLover->name, name);
    newLover->age = age;
    newLover->next = lovers;
    lovers = newLover;
}

void displayLovers() {
    Lover *current = lovers;
    printf("\nMy beloved lovers:\n");
    while (current != NULL) {
        printf("%s (%d years old)\n", current->name, current->age);
        current = current->next;
    }
}

void freeLovers() {
    Lover *current = lovers;
    Lover *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    lovers = NULL;
}

int main() {
    int choice, age;
    char name[50];

    while (1) {
        printf("\n1. Add a new lover\n");
        printf("2. Display my lovers\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of your lover: ");
                scanf("%s", name);
                printf("Enter the age of your lover: ");
                scanf("%d", &age);
                addLover(name, age);
                break;

            case 2:
                displayLovers();
                break;

            case 3:
                freeLovers();
                printf("\nGoodbye, my love! :(\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}