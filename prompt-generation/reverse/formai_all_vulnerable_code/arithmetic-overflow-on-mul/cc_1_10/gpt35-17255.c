//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int);
int generateRandom(int, int);

int main(void)
{
    srand(time(NULL));
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in front of an old, creaky house with a sign that reads 'Haunted House' on the gate.\n");
    printf("Do you dare to enter the house? (y/n) ");
    char choice;
    scanf("%c", &choice);
    
    if(choice == 'y' || choice == 'Y') {
        printf("As you enter the house, the door slams shut behind you.\n");
        delay(2000);
        printf("You try to open the door, but it's stuck. You're trapped!\n");
        delay(3000);
        printf("Suddenly, you hear strange noises coming from all around you.\n");
        delay(3000);
        printf("The lights flicker and go out, leaving you in complete darkness.\n");
        delay(3000);
        printf("You feel a cold chill touch the back of your neck.\n");
        delay(1000);
        printf("You turn around, but no one is there. You're alone in the dark.\n");
        delay(3000);
        printf("Suddenly, you see a shadowy figure moving towards you.\n");
        delay(1000);
        printf("You try to run, but your feet won't move.\n");
        delay(2000);
        printf("The figure gets closer and closer, until you can see its face.\n");
        delay(1000);
        printf("It's a ghost! You scream in terror as the ghost reaches out to you.\n");
        delay(2000);
        printf("But then, the lights come back on and the ghost disappears.\n");
        delay(2000);
        printf("You find yourself standing in the middle of an empty room.\n");
        delay(1000);
        printf("You realize it was all just a simulation. Congratulations, you survived!\n");
    } else {
        printf("You chicken out and leave. Game over.\n");
    }
    
    return 0;
}

void delay(int milliseconds) {
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

int generateRandom(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}