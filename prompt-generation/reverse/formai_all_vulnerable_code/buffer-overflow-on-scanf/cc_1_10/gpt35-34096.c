//FormAI DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Weapon {
    char name[25];
    int damage;
};

struct Knight {
    char name[25];
    int age;
    struct Weapon weapon;
};

void addNewKnight(struct Knight knights[], int *numKnights);
void deleteKnight(struct Knight knights[], int *numKnights);
void searchKnight(struct Knight knights[], int numKnights);
void displayAllKnights(struct Knight knights[], int numKnights);

int main() {
    struct Knight knights[100];
    int numKnights = 0;
    int choice;

    printf("Welcome to the Medieval Knight Database!\n\n");

    while(1) {
        printf("Enter 1 to add a new knight.\n");
        printf("Enter 2 to delete a knight.\n");
        printf("Enter 3 to search for a knight.\n");
        printf("Enter 4 to display all knights.\n");
        printf("Enter 0 to exit.\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addNewKnight(knights, &numKnights); break;
            case 2: deleteKnight(knights, &numKnights); break;
            case 3: searchKnight(knights, numKnights); break;
            case 4: displayAllKnights(knights, numKnights); break;
            case 0: exit(0);
            default: printf("Invalid choice. Try again.\n\n"); break;
        }
    }

    return 0;
}

void addNewKnight(struct Knight knights[], int *numKnights) {
    printf("\nAdding a new knight.\n");

    printf("Enter knight name: ");
    scanf("%s", knights[*numKnights].name);

    printf("Enter knight age: ");
    scanf("%d", &knights[*numKnights].age);

    printf("Enter weapon name: ");
    scanf("%s", knights[*numKnights].weapon.name);

    printf("Enter weapon damage: ");
    scanf("%d", &knights[*numKnights].weapon.damage);

    printf("\nKnight added successfully!\n\n");
    (*numKnights)++;
}

void deleteKnight(struct Knight knights[], int *numKnights) {
    printf("\nDeleting a knight.\n");

    printf("Enter knight name: ");
    char name[25];
    scanf("%s", name);

    int i;
    for(i=0; i<*numKnights; i++) {
        if(strcmp(name, knights[i].name) == 0) {
            (*numKnights)--;
            knights[i] = knights[*numKnights];
            printf("\nKnight deleted successfully!\n\n");
            return;
        }
    }

    printf("\nKnight not found. Try again.\n\n");
}

void searchKnight(struct Knight knights[], int numKnights) {
    printf("\nSearching for a knight.\n");

    printf("Enter knight name: ");
    char name[25];
    scanf("%s", name);

    int i;
    for(i=0; i<numKnights; i++) {
        if(strcmp(name, knights[i].name) == 0) {
            printf("\nKnight found!\n");
            printf("Name: %s\n", knights[i].name);
            printf("Age: %d\n", knights[i].age);
            printf("Weapon: %s\n", knights[i].weapon.name);
            printf("Damage: %d\n\n", knights[i].weapon.damage);
            return;
        }
    }

    printf("\nKnight not found. Try again.\n\n");
}

void displayAllKnights(struct Knight knights[], int numKnights) {
    printf("\nDisplaying all knights.\n");

    if(numKnights == 0) {
        printf("\nNo knights found.\n\n");
        return;
    }

    int i;
    for(i=0; i<numKnights; i++) {
        printf("Name: %s\n", knights[i].name);
        printf("Age: %d\n", knights[i].age);
        printf("Weapon: %s\n", knights[i].weapon.name);
        printf("Damage: %d\n\n", knights[i].weapon.damage);
    }
}