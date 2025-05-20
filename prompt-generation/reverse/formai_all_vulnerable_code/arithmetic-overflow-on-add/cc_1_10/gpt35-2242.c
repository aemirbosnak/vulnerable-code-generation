//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    int milliseconds = 1000 * seconds;
    clock_t start_time = clock();
    while(clock() < start_time + milliseconds);
}

int main() {
    srand(time(NULL));
    char name[30];
    printf("Welcome to the Space Adventure! What is your name? ");
    scanf("%s", name);
    printf("Hello %s! Are you ready to embark on a journey through space?\n", name);
    delay(3);
    printf("You find yourself on a spaceship headed towards the planet of Zorgon.\n");
    delay(3);
    printf("Suddenly, the ship starts to shake and alarms start blaring.\n\n");
    delay(3);
    
    int random_event = rand() % 3;
    if (random_event == 0) {
        printf("Oh no! The ship's engine has malfunctioned and we're losing power!\n");
        delay(3);
        printf("Quick, %s, we need to fix the engine before it's too late!\n", name);
        delay(3);
        printf("You work together with the crew and manage to fix the engine just in time.\n");
        delay(3);
    } else if (random_event == 1) {
        printf("Uh oh! We've encountered a group of hostile aliens!\n");
        delay(3);
        printf("Don't worry, %s, we have weapons on board. Help us fight them off!\n", name);
        delay(3);
        printf("After a heated battle, you and the crew emerge victorious.\n");
        delay(3);
    } else {
        printf("Wow, look at that! We just passed an asteroid field!\n");
        delay(3);
        printf("It's breathtaking, isn't it, %s? Sometimes the wonders of space can be truly awe-inspiring.\n", name);
        delay(3);
    }
    
    printf("\nAfter a long and eventful journey, we have finally arrived at Zorgon.\n");
    delay(3);
    printf("We landed safely on the planet and began to explore.\n");
    delay(3);
    printf("Your team discovered an ancient relic that held the key to unlocking a new form of energy.\n");
    delay(3);
    printf("Congratulations, %s! Your bravery and curiosity have uncovered a valuable resource that will benefit humanity for generations to come!\n", name);
    
    return 0;
}