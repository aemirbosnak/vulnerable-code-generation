//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to give a fortune based on a number
const char* getFortune(int fortuneNumber) {
    switch (fortuneNumber) {
        case 0: return "You will uncover a hidden talent soon.";
        case 1: return "A long-lost friend will re-enter your life.";
        case 2: return "Adventure awaits; step out of your comfort zone.";
        case 3: return "Expect the unexpected; a surprise is on the horizon.";
        case 4: return "Love is in the air; go out and embrace it.";
        case 5: return "Patience is a virtue; wait for the right moment.";
        case 6: return "Your intuition will guide you; trust it.";
        case 7: return "A new path will open before you; take the leap.";
        case 8: return "Challenges will arise, but you will conquer them.";
        case 9: return "Show kindness to others; it will be returned tenfold.";
        default: return "Fate is a mystery, embrace uncertainty.";
    }
}

// Function to read user's date of birth and calculate fortune
void calculateFortune(int day, int month, int year) {
    int sum = day + month + year;
    
    // Reducing to a single digit
    while (sum >= 10) {
        sum = sum / 10 + sum % 10;
    }
    
    printf("Your fortune is: %s\n", getFortune(sum));
}

// Function to display the menu
void displayMenu() {
    printf("\nWelcome to the Cosmic Fortune Teller!\n");
    printf("1. Get my fortune\n");
    printf("2. Exit\n");
}

// Main function
int main() {
    int choice;
    do {
        displayMenu();
        printf("\nChoose an option: ");
        while (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number: ");
            while (getchar() != '\n'); // clear input buffer
        }

        switch (choice) {
            case 1: {
                int day, month, year;

                // Getting user input
                printf("Enter your date of birth (DD MM YYYY): ");
                while (scanf("%d %d %d", &day, &month, &year) != 3 ||
                       day < 1 || day > 31 ||
                       month < 1 || month > 12 ||
                       (month == 2 && day > 29) || // rough check, not accounting for leap years
                       ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
                    printf("Invalid date. Please try again (DD MM YYYY): ");
                    while (getchar() != '\n'); // clear input buffer
                }

                // Calculate and display fortune
                calculateFortune(day, month, year);
                break;
            }
            case 2:
                printf("Thank you for visiting the Cosmic Fortune Teller. May the stars guide you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 2);

    return 0;
}