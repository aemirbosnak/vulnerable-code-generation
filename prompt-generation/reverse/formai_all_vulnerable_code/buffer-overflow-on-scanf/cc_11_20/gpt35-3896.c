//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //initialize variables
    int questions = 0, score=0;
    
    //welcome message
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Are you ready to test your knowledge of the elements?\n\n");
    
    //ask user for number of questions
    printf("How many questions would you like to answer? (1-10)\n");
    scanf("%d",&questions);
    
    //make sure number of questions is within range
    if(questions < 1 || questions > 10){
        printf("Invalid input. Please enter a number between 1-10.\n");
        return 1;
    }
    
    //seed for random number generator
    srand(time(NULL));
    
    //question loop
    for(int i=1; i<=questions; i++){
        //generate random element
        int element = rand() % 118 + 1;
        char symbol[3];
        
        //get element symbol
        switch(element){
            case 1:
                sprintf(symbol,"H");
                break;
            case 6:
                sprintf(symbol,"C");
                break;
            case 11:
                sprintf(symbol,"Na");
                break;
            case 15:
                sprintf(symbol,"P");
                break;
            case 19:
                sprintf(symbol,"K");
                break;
            case 29:
                sprintf(symbol,"Cu");
                break;
            case 47:
                sprintf(symbol,"Ag");
                break;
            case 79:
                sprintf(symbol,"Au");
                break;
            default:
                sprintf(symbol,"X");
                break;
        }
        
        //ask question
        printf("\nQuestion %d:\n", i);
        printf("What is the symbol for element %d?\n", element);
        
        //get user answer
        char answer[3];
        scanf("%s", answer);
        
        //convert answer to uppercase
        for(int j=0; j<3; j++){
            if(answer[j] >= 'a' && answer[j] <= 'z'){
                answer[j] = answer[j] - 'a' + 'A';
            }
        }
        
        //check answer
        if(strcmp(answer,symbol)==0){
            printf("Correct!\n");
            score++;
        }else{
            printf("Incorrect. The correct answer is %s.\n",symbol);
        }
    }
    
    //display score
    printf("\nQuiz complete!\n");
    printf("You got %d out of %d questions correct.\n", score, questions);
    
    return 0;
}