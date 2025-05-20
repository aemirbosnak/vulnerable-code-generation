//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to calculate the probability of an alien invasion
double calculateAlienInvasionProbability(int num_of_civilizations, double avg_relationship, int tech_level) {
    double base_prob = 0.1; //base probability of an alien invasion (10%)
    double rel_mod = avg_relationship / 10; //modify base probability based on average relationship
    double tech_mod = tech_level / 100.0; //modify base probability based on tech level
    
    double prob = base_prob + rel_mod - tech_mod; //calculate final probability
    
    //increase probability based on number of civilizations in the galaxy
    if(num_of_civilizations < 100) {
        prob += 0.05;
    } else if (num_of_civilizations > 1000) {
        prob += 0.2;
    } else {
        prob += 0.1;
    }
    
    return prob; 
}

int main() {
    srand(time(0)); //seed the random number generator with the current time
    
    int num_of_civilizations, tech_level;
    double avg_relationship;
    
    //ask user for input values
    printf("Enter the number of known civilizations in the galaxy (must be between 1 and 10000): ");
    scanf("%d", &num_of_civilizations);
    printf("Enter the average relationship rating between civilizations (-10 to 10): ");
    scanf("%lf", &avg_relationship);
    printf("Enter the current tech level of your civilization (1 to 1000): ");
    scanf("%d", &tech_level);
    
    //check input values are valid
    if(num_of_civilizations < 1 || num_of_civilizations > 10000) {
        printf("Invalid value for number of civilizations.\n");
        return 0;
    }
    
    if(avg_relationship < -10 || avg_relationship > 10) {
        printf("Invalid value for average relationship.\n");
        return 0;
    }
    
    if(tech_level < 1 || tech_level > 1000) {
        printf("Invalid value for tech level.\n");
        return 0;
    }
    
    //calculate the probability of an alien invasion
    double invasion_prob = calculateAlienInvasionProbability(num_of_civilizations, avg_relationship, tech_level);
    
    //randomly generate an invasion outcome based on the probability
    int invasion_outcome = rand() % 100 + 1; //generate a number between 1 and 100
    
    if(invasion_outcome <= invasion_prob * 100) {
        printf("Alien invasion successful!\n");
    } else {
        printf("Alien invasion failed.\n");
    }
    
    return 0;
}