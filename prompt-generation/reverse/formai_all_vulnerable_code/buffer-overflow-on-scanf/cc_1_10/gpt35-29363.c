//FormAI DATASET v1.0 Category: Online Examination System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Function for displaying results
void showResult(int score, int total){	
	printf("\n\n=============================================");
	printf("\n          Medieval Online Test Results");
	printf("\n=============================================");
	printf("\n\n Total Questions :\t%d", total);
	printf("\n Correct Answers :\t%d", score);
	printf("\n Wrong Answers :\t%d", total - score);
	printf("\n Your Score is :\t%.2f %%", (float)score/total*100);
	printf("\n\n=============================================");
}

int main(){
    int count, score;
    int answer;
    int level;
    char player_name[20];
    time_t t;
    srand((unsigned) time(&t)); // Seed the random number generator

    // Greet the player
    printf("Welcome brave adventurer, to the Medieval Online Test.\n");
    printf("Please enter your name: ");
    scanf("%s", player_name);
    printf("\nWelcome %s!\n\n", player_name);
    
    printf("Hark! Which level of difficulty would you like?\n");
    printf("Enter 1, 2 or 3.\n");
    scanf("%d", &level);

    switch(level){
        case 1:
            printf("You have chosen the EASY level. Good luck!\n");
            // Game begins at Easy level
            for(count = 1; count <= 5; count++){
                int num1 = rand() % 100 + 1;
                int num2 = rand() % 100 + 1;
                printf("\nQuestion %d:\n", count);
                printf("What is %d + %d?\n", num1, num2);
                scanf("%d", &answer);
                if(answer == num1 + num2){
                    printf("Correct!");
                    score++;
                } else {
                    printf("Wrong. The answer was %d.", num1 + num2);
                }
            }
            showResult(score, 5);
            break;
        case 2:
            printf("You have chosen the MEDIUM level. Good luck!\n");
            // Game begins at Medium level
            for(count = 1; count <= 10; count++){
                int num1 = rand() % 200 + 1;
                int num2 = rand() % 200 + 1;
                printf("\nQuestion %d:\n", count);
                printf("What is %d * %d?\n", num1, num2);
                scanf("%d", &answer);
                if(answer == num1 * num2){
                    printf("Correct!");
                    score++;
                } else {
                    printf("Wrong. The answer was %d.", num1 * num2);
                }
            }
            showResult(score, 10);
            break;
        case 3:
            printf("You have chosen the HARD level. Good luck!\n");
            // Game begins at Hard level
            for(count = 1; count <= 15; count++){
                int num1 = rand() % 500 + 1;
                int num2 = rand() % 500 + 1;
                printf("\nQuestion %d:\n", count);
                printf("What is %d - %d?\n", num1, num2);
                scanf("%d", &answer);
                if(answer == num1 - num2){
                    printf("Correct!");
                    score++;
                } else {
                    printf("Wrong. The answer was %d.", num1 - num2);
                }
            }
            showResult(score, 15);
            break;
        default:
	        printf("Invalid choice. Please enter 1, 2, or 3 only.");
	        return 0;
    }
    return 0;
}