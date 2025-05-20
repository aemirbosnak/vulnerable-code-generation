//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void start_game();
void game_over(int score);

int main() {
    srand(time(NULL));
    intro();
    start_game();
    return 0;
}

void intro() {
    printf("Welcome to the Shocking Space Adventure!\n\n");
    printf("You are a brave astronaut on a mission to explore the galaxy.\n");
    printf("Your spaceship is equipped with the latest technology, but be careful!\n");
    printf("The universe is full of dangers and surprises.\n\n");
    printf("Press ENTER to start the game...\n");
    getchar();
}

void start_game() {
    int choice, score = 0;

    while(1) {
        system("clear");
        printf("Score: %d\n", score);

        printf("What would you like to do?\n");
        printf("1. Explore a planet\n");
        printf("2. Fight an alien\n");
        printf("3. Repair the spaceship\n");
        printf("4. Quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(rand() % 2 == 0) {
                    printf("You found a valuable artifact on the planet! Score increased by 10.\n");
                    score += 10;
                } else {
                    printf("You encountered a hostile creature on the planet. Game over!\n");
                    game_over(score);
                }
                break;
            case 2:
                if(rand() % 2 == 0) {
                    printf("You defeated the alien! Score increased by 20.\n");
                    score += 20;
                } else {
                    printf("The alien was too strong. Game over!\n");
                    game_over(score);
                }
                break;
            case 3:
                if(rand() % 2 == 0) {
                    printf("You successfully repaired the spaceship.\n");
                } else {
                    printf("You accidentally damaged the spaceship further. Game over!\n");
                    game_over(score);
                }
                break;
            case 4:
                printf("Thanks for playing! Press ENTER to exit...\n");
                getchar();
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void game_over(int score) {
    printf("Game over! Your final score is %d.\n", score);
    printf("Press ENTER to exit...\n");
    getchar();
    exit(0);
}