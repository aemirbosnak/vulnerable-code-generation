//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator! \n");
    
    srand(time(NULL)); // set seed for random number generator
    
    int num_aliens = rand() % 100 + 1; // randomly generate number of aliens
    
    printf("There are currently %d aliens approaching Earth. \n", num_aliens);
    
    float probability = (num_aliens * 0.1) / 100; // calculate invasion probability
    
    if(probability > 0.5) {
        printf("Warning! Invasion highly likely with a probability of %.2f percent. \n", (probability * 100));
    } else {
        printf("Invasion unlikely with a probability of %.2f percent. \n", (probability * 100));
    }
    
    // generate random events that can affect probability
    int event_num = rand() % 6; // there are 6 possible events
    char event[6][50] = {"Spaceship crash on the Moon", "Alien alliance with humans", "Solar flare disruption of alien communication", "Virus outbreak among the aliens", "Powerful Earth defense system activation", "Discovery of alien weakness"};
    
    printf("Unexpected event: %s \n", event[event_num]);
    
    // adjust probability based on event
    switch(event_num) {
        case 0:
            probability += 0.2; // increase probability by 20%
            break;
        case 1:
            probability -= 0.1; // decrease probability by 10%
            break;
        case 2:
            probability -= 0.05; // decrease probability by 5%
            break;
        case 3:
            probability += 0.15; // increase probability by 15%
            break;
        case 4:
            probability -= 0.2; // decrease probability by 20%
            break;
        case 5:
            probability += 0.3; // increase probability by 30%
            break;
        default:
            break;
    }
    
    // adjust probability based on human actions
    printf("Have humans taken any action against the aliens? (Y/N) \n");
    char action;
    scanf("%c", &action);
    
    switch(action) {
        case 'Y':
        case 'y':
            printf("How effective was the human action? (1-10) \n");
            int effectiveness;
            scanf("%d", &effectiveness);
            
            probability -= (effectiveness * 0.05); // decrease probability by 5% for every unit of effectiveness
            break;
        case 'N':
        case 'n':
            probability += 0.05; // increase probability by 5% if no action taken
            break;
        default:
            break;
    }
    
    printf("Final Invasion Probability: %.2f percent \n", (probability * 100));
    
    return 0;
}