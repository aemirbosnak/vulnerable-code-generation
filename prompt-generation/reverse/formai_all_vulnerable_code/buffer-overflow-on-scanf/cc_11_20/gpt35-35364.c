//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num_of_aliens = 0;
    float invasion_prob = 0.0f;
    int seed = time(NULL);
    
    printf("Welcome to the Alien Invasion Probability Calculator 3000! \n\n");
    
    printf("Please enter the number of known alien sightings in your area: ");
    scanf("%d", &num_of_aliens);
    
    srand(seed);
    int rand_num = rand() % 100;
    
    for(int i = 0; i < 8; i++) {
        switch(rand_num % 4) {
            case 0:
                printf("Calculating...");
                break;
            case 1:
                printf("Analyzing data...");
                break;
            case 2:
                printf("Processing probabilities...");
                break;
            case 3:
                printf("Getting ready...");
                break;
        }
        
        rand_num = rand() % 100;
        for(int j = 0; j < 500000000; j++);
        
        printf("\r");
    }
    
    invasion_prob = num_of_aliens * 10.0f;
    
    rand_num = rand() % 100;
    
    for(int i = 0; i < 8; i++) {
        switch(rand_num % 4) {
            case 0:
                printf("Calculating...");
                break;
            case 1:
                printf("Analyzing data...");
                break;
            case 2:
                printf("Processing probabilities...");
                break;
            case 3:
                printf("Getting ready...");
                break;
        }
        
        rand_num = rand() % 100;
        for(int j = 0; j < 500000000; j++);
        
        printf("\r");
    }
    
    invasion_prob *= (rand_num % 50 + 50.0f) / 100.0f;
    
    printf("\n\nThe chance of an alien invasion in your area is %.2f%%. \n\n", invasion_prob);
    
    printf("Thank you for using the Alien Invasion Probability Calculator 3000!");
    
    return 0;
}