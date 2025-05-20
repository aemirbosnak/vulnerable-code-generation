//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed
    
    int invasionProbability = 0;
    int alienStrength = 0;
    char alienType[20];
    char playerName[20];
    
    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("Hello %s, let's determine the probability of an alien invasion.\n", playerName);
    
    printf("Please select the type of alien:\n1. Zorgon\n2. Xentron\n3. Vaygar\n");
    int alienChoice = 0;
    scanf("%d", &alienChoice);
    switch (alienChoice) {
        case 1:
            invasionProbability += 5;
            alienStrength = 3;
            strcpy(alienType, "Zorgon");
            break;
        case 2:
            invasionProbability += 10;
            alienStrength = 5;
            strcpy(alienType, "Xentron");
            break;
        case 3:
            invasionProbability += 15;
            alienStrength = 7;
            strcpy(alienType, "Vaygar");
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }
    
    printf("Please select the month:\n1. January\n2. February\n3. March\n4. April\n5. May\n6. June\n7. July\n8. August\n9. September\n10. October\n11. November\n12. December\n");
    int monthChoice = 0;
    scanf("%d", &monthChoice);
    if (monthChoice >= 1 && monthChoice <= 4) {
        invasionProbability += 10;
    } else if (monthChoice >= 5 && monthChoice <= 10) {
        invasionProbability += 20;
    } else if (monthChoice >= 11 && monthChoice <= 12) {
        invasionProbability += 5;
    } else {
        printf("Invalid choice.\n");
        return 1;
    }
    
    printf("Please enter your age: ");
    int age = 0;
    scanf("%d", &age);
    if (age >= 18 && age <= 30) {
        invasionProbability += 10;
    } else if (age >= 31 && age <= 50) {
        invasionProbability += 5;
    } else if (age >= 51) {
        invasionProbability += 2;
    }
    
    printf("Please choose your favorite color:\n1. Red\n2. Blue\n3. Green\n4. Yellow\n5. Purple\n6. Orange\n7. Black\n8. White\n");
    int colorChoice = 0;
    scanf("%d", &colorChoice);
    if (colorChoice == 1 || colorChoice == 5) {
        invasionProbability += 5;
    } else if (colorChoice == 2 || colorChoice == 3) {
        invasionProbability += 10;
    } else if (colorChoice == 6 || colorChoice == 7) {
        invasionProbability += 2;
    } else if (colorChoice == 4 || colorChoice == 8) {
        invasionProbability += 1;
    } else {
        printf("Invalid choice.\n");
        return 1;
    }
    
    printf("Please enter your shoe size: ");
    float shoeSize = 0.0;
    scanf("%f", &shoeSize);
    if (shoeSize >= 7.5 && shoeSize <= 10.5) {
        invasionProbability += 5;
    } else if (shoeSize > 10.5) {
        invasionProbability += 10;
    }
    
    printf("Calculating probability...\n");
    int randomNum = rand() % 10 + 1;
    invasionProbability -= randomNum;
    if (invasionProbability < 0) {
        invasionProbability = 0;
    }
    
    printf("The probability of an %s invasion with a strength of %d in the month of %d is %d%%\n", alienType, alienStrength, monthChoice, invasionProbability);
    if (invasionProbability < 25) {
        printf("It appears that you are safe from the %s invasion, %s.\n", alienType, playerName);
    } else if (invasionProbability >= 25 && invasionProbability < 75) {
        printf("There is a moderate chance of an %s invasion, %s. Be prepared.\n", alienType, playerName);
    } else if (invasionProbability >= 75) {
        printf("There is a high probability of an %s invasion with a strength of %d, %s. Seek shelter immediately.\n", alienType, alienStrength, playerName);
    }
    
    return 0;
}