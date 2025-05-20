//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible fortunes
#define FORTUNE_COUNT 10
char *fortunes[FORTUNE_COUNT] = {
    "You will have a great day today!",
    "A new opportunity will come your way soon.",
    "Your hard work will pay off in the future.",
    "You will meet someone special today.",
    "You will receive good news in the near future.",
    "A friend will need your help today.",
    "You will experience a moment of clarity.",
    "You will have a lucky streak in the coming days.",
    "You will find a lost item today.",
    "You will be surprised by a gift."
};

// Function to generate a random number between 0 and n-1
int rand_int(int n) {
    return rand() % n;
}

// Function to print a random fortune
void print_fortune(void) {
    int fortune_index = rand_int(FORTUNE_COUNT);
    printf("%s\n", fortunes[fortune_index]);
}

// Function to run the fortune teller
void run_fortune_teller(void) {
    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                print_fortune();
                break;
            case 2:
                printf("Thank you for using the Automated Fortune Teller!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 2);
}

// Main function
int main(void) {
    srand(time(NULL)); // Seed the random number generator with the current time
    run_fortune_teller();
    return 0;
}