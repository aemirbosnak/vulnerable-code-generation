//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    printf("Welcome to the Surreal Adventure Game!\n");
    int health = 100;
    int sanity = 100;
    int random_event = rand() % 6;
    char player_name[20];
    printf("What's your name, traveler?\n");
    scanf("%s", player_name);
    printf("Welcome, %s! You begin with %d health and %d sanity.\n", player_name, health, sanity);

    while (health > 0 && sanity > 0) {
        switch (random_event) {
            case 0:
                printf("You come across an infinite staircase. How many steps do you climb?\n");
                int steps;
                scanf("%d", &steps);
                if (steps > 100) {
                    printf("You reach the top and find yourself in a world of pure imagination. Your sanity increases by 10.\n");
                    sanity += 10;
                } else {
                    printf("You fall down the stairs and lose 20 health.\n");
                    health -= 20;
                }
                break;
            case 1:
                printf("You stumble upon a talking cat. What do you ask?\n");
                char words[50];
                scanf("%s", words);
                printf("The cat responds: 'The only answer is within yourself.'\n");
                break;
            case 2:
                printf("You find yourself in a room full of mirrors. What do you see in the reflections?\n");
                char reflections[50];
                scanf("%s", reflections);
                printf("The mirrors shatter and the room transforms into a labyrinth. Your sanity decreases by 10.\n");
                sanity -= 10;
                break;
            case 3:
                printf("You encounter a giant mechanical spider. How do you defeat it?\n");
                char weapon[20];
                scanf("%s", weapon);
                if (strcmp(weapon, "love") == 0) {
                    printf("The spider short circuits and shuts down. Your sanity increases by 10.\n");
                    sanity += 10;
                } else {
                    printf("The spider destroys your %s and you lose 30 health.\n", weapon);
                    health -= 30;
                }
                break;
            case 4:
                printf("You enter a room and find your doppelganger. What do you do?\n");
                char action[20];
                scanf("%s", action);
                if (strcmp(action, "fear") == 0) {
                    printf("The doppelganger disappears as you conquer your fears. Your sanity increases by 10.\n");
                    sanity += 10;
                } else {
                    printf("The doppelganger attacks you and you lose 30 health.\n");
                    health -= 30;
                }
                break;
            case 5:
                printf("You discover a secret room containing a mysterious box. Do you open it?\n");
                char choice[5];
                scanf("%s", choice);
                if (strcmp(choice, "yes") == 0) {
                    printf("You open the box and find a note. It reads: 'The journey is the destination.' Your sanity decreases by 10.\n");
                    sanity -= 10;
                } else {
                    printf("You leave the box untouched and continue on your journey.\n");
                }
                break;
            default:
                printf("You see a hallucination and can't discern reality for a moment. You lose 10 sanity.\n");
                sanity -= 10;
                break;
        }
        printf("You have %d health and %d sanity left.\n", health, sanity);
        random_event = rand() % 6;
    }
    if (health <= 0) {
        printf("You have lost all your health and have died on your adventure. Better luck next time!\n");
    } else {
        printf("Congratulations, %s! You have completed the Surreal Adventure Game with %d health and %d sanity remaining.\n", player_name, health, sanity);
    }
    return 0;
}