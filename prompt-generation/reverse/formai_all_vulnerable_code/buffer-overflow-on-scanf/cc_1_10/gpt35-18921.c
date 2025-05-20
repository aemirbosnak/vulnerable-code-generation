//FormAI DATASET v1.0 Category: Data validation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int age, pin;
    char name[20], choice;

    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);

    // Check that name only contains letters
    for (int i = 0; name[i] != '\n'; i++) {
        if (!isalpha(name[i])) {
            printf("Invalid name. Please try again.\n");
            return 1;
        }
    }

    printf("Please enter your age: ");
    scanf("%d", &age);

    // Check that age is between 18 and 65
    if (age < 18 || age > 65) {
        printf("You must be between 18 and 65 years old.\n");
        return 1;
    }

    printf("Please enter your 4-digit PIN: ");
    scanf("%d", &pin);

    // Check that pin is exactly 4 digits
    if (pin < 1000 || pin > 9999) {
        printf("PIN must be exactly 4 digits.\n");
        return 1;
    }

    printf("Thank you, %s! Your information has been saved.\n", name);

    // Prompt user to continue or exit
    printf("Would you like to continue? (y/n) ");
    scanf(" %c", &choice);

    // Check that user has entered 'y' or 'n'
    while (choice != 'y' && choice != 'n') {
        printf("Invalid choice. Please enter 'y' or 'n'.\n");
        scanf(" %c", &choice);
    }

    if (choice == 'n') {
        printf("Goodbye!\n");
        return 0;
    }

    return 0;
}