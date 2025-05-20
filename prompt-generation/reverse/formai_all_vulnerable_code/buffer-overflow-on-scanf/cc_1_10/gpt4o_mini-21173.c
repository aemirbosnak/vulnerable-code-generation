//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: medieval
#include <stdio.h>

// Proclaiming the purpose of this ancient script
void displayCastle(int height) {
    // The glorious height of the castle turrets
    for (int i = 0; i < height; i++) {
        // Drawing the roof of the turrets
        for (int j = height; j > i; j--) {
            printf(" ");
        }
        printf("*");
        for (int j = 0; j < (i * 2); j++) {
            printf(" ");
        }
        printf("*\n");
    }

    // Now let us forge the strong walls of the castle
    for (int i = 0; i < height; i++) {
        // Drawing the left wall
        for (int j = height; j > 0; j--) {
            printf(" ");
        }
        printf("*");
        for (int j = 0; j < (height * 2 - 2); j++) {
            printf(" ");
        }
        printf("*\n");
    }

    // The foundation of the castle, a grand barricade!
    for (int i = 0; i < (height * 2); i++) {
        printf("*");
    }
    printf("\n");
}

// A mighty quest to bring forth the great castle pattern
int main() {
    // Specify the height of the castle
    int towerHeight;

    printf("Enter the height of thy castle (3 or more): ");
    scanf("%d", &towerHeight);

    // Ensuring the height is fit for a noble castle
    if (towerHeight < 3) {
        printf("The height of a castle must not be below 3! \n");
        return 1;
    }

    // Behold! The castle shall appear!
    printf("\nBehold the mighty castle!\n\n");
    displayCastle(towerHeight);

    // Farewell message from the scribe
    printf("\nLet this castle stand tall in the annals of yer coding journey!\n");
    return 0;
}