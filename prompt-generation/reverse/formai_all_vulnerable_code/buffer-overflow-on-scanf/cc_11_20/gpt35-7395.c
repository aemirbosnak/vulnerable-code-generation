//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); //random seed
    
    char playerName[20];
    int age;
    int choice;
    
    //Getting player name and age
    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("What's your name? ");
    scanf("%s", playerName);
    printf("What's your age? ");
    scanf("%d", &age);
    printf("\nOh, hi %s! So you are %d years old! Let's start.\n\n", playerName, age);
    
    //Asking player if they're ready
    printf("Are you ready to know your fortune? Press 1 for yes and 0 for no.\n");
    scanf("%d", &choice);
    
    //Checking if player is ready or not
    if(choice == 0){
        printf("\nOkay, come again when you're ready.\n");
        return 0;
    }
    
    int randomNum = rand() % 10 + 1; //random number generator
    
    //Fortune teller outputs depending on random number generated
    switch(randomNum){
        case 1: printf("You will have a wonderful day today, %s!\n", playerName);
                break;
        case 2: printf("You will meet someone special this week, %s!\n", playerName);
                break;
        case 3: printf("Your hard work and perseverance will pay off, %s!\n", playerName);
                break;
        case 4: printf("You will receive unexpected good news, %s!\n", playerName);
                break;
        case 5: printf("You will have a lucky break in your career, %s!\n", playerName);
                break;
        case 6: printf("You will win a prize very soon, %s!\n", playerName);
                break;
        case 7: printf("Your life will take a big turn in the next few days, %s!\n", playerName);
                break;
        case 8: printf("You will experience a lot of growth and learning this month, %s!\n", playerName);
                break;
        case 9: printf("You will travel to a new country soon, %s!\n", playerName);
                break;
        case 10: printf("Your romantic life will improve, %s!\n", playerName);
                break;
        default: printf("\nInvalid input. Please try again later.\n");
    }
    
    printf("\nThank you for trusting the Automated Fortune Teller. Have a great day!");
    
    return 0;
}