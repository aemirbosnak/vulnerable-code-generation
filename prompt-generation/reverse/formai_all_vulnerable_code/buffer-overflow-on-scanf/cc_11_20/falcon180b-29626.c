//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int score = 0;
    int lives = 3;
    int level = 1;
    char name[20];
    printf("Welcome to the space adventure game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! You are now in level %d.\n", name, level);
    while (lives > 0 && level <= 10) {
        printf("You have %d lives left.\n", lives);
        printf("What would you like to do?\n");
        printf("1. Move forward\n");
        printf("2. Shoot\n");
        printf("3. Defend\n");
        printf("4. Check score\n");
        printf("5. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (level == 1) {
                    printf("You moved forward and reached level 2!\n");
                    level++;
                } else if (level == 2) {
                    printf("You moved forward and reached level 3!\n");
                    level++;
                } else if (level == 3) {
                    printf("You moved forward and reached level 4!\n");
                    level++;
                } else if (level == 4) {
                    printf("You moved forward and reached level 5!\n");
                    level++;
                } else if (level == 5) {
                    printf("You moved forward and reached level 6!\n");
                    level++;
                } else if (level == 6) {
                    printf("You moved forward and reached level 7!\n");
                    level++;
                } else if (level == 7) {
                    printf("You moved forward and reached level 8!\n");
                    level++;
                } else if (level == 8) {
                    printf("You moved forward and reached level 9!\n");
                    level++;
                } else if (level == 9) {
                    printf("You moved forward and reached level 10!\n");
                    level++;
                }
                break;
            case 2:
                printf("You shot and gained 10 points!\n");
                score += 10;
                break;
            case 3:
                printf("You defended and lost 5 points.\n");
                score -= 5;
                break;
            case 4:
                printf("Your score is %d.\n", score);
                break;
            case 5:
                printf("Goodbye, %s! Your final score is %d.\n", name, score);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    printf("Game over! You lost all your lives.\n");
    return 0;
}