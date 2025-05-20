//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: grateful
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

/* space adventure function */
void space_adventure() 
{ 
    int fuel = 100, distance = 0, random_event; 

    /* seed random number generator */
    srand(time(NULL)); 

    printf("Welcome to our space adventure!\n"); 
    printf("You have been chosen to explore the galaxy and discover new\nworlds.\n"); 

    while (fuel > 0 && distance < 5000) 
    { 
        printf("\nCurrent distance: %d\nFuel remaining: %d\n", distance, fuel); 
        printf("What would you like to do?\n"); 
        printf("1. Travel forward\n"); 
        printf("2. Refuel the ship\n"); 

        /* random event chance (10%) */
        random_event = rand() % 10; 

        if (random_event == 0) 
        { 
            printf("\nOh no, an asteroid field is blocking your path!\n"); 
            printf("1. Try to navigate through it\n"); 
            printf("2. Turn around and find another route\n"); 
            printf("3. Put on your spacesuit and walk on the asteroid\n"); 
        } 

        int choice; 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 

        switch (choice) 
        { 
            case 1: 
                distance += 500; 
                fuel -= 20; 
                if (random_event == 0) 
                { 
                    /* choose a random outcome from the asteroid field event */
                    int outcome = rand() % 3; 
                    if (outcome == 0) 
                    { 
                        printf("\nYou made it through the asteroid field safely!\n"); 
                        fuel -= 10; 
                    } 
                    else if (outcome == 1) 
                    { 
                        printf("\nYour ship was damaged by the asteroids, losing fuel!\n"); 
                        fuel -= 30; 
                    } 
                    else 
                    { 
                        printf("\nYour navigation system malfunctioned and you got lost!\n"); 
                        distance -= 500; 
                    } 
                } 
                break; 

            case 2: 
                fuel = 100; 
                break; 

            case 3: 
                printf("\nYou attempt to walk on the asteroid but lose your footing\n"); 
                printf("and are lost in space forever.\n"); 
                exit(1); 

            default: 
                printf("\nInvalid choice, please enter a valid choice.\n"); 
        } 

        /* check if the player has reached the destination */
        if (distance >= 5000) 
        { 
            printf("\nCongratulations, you have reached the destination!\n"); 
            printf("You are the first to discover this new world.\n"); 
        } 

        /* check if the player has run out of fuel */
        if (fuel <= 0) 
        { 
            printf("\nYou have run out of fuel and your ship is adrift in space.\n"); 
            printf("Your mission is a failure.\n"); 
            exit(1); 
        } 
    } 
} 

/* main function */
int main() 
{ 
    space_adventure(); 
    return 0; 
}