//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    char answer;
    int score = 0;
    int atomicNumber;
    
    printf("Welcome to the Periodic Table quiz!\n\n");

    do{
        printf("What is the atomic number of Platinum? \n");
        printf("A) 71\n");
        printf("B) 78\n");
        printf("C) 80\n\n");
        scanf(" %c", &answer);
    
        if(answer == 'C' || answer == 'c'){
            printf("Correct!\n");
            score++;
        }else{
            printf("Incorrect! The correct answer is C) 80.\n");
        }

        printf("\nWhat is the symbol for Sodium? \n");
        printf("A) S\n");
        printf("B) Na\n");
        printf("C) N\n\n");
        scanf(" %c", &answer);
    
        if(answer == 'B' || answer == 'b'){
            printf("Correct!\n");
            score++;
        }else{
            printf("Incorrect! The correct answer is B) Na.\n");
        }

        printf("\nWhat is the atomic number of Oxygen? \n");
        printf("A) 6\n");
        printf("B) 8\n");
        printf("C) 16\n\n");
        scanf(" %c", &answer);
    
        if(answer == 'B' || answer == 'b'){
            printf("Correct!\n");
            score++;
        }else{
            printf("Incorrect! The correct answer is B) 8.\n");
        }

        printf("\nWhat is the symbol for Helium? \n");
        printf("A) H\n");
        printf("B) He\n");
        printf("C) Ho\n\n");
        scanf(" %c", &answer);
    
        if(answer == 'B' || answer == 'b'){
            printf("Correct!\n");
            score++;
        }else{
            printf("Incorrect! The correct answer is B) He.\n");
        }

        printf("\nWhat is the atomic number of Chlorine? \n");
        printf("A) 16\n");
        printf("B) 17\n");
        printf("C) 37\n\n");
        scanf(" %c", &answer);
    
        if(answer == 'B' || answer == 'b'){
            printf("Correct!\n");
            score++;
        }else{
            printf("Incorrect! The correct answer is B) 17.\n");
        }

        printf("\nWhat is the symbol for Iron? \n");
        printf("A) Ir\n");
        printf("B) Fe\n");
        printf("C) I\n\n");
        scanf(" %c", &answer);
    
        if(answer == 'B' || answer == 'b'){
            printf("Correct!\n");
            score++;
        }else{
            printf("Incorrect! The correct answer is B) Fe.\n");
        }

        printf("\nWhat is the atomic number of Zinc? \n");
        printf("A) 30\n");
        printf("B) 40\n");
        printf("C) 50\n\n");
        scanf(" %c", &answer);
    
        if(answer == 'A' || answer == 'a'){
            printf("Correct!\n");
            score++;
        }else{
            printf("Incorrect! The correct answer is A) 30.\n");
        }

    }while(score < 5);
    
    printf("\nCongratulations! You got %d out of 7.\n", score);
    
    if(score == 7){
        printf("Amazing! You are a true Periodic Table expert!\n");
    }else if(score >= 5 && score <= 6){
        printf("Great job! You definitely know your way around the Periodic Table.\n");
    }else{
        printf("Keep studying! You'll get there eventually.\n");
    }
    
    return 0;
}