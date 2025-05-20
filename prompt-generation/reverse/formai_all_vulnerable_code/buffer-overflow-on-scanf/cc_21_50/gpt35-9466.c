//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, num, found;
    int bingo[5][5] = {0};
    char name[20];
    srand(time(NULL));
    printf("Welcome to Bingo Simulator! Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    // generate random bingo card
    for(i=0; i<5; i++) {
        found = 1;
        while(found) {
            num = rand() % 15 + i * 15 + 1;
            found = 0;
            for(j=0; j<5; j++) {
                if(bingo[j][i] == num) {
                    found = 1;
                    break;
                }
            }
        }
        bingo[i][2] = num;
    }
    for(i=0; i<5; i++) {
        found = 1;
        while(found) {
            num = rand() % 15 + i * 15 + 1;
            found = 0;
            for(j=0; j<5; j++) {
                if(bingo[j][i] == num) {
                    found = 1;
                    break;
                }
            }
        }
        bingo[i][3] = num;
    }
    bingo[2][2] = 0;
    // print bingo card
    printf("Here is your bingo card:\n");
    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            if(bingo[j][i] == 0) {
                printf("  ");
            }
            else {
                printf("%2d", bingo[j][i]);
            }
            printf("|");
        }
        printf("\n");
    }
    printf("\n");
    // play game
    printf("Let's play bingo!\n");
    for(n=1; n<=25; n++) {
        printf("Press Enter to draw the next number.");
        getchar();
        found = 0;
        while(!found) {
            num = rand() % 75 + 1;
            for(i=0; i<5; i++) {
                for(j=0; j<5; j++) {
                    if(bingo[j][i] == num) {
                        bingo[j][i] = 0;
                        found = 1;
                    }
                }
            }
        }
        //check for bingo
        if((bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0) || 
           (bingo[0][4] == 0 && bingo[1][3] == 0 && bingo[3][1] == 0 && bingo[4][0] == 0)) {
            printf("%s wins - diagonal bingo!\n", name);
            break;
        }
        for(i=0; i<5; i++) {
            if(bingo[i][0] == 0 && bingo[i][1] == 0 && bingo[i][2] == 0 && bingo[i][3] == 0 && bingo[i][4] == 0) {
                printf("%s wins - horizontal bingo!\n", name);
                break;
            }
            if(bingo[0][i] == 0 && bingo[1][i] == 0 && bingo[2][i] == 0 && bingo[3][i] == 0 && bingo[4][i] == 0) {
                printf("%s wins - vertical bingo!\n", name);
                break;
            }
        }
        // print updated bingo card
        printf("Number drawn: %d\n", num);
        printf("Updated bingo card:\n");
        for(i=0; i<5; i++) {
            for(j=0; j<5; j++) {
                if(bingo[j][i] == 0) {
                    printf("  ");
                }
                else {
                    printf("%2d", bingo[j][i]);
                }
                printf("|");
            }
            printf("\n");
        }
        printf("\n");
    }
    if(n == 26) {
        printf("Sorry, no more numbers! Game over.\n");
    }
    return 0;
}