//FormAI DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a function to generate a random integer between two numbers
int generateRandomInt(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){
    int num1, num2, answer, userAnswer, correct = 0, total = 0;
    char operation;

    // Seed the random number generator with current time
    srand(time(0));
    
    printf("Welcome to Configurable Math Exercise Program\n\n");
    printf("Choose the type of operation:\n");
    printf("For addition enter +\n");
    printf("For subtraction enter -\n");
    printf("For multiplication enter *\n");
    printf("For division enter /\n");

    // Prompt the user to select the operation type
    scanf("%c", &operation);

    printf("\nHow many questions do you want to attempt? ");
    scanf("%d", &total);

    printf("\n--------------------\n");

    // Loop for generating and evaluating the questions
    for(int i=0; i<total; i++){
        num1 = generateRandomInt(1, 100);
        num2 = generateRandomInt(1, 100);
        
        if(operation == '+'){
            printf("%d. %d %c %d = ", i+1, num1, operation, num2);
            answer = num1 + num2;
        }
        else if(operation == '-'){
            // Make sure the first number is greater than the second number
            if(num2 > num1){
                int temp = num1;
                num1 = num2;
                num2 = temp;
            }
            printf("%d. %d %c %d = ", i+1, num1, operation, num2);
            answer = num1 - num2;
        }
        else if(operation == '*'){
            printf("%d. %d %c %d = ", i+1, num1, operation, num2);
            answer = num1 * num2;
        }
        else if(operation == '/'){
            // Make sure the first number is divisible by the second number
            while(num1%num2 != 0){
                num1 = generateRandomInt(1, 100);
                num2 = generateRandomInt(1, 100);
            }
            printf("%d. %d %c %d = ", i+1, num1, operation, num2);
            answer = num1 / num2;
        }
        else{
            printf("Invalid operation type selected!");
            exit(0);
        }

        // Prompt user for answer and check if it is correct
        scanf("%d", &userAnswer);
        if(userAnswer == answer){
            printf("Correct!\n");
            correct++;
        }
        else{
            printf("Incorrect. The correct answer is %d\n", answer);
        }

        printf("\n");
    }

    printf("\n--------------------\n");
    printf("You answered %d/%d questions correctly.\n", correct, total);

    return 0;
}