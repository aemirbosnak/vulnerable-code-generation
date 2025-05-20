//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_FORTUNES 10

const char *fortunes[NUMBER_OF_FORTUNES] = {
    "You will receive an unexpected gift.",
    "A great opportunity is waiting for you.",
    "Your future is bright, do not lose hope.",
    "Travel is in your future; pack your bags!",
    "Your hard work will soon be rewarded.",
    "A new friendship will bring you joy.",
    "You will discover something new about yourself.",
    "An adventure lies ahead; embrace it!",
    "You will find clarity in a confusing situation.",
    "A financial blessing is on the way."
};

void display_menu() {
    printf("********************************************\n");
    printf("*           Welcome to Fortune Teller     *\n");
    printf("********************************************\n");
    printf("1. Get a fortune\n");
    printf("2. Exit\n");
    printf("********************************************\n");
}

void get_fortune() {
    int index = rand() % NUMBER_OF_FORTUNES;  // Random index for fortunes
    printf("Your fortune: %s\n", fortunes[index]);
}

int main() {
    int choice;
    
    // Seed the random number generator
    srand(time(NULL));

    while (1) {
        display_menu();
        printf("Please enter your choice (1 or 2): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        } else if (choice == 1) {
            get_fortune();
        } else if (choice == 2) {
            printf("Thank you for visiting the Fortune Teller! Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please choose 1 or 2.\n");
        }
    }
    
    return 0;
}