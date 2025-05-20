//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_AREAS 10

typedef struct {
    char name[30];
    double population;
    double alien_activity; // The amount of alien sightings per month
} Area;

double calculate_invasion_probability(Area area) {
    // The probability is calculated based on the simple formula
    // P(invasion) = (alien sightings * population) / 1,000,000
    return (area.alien_activity * area.population) / 1000000;
}

void display_probability(Area area) {
    double probability = calculate_invasion_probability(area);
    printf("In the area of %s, with a population of %.0f and alien activity of %.2f sightings/month:\n",
           area.name, area.population, area.alien_activity);
    printf("The calculated probability of an alien invasion is %.6f%%.\n", probability);
}

int main() {
    Area areas[MAX_AREAS];
    int n;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    printf("How many areas would you like to analyze? (Max %d): ", MAX_AREAS);
    scanf("%d", &n);
    if (n > MAX_AREAS) {
        printf("Too many areas! Please limit your analysis to %d areas.\n", MAX_AREAS);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter the name of Area %d: ", i + 1);
        scanf("%s", areas[i].name);
        
        printf("Enter the population of %s: ", areas[i].name);
        scanf("%lf", &areas[i].population);
        
        printf("Enter the alien activity (sightings/month) in %s: ", areas[i].name);
        scanf("%lf", &areas[i].alien_activity);
    }

    printf("\nCalculating probabilities of alien invasions...\n\n");
    
    for (int i = 0; i < n; i++) {
        display_probability(areas[i]);
    }

    printf("\nAnalysis complete. Stay vigilant and remember, the truth is out there!\n");
    return 0;
}