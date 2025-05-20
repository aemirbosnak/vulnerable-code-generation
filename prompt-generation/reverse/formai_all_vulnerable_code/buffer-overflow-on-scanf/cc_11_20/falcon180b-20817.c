//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int x = 0, y = 0;
    int map[10][10] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    int playerx = 0;
    int playery = 0;

    srand(time(0));

    printf("Welcome to the Text-Based Adventure Game!\n");

    while(1) {
        system("clear");
        printf("You are at location (%d,%d)\n", playerx, playery);
        printf("What would you like to do?\n");
        printf("1. Move Up\n");
        printf("2. Move Down\n");
        printf("3. Move Left\n");
        printf("4. Move Right\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(playerx > 0 && map[playerx-1][playery]!= 1) {
                    playerx--;
                }
                break;
            case 2:
                if(playerx < 8 && map[playerx+1][playery]!= 1) {
                    playerx++;
                }
                break;
            case 3:
                if(playery > 0 && map[playerx][playery-1]!= 1) {
                    playery--;
                }
                break;
            case 4:
                if(playery < 8 && map[playerx][playery+1]!= 1) {
                    playery++;
                }
                break;
            case 5:
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}