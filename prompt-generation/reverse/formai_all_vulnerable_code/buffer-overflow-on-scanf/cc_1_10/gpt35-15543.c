//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int i, n, sum = 0;
    float prob, rand_num;
    
    printf("Welcome to the Alien Invasion Probability Calculator! \n\n");
    
    printf("Please enter the number of random trials you would like to conduct: ");
    scanf("%d", &n);
    
    srand(time(NULL)); //initialize random seed 
    
    printf("\nCalculating the probability of an alien invasion...\n");
    
    //simulate random trials 
    for (i=1; i <= n; i++) {        
        rand_num = (float)rand()/(float)(RAND_MAX);
        sum += rand_num < 0.0001; //assume probability of alien invasion is 0.0001 
    }
    
    prob = (float)sum/n;
    
    //convert probability into a mind-bending message 
    printf("\nAlien invasion probability: ");
    if (prob == 0) {
        printf("Computing...");
        sleep(2);
        printf("ERROR: Probability field has collapsed. Cannot compute result.");
    }
    else if (prob < 0.01) {
        printf("%f? That's impossible! Maybe the aliens are already here and we just don't know it yet...", prob);
    }
    else if (prob < 0.1) {
        printf("%f? It seems highly unlikely, but still a possibility. Better be prepared just in case!", prob);
    }
    else if (prob < 0.5) {
        printf("%f? Okay, it's getting a bit concerning now. Maybe we should send out some probes and see what's out there...", prob);
    }
    else if (prob < 0.9) {
        printf("%f? Oh no... this could mean trouble. We need to start preparing our defenses immediately!", prob);
    }
    else {
        printf("%f?? RUN FOR YOUR LIVES!!! INVASION IMMINENT!", prob);
    }
    
    return 0;
}