//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

int main(){

    printf("Welcome to the Mathematical Adventure!\n");
    printf("In this game, you will face mathematical challenges that you have to solve in order to progress through the game. Good luck!\n");

    int lives = 3;
    int level = 1;
    int progress = 0;
    int score = 0;
    int answer;

    while (lives > 0 && level <= 3){

        printf("\nLevel %d:\n", level);
        printf("Progress: %d/5\n", progress);
        printf("Lives: %d\n", lives);
        printf("Score: %d\n", score);

        if (progress == 5){
            level++;
            progress = 0;
            printf("Congratulations! You have completed level %d.\n", level-1);
            printf("Your score is now %d.\n", score);
            continue;
        }

        int num1 = rand() % (level * 10) + 1;
        int num2 = rand() % (level * 10) + 1;
        char operation = rand() % 4 + 1;

        if (operation == 1){ // Addition
            printf("%d + %d = ", num1, num2);
            scanf("%d", &answer);
            if (answer == num1 + num2){
                printf("Correct!\n");
                progress++;
                score += level * 10;
            } else {
                printf("Incorrect! The correct answer is %d.\n", num1 + num2);
                lives--;
            }
        } else if (operation == 2){ // Subtraction
            printf("%d - %d = ", num1, num2);
            scanf("%d", &answer);
            if (answer == num1 - num2){
                printf("Correct!\n");
                progress++;
                score += level * 10;
            } else {
                printf("Incorrect! The correct answer is %d.\n", num1 - num2);
                lives--;
            }
        } else if (operation == 3){ // Multiplication
            printf("%d x %d = ", num1, num2);
            scanf("%d", &answer);
            if (answer == num1 * num2){
                printf("Correct!\n");
                progress++;
                score += level * 10;
            } else {
                printf("Incorrect! The correct answer is %d.\n", num1 * num2);
                lives--;
            }
        } else { // Division
            printf("%d / %d = ", num1*num2, num2);
            scanf("%d", &answer);
            if (answer == num1){
                printf("Correct!\n");
                progress++;
                score += level * 10;
            } else {
                printf("Incorrect! The correct answer is %d.\n", num1);
                lives--;
            }
        }

    }

    if (lives == 0){
        printf("Game Over! You have run out of lives.\n");
    } else {
        printf("Congratulations! You have completed level 3.\n");
        printf("Your final score is %d.\n", score);
    }

    return 0;
}