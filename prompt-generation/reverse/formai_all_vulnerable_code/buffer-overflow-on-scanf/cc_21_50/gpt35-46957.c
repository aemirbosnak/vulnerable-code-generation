//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int probability = 0;
    int alien_strength, human_strength, advanced_weaponry = 0;
    char planet_type, space_weather;
    
    // Seed the random number generator with current time
    srand(time(NULL));
    
    // Get user inputs - planet type, space weather, alien and human strengths, and advanced weaponry availability
    printf("Enter planet type (V: Volcanic, D: Desert, R: Rocky, G: Gaseous or A: Aquatic): ");
    scanf("%c", &planet_type);
    getchar();
    
    printf("Enter space weather (S: Solar Flares, A: Asteroid Storm, Q: Quiet): ");
    scanf("%c", &space_weather);
    getchar();
    
    printf("Enter alien strength (1-10): ");
    scanf("%d", &alien_strength);
    
    printf("Enter human strength (1-10): ");
    scanf("%d", &human_strength);
    
    printf("Does your team have advanced weaponry? (1: Yes, 0: No): ");
    scanf("%d", &advanced_weaponry);
    
    // Calculate probability based on inputs
    if (planet_type == 'V') {
        if (space_weather == 'S') {
            probability = 90;
        } else if (space_weather == 'A') {
            probability = 60;
        } else {
            probability = 80;
        }
        if (alien_strength >= 8) {
            probability -= 10;
        }
        if (human_strength >= 8) {
            probability += 10;
        }
        if (advanced_weaponry) {
            probability += 20;
        }
    } else if (planet_type == 'D') {
        if (space_weather == 'S') {
            probability = 75;
        } else if (space_weather == 'A') {
            probability = 50;
        } else {
            probability = 70;
        }
        if (alien_strength >= 8) {
            probability -= 5;
        }
        if (human_strength >= 8) {
            probability += 5;
        }
        if (advanced_weaponry) {
            probability += 10;
        }
    } else if (planet_type == 'R') {
        if (space_weather == 'S') {
            probability = 50;
        } else if (space_weather == 'A') {
            probability = 30;
        } else {
            probability = 40;
        }
        if (alien_strength >= 8) {
            probability -= 5;
        }
        if (human_strength >= 8) {
            probability += 5;
        }
        if (advanced_weaponry) {
            probability += 10;
        }
    } else if (planet_type == 'G') {
        if (space_weather == 'S') {
            probability = 10;
        } else if (space_weather == 'A') {
            probability = 20;
        } else {
            probability = 30;
        }
        if (alien_strength >= 8) {
            probability += 5;
        }
        if (human_strength >= 8) {
            probability -= 5;
        }
        if (advanced_weaponry) {
            probability += 5;
        }
    } else if (planet_type == 'A') {
        if (space_weather == 'S') {
            probability = 95;
        } else if (space_weather == 'A') {
            probability = 90;
        } else {
            probability = 85;
        }
        if (alien_strength >= 8) {
            probability -= 5;
        }
        if (human_strength >= 8) {
            probability += 5;
        }
        if (advanced_weaponry) {
            probability += 15;
        }
    } else {
        printf("Invalid planet type entered!");
        return 0;
    }
    
    // Generate a random factor between 0.5 and 1.5 to reflect the unpredictable nature of alien invasions
    float factor = ((float)rand() / RAND_MAX) + 0.5;
    
    // Calculate final probability taking into account the random factor
    int final_probability = (int)(probability * factor);
    
    // Print the final probability to the user
    printf("\n\nThe probability of an alien invasion successfully taking over planet %c with %c space weather is %d%%\n\n", planet_type, space_weather, final_probability);
    
    return 0;
}