//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void displayWelcomeMessage() {
    printf("*****************************************\n");
    printf("*      Welcome to the Speed Test App!  *\n");
    printf("*    Gratefully brought to you by C!    *\n");
    printf("*****************************************\n\n");
}

void runSpeedTest() {
    printf("Thank you for your patience while we test your internet speed...\n");
    printf("Please ensure you have 'speedtest-cli' installed.\n");
    printf("This may take a minute...\n\n");

    // Execute the speed test command
    int result = system("speedtest-cli --simple");

    // Check if the command was successful
    if (result == -1) {
        fprintf(stderr, "Error: Unable to run speed test. Please make sure speedtest-cli is installed.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nSpeed Test completed. Thank you for using our app!\n");
}

void displayExitMessage() {
    printf("\n*****************************************\n");
    printf("*        Thank you for using our app!  *\n");
    printf("*    Wishing you a wonderful Internet!   *\n");
    printf("*****************************************\n");
}

int main() {
    int choice;

    displayWelcomeMessage();

    while (1) {
        printf("Would you like to test your internet speed? (1: Yes, 0: No): ");
        scanf("%d", &choice);

        if (choice == 1) {
            runSpeedTest();
        } else if (choice == 0) {
            displayExitMessage();
            break;
        } else {
            printf("Invalid option. Please enter 1 or 0.\n");
        }
    }

    return 0;
}