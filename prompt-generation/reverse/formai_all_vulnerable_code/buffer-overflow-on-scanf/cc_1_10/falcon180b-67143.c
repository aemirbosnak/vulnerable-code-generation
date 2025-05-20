//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int score = 0;
    int lives = 3;
    int level = 1;

    srand(time(0));

    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You wake up in a dark room with no memory of how you got there.\n");
    printf("Your goal is to escape the room and find out what happened to you.\n");
    printf("You have 3 lives. Lose all of them and it's game over.\n");

    while (lives > 0) {
        system("clear");
        printf("Level %d\n\n", level);
        printf("Score: %d\n", score);
        printf("Lives: %d\n\n", lives);

        int random = rand() % 3;

        switch (random) {
            case 0:
                printf("You find a key on the floor.\n");
                printf("Press 1 to pick it up or 2 to leave it.\n");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("You picked up the key.\n");
                    score++;
                } else {
                    printf("You left the key on the floor.\n");
                }
                break;

            case 1:
                printf("You hear footsteps outside the door.\n");
                printf("Press 1 to hide or 2 to confront whoever is out there.\n");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("You hide under the bed.\n");
                    score++;
                } else {
                    printf("You confront the person outside the door.\n");
                    lives--;
                }
                break;

            case 2:
                printf("You find a note on the table.\n");
                printf("Press 1 to read it or 2 to ignore it.\n");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("The note says: 'You were kidnapped by the evil Dr. Doom.'\n");
                    score++;
                } else {
                    printf("You ignore the note.\n");
                }
                break;
        }

        if (score >= 10) {
            level++;
            score = 0;
        }
    }

    if (lives == 0) {
        printf("Game Over!\n");
    } else {
        printf("Congratulations! You escaped the room with %d lives left.\n", lives);
    }

    return 0;
}