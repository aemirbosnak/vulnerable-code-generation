//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a random fortune
void print_fortune(int fortune_number) {
    switch (fortune_number) {
        case 1:
            printf("You will have good luck today.\n");
            break;
        case 2:
            printf("A new opportunity will come your way.\n");
            break;
        case 3:
            printf("You will receive a surprise gift.\n");
            break;
        case 4:
            printf("Your hard work will pay off soon.\n");
            break;
        case 5:
            printf("A friend will help you in a time of need.\n");
            break;
        case 6:
            printf("You will overcome a challenge.\n");
            break;
        case 7:
            printf("Love is in the air.\n");
            break;
        case 8:
            printf("You will have a peaceful day.\n");
            break;
        case 9:
            printf("You will learn something new.\n");
            break;
        case 10:
            printf("You will have a successful day.\n");
            break;
        default:
            printf("Sorry, that fortune is not available.\n");
            break;
    }
}

int main() {
    int fortunes[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    int user_choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Print a welcome message
    printf("Welcome to the Automated Fortune Teller!\n\n");

    // Ask the user to choose a fortune
    printf("Please choose a number between 1 and %d:\n", num_fortunes);
    scanf("%d", &user_choice);

    // Check if the user's choice is valid
    if (user_choice < 1 || user_choice > num_fortunes) {
        printf("Invalid choice. Please choose a number between 1 and %d.\n", num_fortunes);
        return 1;
    }

    // Generate a random fortune and print it
    int fortune_number = random_number(1, num_fortunes);
    print_fortune(fortune_number);

    return 0;
}