//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1-10
int generateRandomNumber(){
    srand(time(NULL));
    int randomNum = rand() % 10 + 1;
    return randomNum;
}

int main(){

    int a, b, c, result;
    char operator;

    printf("Welcome to the wackiest Math Exercise Program of all time!\n");
    printf("Here, you will have to answer Math exercises in the most bizarre way possible.\n");
    printf("Let's get started!\n\n");

    printf("Please enter the number of Math exercises you want to solve (between 1-10): ");
    scanf("%d", &c);

    for(int i=0; i<c; i++){

        // Generating random operands
        a = generateRandomNumber(); 
        b = generateRandomNumber();

        // Generating random operator
        int opNum = generateRandomNumber();
        if(opNum <= 3){
            operator = '+';
            result = a + b;
        }
        else if(opNum <= 6){
            operator = '-';
            result = a - b;
        }
        else if(opNum <= 8){
            operator = '*';
            result = a * b;
        }
        else{
            operator = '/';
            result = a / b;
        }

        printf("\nExercise %d:\n", i+1);
        printf("Solve the following equation in the most amusing way possible:\n%d %c %d = ?\n", a, operator, b);

        // Accepting response
        int answer;
        scanf("%d", &answer);

        // Checking answer
        if(answer == result){
            printf("Superb! You are a Genius!\n");
        }
        else{
            printf("Sadly, your answer is incorrect. Here's what you could have said to make it correct:\n");

            // Generating silly response
            int sillyNum = generateRandomNumber();
            switch(sillyNum){
                case 1:
                    printf("%d %c %d = %d. Wait, what was your question again?\n", a, operator, b, result);
                    break;
                case 2:
                    printf("%d %c %d = %d? No way! The answer cannot be that easy!\n", a, operator, b, answer);
                    break;
                case 3:
                    printf("%d %c %d = %d. Oops, I accidentally memorized the answer!\n", a, operator, b, result);
                    break;
                case 4:
                    printf("%d %c %d = %d. Wait, am I dreaming or are you the one with the wrong answer?\n", a, operator, b, result);
                    break;
                case 5:
                    printf("%d %c %d = %d. Quick, someone call my mom and tell her I aced my Math test!\n", a, operator, b, result);
                    break;
                case 6:
                    printf("%d %c %d = %d. Oh sure, that's the answer. And I am Einstein!\n", a, operator, b, result);
                    break;
                case 7:
                    printf("%d %c %d = %d. Hurray, I just broke the record for the slowest Math solver of all time!\n", a, operator, b, result);
                    break;
                case 8:
                    printf("%d %c %d = %d. Hold on, let me google the answer first!\n", a, operator, b, result);
                    break;
                case 9:
                    printf("%d %c %d = %d. 42. Oh wait, that's the answer to the universe and everything, not this Math exercise!\n", a, operator, b, answer);
                    break;
                case 10:
                    printf("%d %c %d = %d. I am pretty sure that's the answer to a completely different exercise, but good try!\n", a, operator, b, answer);
                    break;
                default:
                    printf("%d %c %d = %d. Sorry, I am a Math exercise program, not a psychic!\n", a, operator, b, answer);
            }
        }

    }

    printf("\n\nThank you for playing the wackiest Math exercise program of all time! I hope you had a good laugh!\n");
    printf("Exiting...");

    return 0;
}