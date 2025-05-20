//GPT-4o-mini DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FLOWERS 10
#define MAX_CREATURES 5
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int happinessLevel;
} Creature;

typedef struct {
    char name[MAX_NAME_LEN];
    int collected;
    int rarity;
} Flower;

void initCreatures(Creature* creatures) {
    strcpy(creatures[0].name, "Buzzy Bee");
    creatures[0].happinessLevel = rand() % 100;
    
    strcpy(creatures[1].name, "Playful Puppy");
    creatures[1].happinessLevel = rand() % 100;

    strcpy(creatures[2].name, "Chatty Parrot");
    creatures[2].happinessLevel = rand() % 100;

    strcpy(creatures[3].name, "Happy Bunny");
    creatures[3].happinessLevel = rand() % 100;

    strcpy(creatures[4].name, "Curious Cat");
    creatures[4].happinessLevel = rand() % 100;
}

void initFlowers(Flower* flowers) {
    strcpy(flowers[0].name, "Sunny Sunflower");
    flowers[0].collected = 0;
    flowers[0].rarity = 1;

    strcpy(flowers[1].name, "Beautiful Rose");
    flowers[1].collected = 0;
    flowers[1].rarity = 2;

    strcpy(flowers[2].name, "Lovely Lily");
    flowers[2].collected = 0;
    flowers[2].rarity = 3;

    strcpy(flowers[3].name, "Cheerful Daisy");
    flowers[3].collected = 0;
    flowers[3].rarity = 1;

    strcpy(flowers[4].name, "Exotic Orchid");
    flowers[4].collected = 0;
    flowers[4].rarity = 4;
}

void exploreGarden(Creature* creatures, Flower* flowers, int* flowerCount) {
    int choice;
    printf("You wander into the garden and feel a sense of wonder!\n");
    printf("1. Collect Flowers\n");
    printf("2. Meet Creatures\n");
    printf("3. Leave the garden\n");
    printf("Choose an option (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (*flowerCount < MAX_FLOWERS) {
                int flowerIndex = rand() % MAX_FLOWERS;
                flowers[flowerIndex].collected++;
                (*flowerCount)++;
                printf("Hooray! You collected a %s! Total collected: %d\n", 
                       flowers[flowerIndex].name, flowers[flowerIndex].collected);
            } else {
                printf("You have collected all the flowers! Time to enjoy the view!\n");
            }
            break;
        case 2:
            for (int i = 0; i < MAX_CREATURES; i++) {
                printf("%d. %s (Happiness Level: %d)\n", i + 1, creatures[i].name, creatures[i].happinessLevel);
            }
            break;
        case 3:
            printf("You decide to leave the garden. Come back soon!\n");
            break;
        default:
            printf("Invalid choice. Please try again!\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    Creature creatures[MAX_CREATURES];
    Flower flowers[MAX_FLOWERS];
    int flowerCount = 0;

    initCreatures(creatures);
    initFlowers(flowers);

    int running = 1;
    while (running) {
        exploreGarden(creatures, flowers, &flowerCount);
        
        char continueGame;
        printf("Do you want to continue exploring? (y/n): ");
        scanf(" %c", &continueGame);
        if (continueGame == 'n' || continueGame == 'N') {
            running = 0;
        }
    }

    printf("Thank you for visiting the garden! Goodbye!\n");
    return 0;
}