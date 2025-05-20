//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CREATURES 100
#define NAME_LENGTH 50
#define SPECIES_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    char species[SPECIES_LENGTH];
    int age;
    float power_level;
} Creature;

Creature creature_db[MAX_CREATURES];
int creature_count = 0;

void add_creature() {
    if (creature_count >= MAX_CREATURES) {
        printf("Creature database is full! Cannot add more creatures.\n");
        return;
    }
    
    printf("Enter creature name: ");
    scanf("%s", creature_db[creature_count].name);
    
    printf("Enter creature species: ");
    scanf("%s", creature_db[creature_count].species);
    
    printf("Enter creature age: ");
    scanf("%d", &creature_db[creature_count].age);
    
    printf("Enter creature power level: ");
    scanf("%f", &creature_db[creature_count].power_level);
    
    creature_count++;
    printf("Creature added successfully!\n");
}

void list_creatures() {
    printf("\nCreatures in the database: \n");
    for (int i = 0; i < creature_count; i++) {
        printf("Creature %d: Name: %s, Species: %s, Age: %d, Power Level: %.2f\n", 
            i + 1, 
            creature_db[i].name, 
            creature_db[i].species, 
            creature_db[i].age, 
            creature_db[i].power_level);
    }
}

void search_creature() {
    char name[NAME_LENGTH];
    printf("Enter the name of the creature to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < creature_count; i++) {
        if (strcmp(creature_db[i].name, name) == 0) {
            printf("Creature found! Name: %s, Species: %s, Age: %d, Power Level: %.2f\n",
                creature_db[i].name, 
                creature_db[i].species, 
                creature_db[i].age, 
                creature_db[i].power_level);
            return;
        }
    }
    printf("Creature not found in the database.\n");
}

void delete_creature() {
    char name[NAME_LENGTH];
    printf("Enter the name of the creature to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < creature_count; i++) {
        if (strcmp(creature_db[i].name, name) == 0) {
            for (int j = i; j < creature_count - 1; j++) {
                creature_db[j] = creature_db[j + 1]; // Shift left
            }
            creature_count--;
            printf("Creature %s deleted successfully!\n", name);
            return;
        }
    }
    printf("Creature not found in the database.\n");
}

void display_menu() {
    printf("\n=== Fantasy Creature Database ===\n");
    printf("1. Add Creature\n");
    printf("2. List Creatures\n");
    printf("3. Search Creature\n");
    printf("4. Delete Creature\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_creature();
                break;
            case 2:
                list_creatures();
                break;
            case 3:
                search_creature();
                break;
            case 4:
                delete_creature();
                break;
            case 5:
                printf("Exiting the database. May your adventures be legendary!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}