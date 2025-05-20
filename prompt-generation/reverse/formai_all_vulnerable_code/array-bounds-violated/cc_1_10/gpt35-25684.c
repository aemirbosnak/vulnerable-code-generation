//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
    #ifdef _WIN32
        system("cls");  // For Windows
    #else
        system("clear"); // For Linux/Unix/MacOS
    #endif
}

void generateAliens(int aliens[][3], int numAliens) {
    srand(time(NULL));
    for(int i=0; i<numAliens; i++) {
        aliens[i][0] = rand()%10 + 1;   // Generate random x-coordinate
        aliens[i][1] = rand()%10 + 1;   // Generate random y-coordinate
        aliens[i][2] = rand()%3 + 1;    // Generate random strength
    }
}

void printBoard(int board[][10], int numAliens, int aliens[][3], int playerHealth) {
    clearScreen();
    printf("Procedural Space Adventure\n\n");
    printf("Player Health: %d%%\n\n", playerHealth);
    printf("   ");
    for(int i=0; i<10; i++)
        printf("%d ", i);
    printf("\n");
    for(int i=0; i<10; i++) {
        printf("%d  ", i);
        for(int j=0; j<10; j++) {
            if(board[i][j] == 0)
                printf(". ");
            else if(board[i][j] == 1)
                printf("X ");
            else {
                int flag = 0;
                for(int k=0; k<numAliens; k++) {
                    if(aliens[k][0] == i && aliens[k][1] == j) {
                        printf("%d ", aliens[k][2]);
                        flag = 1;
                        break;
                    }
                }
                if(!flag)
                    printf("E ");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[10][10] = {0};
    int playerHealth = 100;
    int aliens[10][3];
    int numAliens = 5;
    int x, y;

    for(int i=0; i<numAliens; i++)
        board[aliens[i][0]][aliens[i][1]] = 2;

    generateAliens(aliens, numAliens);
    printBoard(board, numAliens, aliens, playerHealth);

    while(1) {
        printf("\nEnter X and Y coordinates to attack: ");
        scanf("%d %d", &x, &y);

        if(x < 0 || x > 9 || y < 0 || y > 9) {
            printf("Invalid coordinates! Try again.\n");
            continue;
        }

        if(board[x][y] == 2) {
            int strength;
            for(int i=0; i<numAliens; i++) {
                if(aliens[i][0] == x && aliens[i][1] == y) {
                    strength = aliens[i][2];
                    aliens[i][2] = 0;
                    break;
                }
            }
            board[x][y] = 1;
            playerHealth -= strength*10;
            printf("You killed an alien with strength %d!\n", strength);
            if(playerHealth <= 0) {
                printf("Game Over! You lost.\n");
                break;
            }
            numAliens--;
            if(numAliens == 0) {
                printf("Congratulations! You won.\n");
                break;
            }
        }
        else if(board[x][y] == 1)
            printf("You have already attacked this square! Try again.\n");
        else
            printf("Missed! There is no alien here.\n");

        printBoard(board, numAliens, aliens, playerHealth);
    }
    return 0;
}