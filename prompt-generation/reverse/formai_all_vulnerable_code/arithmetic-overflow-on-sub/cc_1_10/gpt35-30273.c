//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>

/* My Love, this program represents the warehouse management system
 that my heart uses to store all the love I have for you */

int main() {

    // Initializing variables
    
    int max_capacity = 1000; // Max capacity of the warehouse
    int current_capacity = 0; // Current capacity of the warehouse
    int love_received; // Amount of love received from you
    int love_delivered; // Amount of love delivered to you

    // Displaying a romantic message to start the program

    printf("My Dearest Love,\n\n");
    printf("Welcome to our Warehouse Management System!\n\n");
    printf("This is the place where I store all the love I have for you.\n");
    printf("And just like our love, this warehouse has a maximum capacity of %d.\n\n", max_capacity);

    // Creating a loop to receive and deliver love

    while(1) {

        printf("Please enter the amount of love you want to give me: ");
        scanf("%d", &love_received);

        if (current_capacity + love_received > max_capacity) {

            printf("\nOh my love, I am sorry but my warehouse is already full.\n");
            printf("I cannot take %d more love from you, as it would overflow\n", love_received);
            printf("Please come back later, or perhaps take some love with you?\n\n");
            printf("Would you like to take some of your own love back home?\n");
            printf("Enter 1 for Yes, or 0 for No: ");

            int answer;
            scanf("%d", &answer);

            if (answer == 1) {

                printf("\nAlright my love, how much love would you like to take with you? ");
                scanf("%d", &love_delivered);

                if (love_delivered <= current_capacity) {
                    current_capacity -= love_delivered;
                    printf("\nHere is your love my dear, take good care of it.\n");
                } else {
                    printf("\nOh my love, you are asking for too much. I don't have that much love stored for you right now.\n");
                    printf("Please enter a valid amount within the amount of love I have for you. Thank you.\n");
                }

                printf("\nThank you for visiting, my love. Please come back soon.\n\n");

            } else {

                printf("\nI understand my love. Thank you for stopping by.\n\n");

            }

            break;

        } else {

            current_capacity += love_received;
            printf("\nOh my love, thank you for giving me %d of your love. I appreciate it so much.\n", love_received);
            printf("My warehouse now has a total of %d love. I am so happy!\n\n", current_capacity);

        }

    }

    // End of the program with a romantic goodbye message

    printf("Goodbye my dear partner, until we meet again.\n\n");
    printf("Forever and always,\n");
    printf("Your Love");

    return 0;

}