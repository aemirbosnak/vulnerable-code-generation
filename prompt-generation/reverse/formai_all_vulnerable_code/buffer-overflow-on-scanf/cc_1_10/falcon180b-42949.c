//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_fortune(int fortune_index);
int get_random_fortune();

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int user_choice;

    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please select an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                print_fortune(get_random_fortune());
                break;
            case 2:
                printf("Thank you for using the Automated Fortune Teller!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (user_choice!= 2);

    return 0;
}

void print_fortune(int fortune_index) {
    const char* fortunes[] = {
        "You will have a lucky day today.",
        "A pleasant surprise awaits you.",
        "You will meet someone new soon.",
        "Your hard work will pay off.",
        "Good health and happiness are in your future.",
        "You will achieve great success in your endeavors.",
        "A long-awaited opportunity will present itself to you.",
        "You will find true love in the near future.",
        "Your financial situation will improve.",
        "You will overcome any obstacles in your path."
    };

    printf("Your fortune is:\n%s\n", fortunes[fortune_index]);
}

int get_random_fortune() {
    return rand() % 10; // Generate a random number between 0 and 9
}