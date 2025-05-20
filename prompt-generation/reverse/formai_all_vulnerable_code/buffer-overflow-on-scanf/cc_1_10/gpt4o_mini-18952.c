//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENCOUNTERS 3
#define MAX_RESOURCE 5

typedef struct {
    char name[30];
    int resources;
} Alien;

const char* planets[] = {
    "Zargoth",
    "Pellon",
    "Xeridia",
    "Glaxia",
    "Briargoon"
};

void printWelcome() {
    printf("Welcome to the Galaxy Exploration Adventure!\n");
    printf("In this game, you'll navigate through various planets,\n");
    printf("encounter alien species, and try to collect resources.\n\n");
}

void randomizeAlien(Alien *alien) {
    const char* names[] = {"Zylox", "Morfak", "Eldraal", "Treek", "Shinyo"};
    strcpy(alien->name, names[rand() % 5]);
    alien->resources = rand() % MAX_RESOURCE + 1; // Resource between 1 and 5
}

void explorePlanet() {
    int choice;
    Alien alien;
    int total_resources = 0;
    
    for (int i = 0; i < MAX_ENCOUNTERS; i++) {
        printf("\nYou arrive at the planet %s.\n", planets[rand() % 5]);
        randomizeAlien(&alien);
        printf("You encounter a friendly alien named %s!\n", alien.name);
        printf("It offers you %d resources. Do you want to accept them?\n", alien.resources);
        
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            total_resources += alien.resources;
            printf("You accepted the resources! Total resources: %d\n", total_resources);
        } else {
            printf("You declined the resources.\n");
        }
        
        if (total_resources >= MAX_RESOURCE) {
            printf("Congratulations! You've collected the maximum resources.\n");
            break;
        }
    }
    
    printf("\nYour adventure ends now. You collected a total of %d resources.\n", total_resources);
}

int main() {
    srand(time(NULL));
    printWelcome();
    
    char choice;
    do {
        explorePlanet();
        
        printf("Would you like to explore another planet? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');
    
    printf("Thank you for playing! Safe travels in the galaxy!\n");
    return 0;
}