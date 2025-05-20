//Falcon-180B DATASET v1.0 Category: Educational ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a message with a delay
void print_delayed(char* message, int delay) {
    printf("%s", message);
    fflush(stdout);
    sleep(delay);
}

int main() {
    int num_cases;
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of cases from the user
    print_delayed("Enter the number of cases: ", 2000);
    scanf("%d", &num_cases);

    // Loop through the cases
    for (i = 1; i <= num_cases; i++) {
        // Generate a random number between 1 and 6
        int case_num = rand_num(1, 6);

        // Print a message based on the case number
        switch (case_num) {
            case 1:
                print_delayed("The game is afoot!", 2000);
                break;
            case 2:
                print_delayed("Elementary, my dear Watson.", 3000);
                break;
            case 3:
                print_delayed("When you have eliminated the impossible, whatever remains, however improbable, must be the truth.", 5000);
                break;
            case 4:
                print_delayed("It is a capital mistake to theorize before one has data.", 4000);
                break;
            case 5:
                print_delayed("I am not a psychopath, I'm a high functioning sociopath. Do your research.", 6000);
                break;
            case 6:
                print_delayed("To a great mind, nothing is little.", 5000);
                break;
            default:
                print_delayed("Invalid case number.", 2000);
                break;
        }

        // Wait for the user to press enter before continuing
        print_delayed("Press enter to continue...", 0);
        getchar();
    }

    return 0;
}