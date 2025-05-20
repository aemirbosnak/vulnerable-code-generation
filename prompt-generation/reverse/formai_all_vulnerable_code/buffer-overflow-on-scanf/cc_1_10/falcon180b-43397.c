//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_ALIENS 20
#define MAX_ITEMS 30

typedef struct planet {
    char name[30];
    int population;
    int resources;
} planet_t;

typedef struct alien {
    char name[30];
    int strength;
    int intelligence;
} alien_t;

typedef struct item {
    char name[30];
    int value;
} item_t;

planet_t planets[MAX_PLANETS];
alien_t aliens[MAX_ALIENS];
item_t items[MAX_ITEMS];

void generate_planets() {
    int i;
    for (i = 0; i < MAX_PLANETS; i++) {
        planets[i].population = rand() % 1000 + 100;
        planets[i].resources = rand() % 1000 + 100;
        sprintf(planets[i].name, "Planet %d", i + 1);
    }
}

void generate_aliens() {
    int i;
    for (i = 0; i < MAX_ALIENS; i++) {
        aliens[i].strength = rand() % 100 + 1;
        aliens[i].intelligence = rand() % 100 + 1;
        sprintf(aliens[i].name, "Alien %d", i + 1);
    }
}

void generate_items() {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        items[i].value = rand() % 1000 + 1;
        sprintf(items[i].name, "Item %d", i + 1);
    }
}

int main() {
    srand(time(NULL));

    generate_planets();
    generate_aliens();
    generate_items();

    int choice;
    while (1) {
        printf("\n");
        printf("1. Explore a planet\n");
        printf("2. Encounter an alien\n");
        printf("3. Discover an item\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("You are exploring Planet %s.\n", planets[rand() % MAX_PLANETS].name);
            break;
        case 2:
            printf("You encounter Alien %s.\n", aliens[rand() % MAX_ALIENS].name);
            break;
        case 3:
            printf("You discover Item %s.\n", items[rand() % MAX_ITEMS].name);
            break;
        case 4:
            printf("Thank you for playing!\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}