//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Declare variables
    int num, fortuneNum;
    char response;
    
    // Prompt user to ask the fortune teller a question
    printf("Welcome to the automated fortune teller. Ask your question, and I will give you the answer.\n");
    
    // Loop until they want to quit
    do {
        // Prompt user for a question
        printf("Type in your question: ");
        scanf("%d", &num);
        
        // Generate a random number to select the fortune
        fortuneNum = rand() % 5;
        
        // Print the fortune
        switch(fortuneNum) {
            case 0:
                printf("The answer is yes.\n");
                break;
            case 1:
                printf("The answer is no.\n");
                break;
            case 2:
                printf("It's impossible to say for sure at this time.\n");
                break;
            case 3:
                printf("Ask again later.\n");
                break;
            case 4:
                printf("I prefer not to answer that question.\n");
                break;
        }
        
        // Prompt user if they want to ask another question
        printf("Do you have another question? (y/n) ");
        scanf(" %c", &response);
    } while(response == 'y' || response == 'Y');
    
    // End program
    printf("Thank you for visiting the automated fortune teller.\n");
    return 0;
}