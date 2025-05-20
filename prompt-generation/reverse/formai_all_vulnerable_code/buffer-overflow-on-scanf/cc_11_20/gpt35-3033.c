//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int choice;
    time_t t;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    /* Print greeting message */
    printf("Welcome to the Automated Fortune Teller!\n");

    do{
        /* Print options */
        printf("\nChoose an option (1-5):\n");
        printf("1. Predict your future\n");
        printf("2. Predict your love life\n");
        printf("3. Predict your career\n");
        printf("4. Predict your health\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        /* Check user's choice */
        switch(choice){
            case 1:
                /* Predict future */
                if(rand() % 2 == 0){
                    printf("\nYou will have a happy future!\n");
                }
                else{
                    printf("\nYou may face some challenges in your future.\n");
                }
                break;

            case 2:
                /* Predict love life */
                if(rand() % 2 == 0){
                    printf("\nYou are going to meet the love of your life soon!\n");
                }
                else{
                    printf("\nYou may need to work on your relationships.\n");
                }
                break;

            case 3:
                /* Predict career */
                if(rand() % 2 == 0){
                    printf("\nYou will be successful in your career.\n");
                }
                else{
                    printf("\nYou may face some obstacles in your career.\n");
                }
                break;

            case 4:
                /* Predict health */
                if(rand() % 2 == 0){
                    printf("\nYou will enjoy good health!\n");
                }
                else{
                    printf("\nYou may need to take care of your health.\n");
                }
                break;

            case 5:
                /* Exit the program */
                printf("\nThank you for using the Automated Fortune Teller!\n");
                exit(0);

            default:
                /* Invalid option */
                printf("\nInvalid option. Please choose 1-5.\n");
        }
    }while(1);

    return 0;
}