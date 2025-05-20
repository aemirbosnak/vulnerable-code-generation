//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a fortune
void print_fortune(int fortune_num) {
    switch(fortune_num) {
        case 1:
            printf("You will find great success in your future endeavors.\n");
            break;
        case 2:
            printf("A new love interest will enter your life soon.\n");
            break;
        case 3:
            printf("Financial prosperity is on the horizon for you.\n");
            break;
        case 4:
            printf("You will experience a major life change in the near future.\n");
            break;
        case 5:
            printf("Your hard work will pay off in unexpected ways.\n");
            break;
        default:
            printf("Sorry, no fortune found.\n");
            break;
    }
}

// Main function to run the program
int main() {
    int choice;
    int fortune_num;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Display the menu of options
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please choose an option:\n");
    printf("1. Love\n");
    printf("2. Career\n");
    printf("3. Money\n");
    printf("4. Life\n");
    printf("5. Random\n");

    // Read the user's choice
    scanf("%d", &choice);

    // Generate a random fortune based on the user's choice
    switch(choice) {
        case 1:
            fortune_num = rand_num(1, 3);
            break;
        case 2:
            fortune_num = rand_num(1, 4);
            break;
        case 3:
            fortune_num = rand_num(1, 5);
            break;
        case 4:
            fortune_num = rand_num(1, 5);
            break;
        case 5:
            fortune_num = rand_num(1, 5);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // Print the fortune
    print_fortune(fortune_num);

    return 0;
}