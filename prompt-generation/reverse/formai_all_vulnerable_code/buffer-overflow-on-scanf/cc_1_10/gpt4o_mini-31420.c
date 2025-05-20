//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 100
#define MAX_FRUITS 10
#define FRUIT_NAME_LENGTH 20

typedef struct {
    char name[FRUIT_NAME_LENGTH];
    int count;
} Fruit;

void initializeFruits(Fruit fruits[], int *fruitCount) {
    strcpy(fruits[0].name, "Apple");
    strcpy(fruits[1].name, "Banana");
    strcpy(fruits[2].name, "Cherry");
    strcpy(fruits[3].name, "Date");
    strcpy(fruits[4].name, "Elderberry");
    *fruitCount = 5; // We have 5 fruits
    for (int i = 0; i < *fruitCount; i++) {
        fruits[i].count = 0; // Initial count is 0
    }
}

void collectData(Fruit fruits[], int fruitCount) {
    char name[FRUIT_NAME_LENGTH];
    int choice;

    printf("🎉 Welcome to the Fruit Preference Survey! 🍏🍌🍒\n");
    printf("We have the following fruits for you to choose from:\n");
    
    for (int i = 0; i < fruitCount; i++) {
        printf("%d. %s\n", i + 1, fruits[i].name);
    }

    printf("How many people would you like to survey? ");
    int peopleCount;
    scanf("%d", &peopleCount);

    for (int i = 0; i < peopleCount; i++) {
        printf("Person %d, please enter your favorite fruit number (1-%d): ", i + 1, fruitCount);
        scanf("%d", &choice);
        
        if (choice < 1 || choice > fruitCount) {
            printf("Oops! That's not a valid choice. Please select a number between 1 and %d.\n", fruitCount);
            i--; // Repeat this iteration
        } else {
            fruits[choice - 1].count++; // Increment the count for the selected fruit
            printf("Thank you! You chose %s. 🥳\n", fruits[choice - 1].name);
        }
    }
}

void displayResults(Fruit fruits[], int fruitCount) {
    printf("\n🌟 Fruit Preference Results 🌟\n");
    printf("---------------------------------\n");
    
    for (int i = 0; i < fruitCount; i++) {
        printf("%s: %d votes\n", fruits[i].name, fruits[i].count);
    }

    printf("\n✨ Thank you for participating! Enjoy your day! ✨\n");
}

int main() {
    Fruit fruits[MAX_FRUITS];
    int fruitCount;

    // Initialize fruits
    initializeFruits(fruits, &fruitCount);

    // Collect data from participants
    collectData(fruits, fruitCount);

    // Display the collected results
    displayResults(fruits, fruitCount);

    return 0;
}