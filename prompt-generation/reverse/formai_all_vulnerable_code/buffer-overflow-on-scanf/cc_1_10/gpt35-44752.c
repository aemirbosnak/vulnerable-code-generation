//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int choice;
    char repeat;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Welcome message
    printf("Welcome to the Automated Fortune Teller!\n\n");
    
    do {
        // Prompt user for a question
        printf("Please enter your yes or no question: ");
        
        // Clear any previous input
        fflush(stdin);
        
        // Read the user's question
        char question[100];
        fgets(question, 100, stdin);
        printf("\n");
        
        // Generate a random number between 0 and 2
        int answer = rand() % 3;
        
        // Output the answer based on the random number
        if (answer == 0) {
            printf("The answer to your question is: Yes.\n");
        } else if (answer == 1) {
            printf("The answer to your question is: No.\n");
        } else {
            printf("The answer to your question is: Maybe.\n");
        }
        
        // Prompt user to repeat
        printf("\nWould you like to ask another question? (y/n) ");
        scanf("%c", &repeat);
        printf("\n");
    } while (repeat == 'y' || repeat == 'Y');
    
    // Goodbye message
    printf("Thank you for using the Automated Fortune Teller!\n");
    
    return 0;
}