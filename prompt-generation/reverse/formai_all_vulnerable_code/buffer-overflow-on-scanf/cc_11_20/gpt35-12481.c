//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables and arrays
    int lucky_numbers[6];
    int user_numbers[6];
    int matching_numbers = 0;
    int bonus_number;
    int user_bonus_number;
    
    // Ask user for their lucky numbers
    printf("Welcome to the automated fortune teller!\n");
    printf("Please enter 6 lucky numbers between 1 and 49.\n");
    
    for (int i = 0; i < 6; i++) {
        printf("Number %d: ", i+1);
        scanf("%d", &user_numbers[i]);
        
        // Check if user input is valid
        if (user_numbers[i] < 1 || user_numbers[i] > 49) {
            printf("Invalid input. Please enter a number between 1 and 49.\n");
            i--;
        }
        
        // Check if user input is unique
        for (int j = 0; j < i; j++) {
            if (user_numbers[i] == user_numbers[j]) {
                printf("Duplicate number. Please enter a unique number.\n");
                i--;
            }
        }
    }
    
    // Generate random lucky numbers
    srand(time(NULL));  // Seed random number generator
    for (int i = 0; i < 6; i++) {
        int number = rand() % 49 + 1;
        
        // Check if lucky number is unique
        for (int j = 0; j < i; j++) {
            if (number == lucky_numbers[j]) {
                number = rand() % 49 + 1;
                j = -1;  // Reset loop to check for uniqueness again
            }
        }
        
        // Add lucky number to array
        lucky_numbers[i] = number;
    }
    
    // Generate random bonus number for lucky numbers
    bonus_number = rand() % 49 + 1;
    
    // Print user's lucky numbers and the winning numbers
    printf("\nYour lucky numbers are: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", user_numbers[i]);
    }
    printf("\n");
    
    printf("The winning numbers are: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", lucky_numbers[i]);
        
        // Check if user's lucky number matches winning numbers
        for (int j = 0; j < 6; j++) {
            if (user_numbers[j] == lucky_numbers[i]) {
                matching_numbers++;
            }
        }
    }
    
    // Print bonus number for lucky numbers
    printf("\nBonus number: %d\n", bonus_number);
    
    // Ask user for their bonus number
    printf("\nPlease enter your bonus number between 1 and 49.\n");
    scanf("%d", &user_bonus_number);
    
    // Check if user input is valid
    if (user_bonus_number < 1 || user_bonus_number > 49) {
        printf("Invalid input. Please enter a number between 1 and 49.\n");
        return 0;
    }
    
    // Check if user's bonus number matches winning bonus number
    if (user_bonus_number == bonus_number) {
        printf("Congratulations! You matched the bonus number!\n");
        matching_numbers++;
    }
    
    // Print number of matching numbers and corresponding prize
    printf("You matched %d numbers.\n", matching_numbers);
    switch (matching_numbers) {
        case 3:
            printf("You win a bottle of Coke.\n");
            break;
        case 4:
            printf("You win a book.\n");
            break;
        case 5:
            printf("You win a trip to Paris.\n");
            break;
        case 6:
            printf("You win the jackpot!\n");
            break;
        default:
            printf("Sorry, no prize this time. Better luck next time!\n");
    }
    
    return 0;
}