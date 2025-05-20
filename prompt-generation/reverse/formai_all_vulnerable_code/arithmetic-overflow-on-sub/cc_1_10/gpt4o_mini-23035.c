//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int steps;
    float distance;
    int calories;
} User;

void initializeUser(User *user, const char *name) {
    strcpy(user->name, name);
    user->steps = 0;
    user->distance = 0.0f;
    user->calories = 0;
}

void walk(User *user, int steps) {
    user->steps += steps;
    user->distance += steps * 0.0008; // Average step to meters
    user->calories += steps * 0.05; // Average calories burnt
}

void displayStats(User user) {
    printf("Oh, noble %s!\n", user.name);
    printf("Thou hast walked %d steps!\n", user.steps);
    printf("Thou hast traversed a distance of %.2f kilometers.\n", user.distance);
    printf("Thou hast burned %d calories!\n", user.calories);
    printf("=========================================\n");
}

int main() {
    User romeo;
    User juliet;

    // Initialize our star-crossed lovers
    initializeUser(&romeo, "Romeo");
    initializeUser(&juliet, "Juliet");

    printf("Enter the steps taken by Romeo, fair youth, for love’s sake:\n");
    int stepsRomeo;
    scanf("%d", &stepsRomeo);
    walk(&romeo, stepsRomeo);
    
    printf("Alas! Enter the steps taken by Juliet, sweet lady of the night:\n");
    int stepsJuliet;
    scanf("%d", &stepsJuliet);
    walk(&juliet, stepsJuliet);

    printf("\nA tale of passion unfolds in the fitness realm...\n");
    displayStats(romeo);
    displayStats(juliet);

    // The cosmic bond of fitness
    if (romeo.steps > juliet.steps) {
        printf("Alas! Romeo hath walked more:\n");
        printf("His steps exceed thee by %d steps!\n", romeo.steps - juliet.steps);
    } else {
        printf("Oh, joyous Juliet hath triumphed in steps:\n");
        printf("Her steps exceed his by %d steps!\n", juliet.steps - romeo.steps);
    }

    // Question of distance
    if (romeo.distance > juliet.distance) {
        printf("Behold! Romeo hath traversed farther in the realm of meters!\n");
    } else {
        printf("Sweet Juliet walks the greater distance!\n");
    }

    // Calories burned
    printf("Oh lovers, thy fate entwined with the calories burned...\n");
    printf("Calories burned by Romeo: %d\n", romeo.calories);
    printf("Calories burned by Juliet: %d\n", juliet.calories);

    // Romantic choice based on fitness
    if (romeo.calories < juliet.calories) {
        printf("Juliet burns brighter in the furnace of calories!\n");
    } else {
        printf("Romeo wins with fervor in the burning calories of love!\n");
    }

    printf("As dawn breaks upon Verona, may these figures be a testament\nto love that flourishes through fitness!\n");
    return 0;
}