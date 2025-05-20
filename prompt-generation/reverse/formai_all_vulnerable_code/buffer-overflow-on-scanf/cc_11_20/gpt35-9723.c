//FormAI DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int op, num1, num2, ans, correct = 0, incorrect = 0;

    srand(time(NULL)); // for generating random numbers
    printf("\nWelcome to Math Quiz Program!\n");

    do{
        printf("\nPlease select an operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Quit\n");
        scanf("%d", &op);

        if(op == 5){ // If user selects 'Quit'
            printf("\nTotal number of correct answers: %d\n", correct);
            printf("Total number of incorrect answers: %d\n", incorrect);
            printf("Thank you for using Math Quiz Program!\n\n");
            break; // Exit program
        }
        else if(op >= 1 && op <= 4){ // If user selects a valid operation
            num1 = rand() % 101; // Generate random numbers between 0 and 100
            num2 = rand() % 101;

            switch(op){
                case 1: // Addition
                    ans = num1 + num2;
                    printf("\nWhat is %d + %d? ", num1, num2);
                    break;
                case 2: // Subtraction
                    ans = num1 - num2;
                    printf("\nWhat is %d - %d? ", num1, num2);
                    break;
                case 3: // Multiplication
                    ans = num1 * num2;
                    printf("\nWhat is %d x %d? ", num1, num2);
                    break;
                case 4: // Division
                    while(num2 == 0) // Prevent division by zero
                        num2 = rand() % 101;
                    ans = num1 / num2;
                    printf("\nWhat is %d / %d? (Round down to the nearest integer) ", num1, num2);
                    break;
            }

            int userAns;
            scanf("%d", &userAns); // Get user's answer

            if(userAns == ans){ // If user's answer is correct
                printf("Correct! Great job!\n");
                correct++;
            }
            else{ // If user's answer is incorrect
                printf("Sorry, that's incorrect. The correct answer is %d.\n", ans);
                incorrect++;
            }
        }
        else{ // If user selects an invalid operation
            printf("Invalid option. Please try again.\n");
        }
    }while(op != 5); // Run program until user selects 'Quit'

    return 0;
}