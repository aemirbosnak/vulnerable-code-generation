//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 0, y = 0, z = 0;
    int choice;

    printf("Welcome to Math Adventure Game!\n");
    printf("You are standing at the origin of a 3D coordinate system (0,0,0).\n");
    printf("You have to solve mathematical puzzles to navigate the coordinate axes.\n");

    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Move in x-direction with x = x + 1\n");
        printf("2. Move in y-direction with y = y + 1\n");
        printf("3. Move in z-direction with z = z + 1\n");
        printf("4. Solve a math puzzle\n");
        printf("5. Exit the game\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                x++;
                printf("You moved 1 unit in the positive x-direction.\n");
                break;

            case 2:
                y++;
                printf("You moved 1 unit in the positive y-direction.\n");
                break;

            case 3:
                z++;
                printf("You moved 1 unit in the positive z-direction.\n");
                break;

            case 4:
                printf("Solve this puzzle to make progress:\n");
                printf("What is the cube root of 729?\n");
                int answer;
                scanf("%d", &answer);
                if (answer == 9) {
                    printf("Congratulations! You solved the puzzle and gained 10 points.\n");
                    x += 2;
                    y += 2;
                    z += 2;
                } else {
                    printf("Oops! The answer is incorrect. Try again.\n");
                    x--;
                    y--;
                    z--;
                }
                break;

            case 5:
                printf("Thanks for playing. Exiting the game...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("You are now at position (%d,%d,%d).\n", x, y, z);

        if (x >= 10 && y >= 10 && z >= 10) {
            printf("Congratulations! You have solved all the puzzles and reached the point (10,10,10).\n");
            printf("You have completed the Math Adventure Game.\n");
            exit(0);
        }

    } while (1);

    return 0;
}