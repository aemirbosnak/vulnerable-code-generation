//FormAI DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

/* User-defined function to display the menu */
void displayMenu() 
{
    printf("\n-----------------------------------------------\n");
    printf("Welcome to the Online Examination System\n");
    printf("-----------------------------------------------\n\n");
    printf("1. Start Exam\n");
    printf("2. View High Scores\n");
    printf("3. Exit\n");
}

/* Main function */
int main() 
{
    int choice;
    char ans;

    do {
        /* Display menu */
        displayMenu();

        /* Get user's choice */
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nStarting the exam...\n");
                /* Add code to start exam */
                break;

            case 2:
                printf("\nViewing high scores...\n");
                /* Add code to view high scores */
                break;

            case 3:
                printf("\nExiting the program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

        /* Ask user if they want to continue */
        printf("\nDo you want to continue? (Y/N) ");
        scanf(" %c", &ans);

    } while(ans == 'y' || ans == 'Y');

    printf("\nThank you for using the Online Examination System!\n");

    return 0;
}