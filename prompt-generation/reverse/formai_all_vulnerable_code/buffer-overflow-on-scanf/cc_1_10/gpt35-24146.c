//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void displayWelcomeMessage();

int main(){
    displayWelcomeMessage();
    int choice;
    srand(time(NULL));
    do {
        printf("\nEnter anything to know your fortune (0 to quit): ");
        scanf("%d",&choice);
        int rndm = rand()%10;
        switch (rndm) {
            case 0:
                printf("\nYou will have an unexpected encounter with someone today!");
                break;
            case 1:
                printf("\nGood news is on its way to you today!");
                break;
            case 2:
                printf("\nYou will receive an unexpected gift sometime this week!");
                break;
            case 3:
                printf("\nYou will find great success in a personal project you are working on!");
                break;
            case 4:
                printf("\nYou will unexpectedly run into an old friend today!");
                break;
            case 5:
                printf("\nYou will get a promotion at your job soon!");
                break;
            case 6:
                printf("\nYou will have good health for the next few months!");
                break;
            case 7:
                printf("\nA long distance friend will surprise you with a visit!");
                break;
            case 8:
                printf("\nYour hard work will pay off in the near future!");
                break;
            case 9:
                printf("\nYou will meet someone who will change your life for the better!");
                break;
        } //end of switch
    } while (choice != 0);
    printf("\nThank you for using the Automated Fortune Teller!\n");
    return 0;
} //end of main function

void displayWelcomeMessage(){
    printf("**************************************************\n");
    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("**************************************************\n");
    printf("\nThis program allows you to get a random prediction about your day!");
} //end of displayWelcomeMessage function