//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the maximum number of time travel attempts
#define MAX_ATTEMPTS 10

// Define the maximum number of years to travel back in time
#define MAX_YEARS_BACK 100

// Define the maximum number of years to travel forward in time
#define MAX_YEARS_FORWARD 100

// Define the function to generate a random number between 1 and n (inclusive)
int rand_int(int n) {
    return rand() % n + 1;
}

// Define the function to generate a random time travel destination
int rand_destination() {
    int destination = rand_int(3);
    if (destination == 0) {
        return -1;
    } else if (destination == 1) {
        return rand_int(MAX_YEARS_BACK) - 1;
    } else {
        return rand_int(MAX_YEARS_FORWARD) + 1;
    }
}

// Define the function to print the time travel menu
void print_menu() {
    printf("Time Travel Menu:\n");
    printf("1. Travel back in time\n");
    printf("2. Travel forward in time\n");
    printf("3. Quit\n");
}

// Define the function to prompt for user input
int prompt_user() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Define the function to check if time travel was successful
int check_success(int destination, int attempts) {
    if (destination == -1) {
        printf("Time travel failed.\n");
        return 0;
    } else if (destination == attempts) {
        printf("Time travel successful.\n");
        return 1;
    } else {
        printf("Time travel incomplete.\n");
        return 0;
    }
}

// Define the main function
int main() {
    srand(time(NULL));
    int attempts = 0;
    int destination;
    int choice;

    while (attempts < MAX_ATTEMPTS) {
        print_menu();
        choice = prompt_user();

        switch (choice) {
        case 1:
            destination = rand_destination();
            if (destination == -1) {
                printf("Time travel failed.\n");
            } else {
                printf("Traveling back in time to %d...\n", destination);
                attempts++;
            }
            break;
        case 2:
            destination = rand_destination();
            if (destination == -1) {
                printf("Time travel failed.\n");
            } else {
                printf("Traveling forward in time to %d...\n", destination);
                attempts++;
            }
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }

        if (attempts >= MAX_ATTEMPTS) {
            printf("Max attempts reached. Exiting program.\n");
        }
    }

    return 0;
}