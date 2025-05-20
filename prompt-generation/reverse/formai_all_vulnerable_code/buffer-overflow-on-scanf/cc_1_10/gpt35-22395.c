//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int num, answer;
    
    // Seeding the random number generator
    srand(time(0));
    
    // Generating a random number between 1 and 100
    num = rand() % 100 + 1;
    
    // Prompting the user to enter their question
    printf("Welcome to the Automated Fortune Teller! Please enter your question:\n");
    
    // Reading in the user's question
    char question[100];
    scanf("%[^\n]", question);
    
    // Calculating the answer to the user's question
    answer = num * strlen(question) % 101;
    
    // Generating the fortune based on the answer
    if(answer <= 10){
        printf("The answer to your question is: Definitely no.\n");
    }
    else if(answer <= 20){
        printf("The answer to your question is: Probably not.\n");
    }
    else if(answer <= 40){
        printf("The answer to your question is: It's possible, but not likely.\n");
    }
    else if(answer <= 60){
        printf("The answer to your question is: 50/50 chance.\n");
    }
    else if(answer <= 80){
        printf("The answer to your question is: It's possible.\n");
    }
    else if(answer <= 90){
        printf("The answer to your question is: Most likely.\n");
    }
    else{
        printf("The answer to your question is: Definitely yes!\n");
    }
    
    return 0;
    
}