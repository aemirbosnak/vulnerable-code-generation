//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Declare variables for the math exercise
    srand(time(0));
    int num1, num2, operation, result, user_answer;
    int score = 0, total_questions = 0;

    // Loop for 10 rounds of exercise
    for(int i=1; i<=10; i++){

        printf("Round %d\n", i);

        // Select random numbers between 1 and 10 as operands for the exercise
        num1 = rand()%10 + 1;
        num2 = rand()%10 + 1;

        // Select random operation for the exercise (1-Addition, 2-Subtraction, 3-Multiplication, 4-Division)
        operation = rand()%4 + 1;

        // Generate operation based on the random choice
        switch(operation){
            case 1:
                result = num1 + num2;
                printf("%d + %d = ?\n", num1, num2);
                break;
            case 2:
                result = num1 - num2;
                printf("%d - %d = ?\n", num1, num2);
                break;
            case 3:
                result = num1 * num2;
                printf("%d x %d = ?\n", num1, num2);
                break;
            case 4:
                result = num1 / num2;
                printf("%d / %d = ?\n", num1, num2);
                break;
        }

        // Get user answer and evaluate
        printf("Enter your answer: ");
        scanf("%d", &user_answer);

        if(user_answer == result){
            printf("Correct!\n");
            score++;
        }else{
            printf("Wrong! The correct answer is %d\n", result);
        }

        total_questions++;

    }

    // Display final score and feedback
    printf("\nYour score is %d/%d\n", score, total_questions);

    // Return 0 indicating successful execution of program
    return 0;
}