//Falcon2-11B DATASET v1.0 Category: Space Invaders Game Clone ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int width = 800;
    int height = 600;
    int player_x = (width / 2) - 50;
    int player_y = (height / 2) - 50;
    int alien_x = rand() % (width - 100);
    int alien_y = rand() % (height - 100);
    int alien_x_speed = 1;
    int alien_y_speed = 1;
    int score = 0;
    int player_score = 0;
    int lives = 3;
    char input;
    char alien_direction = 'd';
    while (1) {
        // Clear the screen
        system("cls");

        // Draw the player ship
        printf("Player ship at (%d, %d)\n", player_x, player_y);
        printf("Alien ship at (%d, %d)\n", alien_x, alien_y);
        printf("Score: %d\n", score);

        // Draw the alien ship
        printf("Alien ship at (%d, %d)\n", alien_x, alien_y);

        // Move the player ship
        if (player_x < 0)
            player_x = 0;
        else if (player_x > width - 100)
            player_x = width - 100;
        else if (player_y < 0)
            player_y = 0;
        else if (player_y > height - 100)
            player_y = height - 100;

        // Move the alien ship
        if (alien_x < 0)
            alien_x = 0;
        else if (alien_x > width - 100)
            alien_x = width - 100;
        else if (alien_y < 0)
            alien_y = 0;
        else if (alien_y > height - 100)
            alien_y = height - 100;

        // Move the alien ship in a random direction
        if (alien_direction == 'u')
            alien_y_speed = -1;
        else if (alien_direction == 'd')
            alien_y_speed = 1;
        else if (alien_direction == 'l')
            alien_x_speed = -1;
        else if (alien_direction == 'r')
            alien_x_speed = 1;

        // Move the alien ship up or down
        alien_y += alien_y_speed;

        // Move the alien ship left or right
        alien_x += alien_x_speed;

        // Check if the player has collided with the alien
        if (abs(player_x - alien_x) < 20 && abs(player_y - alien_y) < 20) {
            printf("Player has collided with the alien!\n");
            lives--;
            if (lives == 0) {
                printf("Game over!\n");
                break;
            }
            else {
                alien_x = rand() % (width - 100);
                alien_y = rand() % (height - 100);
            }
        }

        // Check if the alien has collided with the bottom or top of the screen
        if (alien_y < 0) {
            alien_y = 0;
            alien_direction = 'u';
        }
        else if (alien_y > height - 100) {
            alien_y = height - 100;
            alien_direction = 'd';
        }

        // Check if the alien has collided with the left or right of the screen
        if (alien_x < 0) {
            alien_x = 0;
            alien_direction = 'l';
        }
        else if (alien_x > width - 100) {
            alien_x = width - 100;
            alien_direction = 'r';
        }

        // Check if the player has collided with the alien
        if (abs(player_x - alien_x) < 20 && abs(player_y - alien_y) < 20) {
            printf("Player has collided with the alien!\n");
            player_score++;
            score++;
            printf("Score: %d\n", score);
        }

        // Check if the player has won the game
        if (score == 3) {
            printf("Player has won the game!\n");
            break;
        }

        // Check if the player has lost the game
        if (lives == 0) {
            printf("Game over!\n");
            break;
        }

        // Get input from the player
        printf("Press 'w' to move the player ship up\n");
        printf("Press's' to move the player ship down\n");
        printf("Press 'a' to move the player ship left\n");
        printf("Press 'd' to move the player ship right\n");
        printf("Press 'q' to quit the game\n");
        scanf("%c", &input);

        // Move the player ship based on input
        if (input == 'w') {
            if (player_y > 0)
                player_y--;
        }
        else if (input =='s') {
            if (player_y < height - 100)
                player_y++;
        }
        else if (input == 'a') {
            if (player_x > 0)
                player_x--;
        }
        else if (input == 'd') {
            if (player_x < width - 100)
                player_x++;
        }
        else if (input == 'q') {
            break;
        }
    }
    return 0;
}