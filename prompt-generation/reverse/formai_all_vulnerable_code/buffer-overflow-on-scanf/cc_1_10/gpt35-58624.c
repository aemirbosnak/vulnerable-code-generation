//FormAI DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    /*initialize variables*/
    int num1, num2, result, guess;
    char operator;
    int correct_guesses = 0;
    int total_guesses = 0;
    
    srand(time(NULL)); /*seed random number generator*/
    
    printf("Welcome to Math Exercise Game! \n");    
    printf("You will be given two random numbers and a mathematical operator (+,-,* or /).\n");    
    printf("Your task is to solve the problem and provide the correct answer.\n");    
    printf("You will be awarded one point for each correct answer.\n");    
    printf("Are you Ready? Let's begin! \n\n");
           
    while(1){
        /*Generate random numbers between 1-100*/
        num1 = rand()%100 + 1;
        num2 = rand()%100 + 1;
        
        /*Generate random operator*/
        switch(rand()%4){
            case 0:
                operator = '+';
                result = num1 + num2;
                break;
            case 1:
                operator = '-';
                result = num1 - num2;
                break;
            case 2:
                operator = '*';
                result = num1 * num2;
                break;
            case 3:
                operator = '/';
                result = num1 / num2;
                break;
        }
        
        printf("Problem %d: %d %c %d = ? \n", total_guesses+1, num1, operator, num2);
        scanf("%d", &guess);
        
        /*check if user guess is correct*/
        if(guess == result){
            printf("Congratulations! You got it right. \n");
            correct_guesses++;
        }
        else{
            printf("Sorry, the correct answer is %d. \n", result);
        }
        
        total_guesses++;
        
        /*Ask user if they want to continue or quit*/
        printf("Do you want to continue? (Y/N) \n");
        char c;
        scanf(" %c", &c);
        if(c == 'N' || c == 'n'){
            break;
        }
    }
    
    float percentage = ((float)correct_guesses/total_guesses) * 100;
    printf("\nYou answered %d out of %d questions correctly.\n", correct_guesses, total_guesses);
    printf("Your score is %.2f percent. \n", percentage);
    
    /*end program*/
    return 0;    
}