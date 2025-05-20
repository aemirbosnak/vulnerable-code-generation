//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void fortune_teller()
{
    int answer, random_num;
    
    // seed the random number generator
    srand(time(NULL));
    
    printf("Welcome to the Fortune Teller! \n\n");
    printf("Choose a number between 1-5 to receive your fortune: ");
    
    // get user input
    scanf("%d", &answer);
    
    // generate random number between 1-5
    random_num = (rand() % 5) + 1;
    
    // check if user input is valid
    if(answer < 1 || answer > 5) {
        printf("\nInvalid input. Please choose a number between 1-5. \n\n");
        fortune_teller();
    }
    else {
        // display fortune based on random number generated
        switch(random_num) {
            case 1:
                printf("\nYou will have a blessed day today. \n");
                break;
            case 2:
                printf("\nYour hard work will pay off soon. \n");
                break;
            case 3:
                printf("\nA surprise is coming your way. Stay positive. \n");
                break;
            case 4:
                printf("\nYour creativity will be at its peak today. \n");
                break;
            case 5:
                printf("\nYour determination will help you achieve your goals. \n");
                break;
        }
        
        // ask if user wants another fortune
        printf("\nWould you like another fortune? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        
        if(choice == 'y' || choice == 'Y') {
            fortune_teller();
        }
        else if(choice == 'n' || choice == 'N') {
            printf("\nThank you for visiting the Fortune Teller. Goodbye! \n");
        }
        else {
            printf("\nInvalid input. Goodbye! \n");
        }
    }
}

int main()
{
    fortune_teller();
    return 0;
}