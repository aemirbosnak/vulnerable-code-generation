//FormAI DATASET v1.0 Category: System boot optimizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed the random number generator with current time

    printf("Welcome to the C System boot optimizer.\n\n");
    printf("Your PC is running slower than usual, and we're here to help!\n");
    printf("Our team of skilled blacksmiths have crafted a tool that will optimize your PC's boot time, and get you back to slaying dragons in no time.\n");

    // Ask user if they want to use the boot optimizer
    char answer;
    printf("\n\nWould you like to use our boot optimizer? (y/n) ");
    scanf(" %c", &answer);

    if (answer == 'y' || answer == 'Y') {
        printf("\nFantastic! Let's get started.\n");
        printf("We'll need to increase the number of horses powering your PC's engine.\n");

        // Generate random number of horses between 50 and 100
        int num_horses = rand() % 51 + 50;
        printf("We've added %d horses to your engine.\n", num_horses);

        printf("Next, we'll need to clear any unnecessary files from your system.\n");
        printf("Our team of trusty squires will be happy to help with this task.\n");

        printf("Please enter the number of squires you'd like to help with this task: ");
        int num_squires;
        scanf("%d", &num_squires);

        // Generate random amount of time it will take the squires to finish the task
        int time_taken = rand() % 31 + 30;
        printf("%d squires will be working on this task, and it will take them approximately %d minutes to complete.\n", num_squires, time_taken);

        printf("Finally, we'll need to sprinkle some dragon's blood on your motherboard.\n");
        printf("Don't worry, it's perfectly safe.\n");

        // Generate random chance of success/failure
        int chance_of_success = rand() % 101;
        if (chance_of_success > 50) {
            printf("Success! The dragon's blood has worked its magic, and your PC is now optimized.\n");
        } else {
            printf("Uh oh, it looks like the dragon's blood didn't work as intended.\n");
            printf("Please try again later, or contact our support team for further assistance.\n");
        }
    } else if (answer == 'n' || answer == 'N') {
        printf("\nNo worries, we understand.\n");
        printf("If you change your mind in the future, simply run this program again.\n");
    } else {
        printf("\nInvalid input. Please try again.\n");
    }

    return 0;
}