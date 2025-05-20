//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int steps;
    float distance; // in kilometers
    int calories; // burned
    char date[11]; // format: YYYY-MM-DD
} Profile;

void displayProfile(Profile p) {
    printf("Oh, fair Profile of %s:\n", p.name);
    printf("   Steps taken: %d\n", p.steps);
    printf("   Distance traveled: %.2f km\n", p.distance);
    printf("   Calories burned: %d\n", p.calories);
    printf("   Date of record: %s\n", p.date);
}

void updateSteps(Profile *p, int newSteps) {
    p->steps += newSteps;
    p->distance += newSteps * 0.0008; // assuming each step is roughly 0.8 meters
    p->calories += newSteps * 0.05; // assuming 0.05 calories burned per step
}

void recordDate(Profile *p) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(p->date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

int main() {
    Profile romeo;
    Profile juliet;

    // Initialize Profiles
    strcpy(romeo.name, "Romeo");
    romeo.steps = 0;
    romeo.distance = 0.0;
    romeo.calories = 0;
    
    strcpy(juliet.name, "Juliet");
    juliet.steps = 0;
    juliet.distance = 0.0;
    juliet.calories = 0;

    // The score of each day in health and exercise
    updateSteps(&romeo, 5000);
    updateSteps(&juliet, 6000);
    
    // Record the date of their efforts
    recordDate(&romeo);
    recordDate(&juliet);

    // Display Profiles
    printf("In fair Verona, where we lay our scene...\n\n");
    displayProfile(romeo);
    printf("\n");
    displayProfile(juliet);
    
    // Another day passes, another feat to recount
    printf("\nAlas, the sun rises and another eager day awaits...\n\n");
    updateSteps(&romeo, 3000);
    updateSteps(&juliet, 4500);
    
    // Update the records with their enchanted efforts
    recordDate(&romeo);
    recordDate(&juliet);
    
    // Display again
    printf("Oh sweet day, lend me your sunny rays...\n\n");
    displayProfile(romeo);
    printf("\n");
    displayProfile(juliet);
    
    // Whispers of a challenge arise...
    printf("\nBut soft! What challenge doth arise?\n");
    updateSteps(&romeo, 500);
    updateSteps(&juliet, 1500);
    
    // Record the date once more
    recordDate(&romeo);
    recordDate(&juliet);
    
    printf("\nIn the heat of competition...\n");
    printf("By my troth, the clock doth not lie!\n\n");
    displayProfile(romeo);
    printf("\n");
    displayProfile(juliet);
    
    // As days go by, life and steps continue
    for (int i = 1; i <= 5; i++) {
        printf("Thus do we embark upon day %d of our fitness journey...\n", i);
        int romeoSteps = 2000 + (i * 500);
        int julietSteps = 2500 + (i * 300);
        
        updateSteps(&romeo, romeoSteps);
        updateSteps(&juliet, julietSteps);
        
        recordDate(&romeo);
        recordDate(&juliet);
        
        printf("\nOn day %d:\n", i);
        displayProfile(romeo);
        printf("\n");
        displayProfile(juliet);
    }

    printf("\nThus ends the tale of our fitness, dear reader...\n");
    printf("Let not your heart be troubled, persist in thy journey...");
    return 0;
}