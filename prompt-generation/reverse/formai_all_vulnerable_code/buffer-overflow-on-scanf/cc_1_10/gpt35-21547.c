//FormAI DATASET v1.0 Category: System administration ; Style: cheerful
// Hello there! Welcome to my happy-go-lucky system administration example program!
// With this program, managing your system has never been so much fun!
// First, let's include the necessary libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/reboot.h>

// Let's define our main function

int main(int argc, char *argv[]) {

    // Let's print a cheerful message to the user

    printf("Welcome to the happiest system administration program in the world!\n");

    // Now let's ask the user what they would like to do

    printf("What would you like to do?\n");
    printf("1. Reboot the system\n");
    printf("2. Shutdown the system\n");

    // Let's declare some variables

    int option;

    // Now let's get the user's option

    scanf("%d", &option);

    // Let's switch on the user's option

    switch (option) {

        // Option 1 is to reboot the system

        case 1:

            // Let's print a message to the user

            printf("Are you sure you want to reboot the system? (y/n)\n");

            // Let's declare some more variables

            char answer;

            // Let's get the user's answer

            scanf(" %c", &answer);

            // Let's check if the user wants to reboot the system

            if (answer == 'y') {

                // Let's print a cheerful message to the user

                printf("Yay! Rebooting the system!\n");

                // Let's reboot the system

                if (reboot(RB_AUTOBOOT) < 0) {

                    // Let's print an error message if the system can't reboot

                    printf("Sorry, the system can't reboot right now. Try again later.\n");

                }

            } else {

                // Let's print a cheerful message to the user

                printf("Okay, let's not reboot the system then!\n");

            }

            // We're all done with option 1!

            break;

        // Option 2 is to shutdown the system

        case 2:

            // Let's print a message to the user

            printf("Are you sure you want to shutdown the system? (y/n)\n");

            // Let's declare some more variables

            char answer2;

            // Let's get the user's answer

            scanf(" %c", &answer2);

            // Let's check if the user wants to shutdown the system

            if (answer2 == 'y') {

                // Let's print a cheerful message to the user

                printf("Yippee! Shutting down the system!\n");

                // Let's shutdown the system

                if (system("sudo shutdown now") < 0) {

                    // Let's print an error message if the system can't shutdown

                    printf("Sorry, the system can't shutdown right now. Try again later.\n");

                }

            } else {

                // Let's print a cheerful message to the user

                printf("Okay, let's not shutdown the system then!\n");

            }

            // We're all done with option 2!

            break;

        // If the user enters an invalid option, let's tell them

        default:

            // Let's print a cheerful message to the user

            printf("Invalid option! Try again!\n");

            // We're done with this switch statement

            break;

    }

    // Let's exit the program!

    printf("Thanks for using my happy-go-lucky system administration program! Goodbye!\n");

    return 0;

}