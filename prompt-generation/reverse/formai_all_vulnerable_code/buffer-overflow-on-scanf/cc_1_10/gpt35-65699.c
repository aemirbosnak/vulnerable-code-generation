//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int milli_seconds){
    clock_t start_time = clock();
    while(clock() < start_time + milli_seconds);
}

int main(){
    srand(time(0)); //seeding the random number generator
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of a spaceship called Voyager.\n");
    printf("Your mission is to explore the uncharted territories of space and discover new planets.\n");
    printf("Do you accept this mission?\n");
    
    char answer;
    scanf("%c", &answer);
    
    if(answer == 'y' || answer == 'Y'){
        printf("Great! Let's begin our journey.\n");
    }else{
        printf("Exiting program...\n");
        exit(0);
    }
    
    delay(2000);
    
    printf("We are now entering hyperspace...\n");
    delay(3000);
    
    int planets_discovered = 0;
    int current_planet_population;
    
    while(1){
        int encounter = rand()%101; //random number between 0 and 100
        
        if(encounter >= 50){ //50% chance of discovering a new planet
            int planet_population = rand()%1000000 + 1; //random population between 1 and 1,000,000
            printf("Congratulations! You have discovered a new planet with a population of %d.\n", planet_population);
            planets_discovered++;
            current_planet_population = planet_population;
        }else{
            printf("You drift through space...\n");
            delay(2000);
        }
        
        printf("Would you like to land on the planet and explore?\n");
        scanf(" %c", &answer); //space before %c to consume newline character
        
        if(answer == 'y' || answer == 'Y'){
            printf("Landing on the planet...\n");
            delay(3000);
            
            if(current_planet_population <= 1000){
                printf("The planet is uninhabited.\n");
            }else if(current_planet_population <= 100000){
                printf("The planet has a small population.\n");
            }else if(current_planet_population <= 1000000){
                printf("The planet has a large population.\n");
            }
            
            printf("Leaving planet...\n");
            delay(2000);
        }else{
            printf("Continuing journey...\n");
            delay(2000);
        }
        
        printf("Spaceship Voyager has discovered %d planets so far.\n", planets_discovered);
        printf("Would you like to continue exploring?\n");
        scanf(" %c", &answer);
        
        if(answer == 'n' || answer == 'N'){
            printf("Exiting program...\n");
            break;
        }else{
            printf("Continuing journey...\n");
            delay(2000);
        }
    }
    
    return 0;
}