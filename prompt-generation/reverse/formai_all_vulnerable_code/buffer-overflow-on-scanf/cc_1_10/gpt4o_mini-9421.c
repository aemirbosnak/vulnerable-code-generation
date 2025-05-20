//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_OCCUPATION_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char occupation[MAX_OCCUPATION_LENGTH];
    int age;
} Villager;

Villager villagers[MAX_ENTRIES];
int villager_count = 0;

void add_villager() {
    if (villager_count >= MAX_ENTRIES) {
        printf("Thy village is full! Cannot add more villagers.\n");
        return;
    }
    
    Villager new_vil;
    new_vil.id = villager_count + 1;
    
    printf("Enter the name of the villager: ");
    scanf("%s", new_vil.name);
    
    printf("Enter the occupation of the villager: ");
    scanf("%s", new_vil.occupation);
    
    printf("Enter the age of the villager: ");
    scanf("%d", &new_vil.age);
    
    villagers[villager_count] = new_vil;
    villager_count++;
    printf("Huzzah! The villager hath been added to the records.\n");
}

void view_villagers() {
    printf("\n--- List of Villagers ---\n");
    for (int i = 0; i < villager_count; i++) {
        printf("ID: %d, Name: %s, Occupation: %s, Age: %d\n",
               villagers[i].id,
               villagers[i].name,
               villagers[i].occupation,
               villagers[i].age);
    }
    printf("-------------------------\n");
}

void search_villager() {
    char name_to_search[MAX_NAME_LENGTH];
    printf("Enter the name of the villager to search: ");
    scanf("%s", name_to_search);
    
    int found = 0;
    for (int i = 0; i < villager_count; i++) {
        if (strcmp(villagers[i].name, name_to_search) == 0) {
            printf("Villager Found: ID: %d, Name: %s, Occupation: %s, Age: %d\n",
                   villagers[i].id,
                   villagers[i].name,
                   villagers[i].occupation,
                   villagers[i].age);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Alas! No villager by the name of %s dost exist in our village.\n", name_to_search);
    }
}

void remove_villager() {
    int id_to_remove;
    printf("Enter the ID of the villager to remove: ");
    scanf("%d", &id_to_remove);
    
    if (id_to_remove < 1 || id_to_remove > villager_count) {
        printf("Thy request is most unreasonable! No villager exists with that ID.\n");
        return;
    }

    for (int i = id_to_remove - 1; i < villager_count - 1; i++) {
        villagers[i] = villagers[i + 1];
    }
    
    villager_count--;
    printf("The villager hath been banished from the records.\n");
}

void show_menu() {
    printf("\n--- The Village Record Keeper ---\n");
    printf("1. Add Villager\n");
    printf("2. View Villagers\n");
    printf("3. Search for Villager\n");
    printf("4. Remove Villager\n");
    printf("5. Exit\n");
    printf("Choose thine option: ");
}

int main() {
    int choice;
    
    while (1) {
        show_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_villager();
                break;
            case 2:
                view_villagers();
                break;
            case 3:
                search_villager();
                break;
            case 4:
                remove_villager();
                break;
            case 5:
                printf("Farewell, noble keeper of records!\n");
                exit(0);
            default:
                printf("Thy choice is unclear. Please select again.\n");
        }
    }
    
    return 0;
}