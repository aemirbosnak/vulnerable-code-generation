//FormAI DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int choice, num1, num2, result, answer, correct = 0, wrong = 0;
    
    printf("Welcome to the math quiz!\n");
    printf("How many questions would you like to answer?\n");
    scanf("%d", &choice);
    
    srand(time(NULL)); // Initialize random function with seed
    
    for(int i = 0; i < choice; i++){
        num1 = rand() % 100; // Generate random number 1
        num2 = rand() % 100; // Generate random number 2
        
        printf("\nQuestion %d: ", i+1);
        
        switch(rand() % 3){ // Random operator generator
            case 0:
                printf("%d + %d = ", num1, num2);
                result = num1 + num2;
                break;
            case 1:
                printf("%d - %d = ", num1, num2);
                result = num1 - num2;
                break;
            case 2:
                printf("%d * %d = ", num1, num2);
                result = num1 * num2;
                break;
            case 3:
                printf("%d / %d = ", num1, num2);
                result = num1 / num2;
                break;
        }
        
        scanf("%d", &answer);
        
        if (answer == result){
            printf("Correct\n");
            correct++;
        }
        else {
            printf("Wrong! The answer is %d\n", result);
            wrong++;
        }
    }
    
    printf("\nTotal correct answers: %d", correct);
    printf("\nTotal wrong answers: %d", wrong);
    
    if (correct > wrong){
        printf("\nCongratulations, you passed the quiz!");
    }
    else{
        printf("\nSorry, you failed the quiz.");
    }
    
    return 0;
}