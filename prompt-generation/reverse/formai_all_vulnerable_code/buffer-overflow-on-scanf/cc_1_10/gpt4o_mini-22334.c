//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTITIES 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int resources; // Amount of resources owned
    int health;    // Health status of the entity
} Survivor;

Survivor survivors[MAX_ENTITIES];
int survivor_count = 0;

void add_survivor(char* name, int resources, int health) {
    if (survivor_count < MAX_ENTITIES) {
        survivors[survivor_count].id = survivor_count + 1;
        strncpy(survivors[survivor_count].name, name, NAME_LENGTH);
        survivors[survivor_count].resources = resources;
        survivors[survivor_count].health = health;
        survivor_count++;
    } else {
        printf("Unable to add more survivors. Max capacity reached!\n");
    }
}

void display_survivors() {
    if (survivor_count == 0) {
        printf("No survivors yet. The wasteland feels empty.\n");
        return;
    }
    
    printf("Survivors in the Wasteland:\n");
    for (int i = 0; i < survivor_count; i++) {
        printf("ID: %d | Name: %s | Resources: %d | Health: %d\n", 
               survivors[i].id, survivors[i].name, 
               survivors[i].resources, survivors[i].health);
    }
}

void update_health(int id, int new_health) {
    for (int i = 0; i < survivor_count; i++) {
        if (survivors[i].id == id) {
            survivors[i].health = new_health;
            printf("Health of %s updated to %d.\n", survivors[i].name, new_health);
            return;
        }
    }
    printf("Survivor with ID %d not found.\n", id);
}

void gather_resources(int id, int amount) {
    for (int i = 0; i < survivor_count; i++) {
        if (survivors[i].id == id) {
            survivors[i].resources += amount;
            printf("%s gathered %d resources. Total: %d\n", 
                   survivors[i].name, amount, survivors[i].resources);
            return;
        }
    }
    printf("Survivor with ID %d not found.\n", id);
}

void simulate_day() {
    for (int i = 0; i < survivor_count; i++) {
        int health_change = rand() % 5 - 2; // Random health change (-2, -1, 0, 1, 2)
        survivors[i].health += health_change;
        if (survivors[i].health < 0) survivors[i].health = 0;
        printf("At the end of the day, %s's health is now %d.\n", 
               survivors[i].name, survivors[i].health);
    }
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    int resources, health, id, amount;

    printf("Welcome to the Wasteland Survivor Database!\n");

    while (1) {
        printf("\n1. Add Survivor\n2. Display Survivors\n3. Update Health\n4. Gather Resources\n5. Simulate Day\n6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Survivor Name: ");
                scanf("%s", name);
                printf("Enter Resources: ");
                scanf("%d", &resources);
                printf("Enter Health: ");
                scanf("%d", &health);
                add_survivor(name, resources, health);
                break;
            case 2:
                display_survivors();
                break;
            case 3:
                printf("Enter Survivor ID: ");
                scanf("%d", &id);
                printf("Enter New Health: ");
                scanf("%d", &health);
                update_health(id, health);
                break;
            case 4:
                printf("Enter Survivor ID: ");
                scanf("%d", &id);
                printf("Enter Resources to Gather: ");
                scanf("%d", &amount);
                gather_resources(id, amount);
                break;
            case 5:
                simulate_day();
                break;
            case 6:
                printf("Fading into the wasteland... until next time.\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}