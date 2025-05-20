//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>
#include <math.h>

// Define the conversion factors
#define C_TO_F (9.0/5.0)
#define F_TO_C (5.0/9.0)

int main() {
    double celsius, fahrenheit;
    char choice;

    // Continue the loop until the user chooses to quit
    while(1) {
        // Display the menu
        printf("\n");
        printf("Celsius to Fahrenheit Converter\n");
        printf("---------------------------------\n");
        printf("C -> F\n");
        printf("F -> C\n");
        printf("Q -> Quit\n");

        // Get the user's choice
        scanf("%c", &choice);

        // Convert the choice to uppercase
        choice = toupper(choice);

        // Perform the conversion based on the user's choice
        if(choice == 'C') {
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &celsius);
            printf("%.2lfC = %.2lfF\n", celsius, celsius * C_TO_F);
        }
        else if(choice == 'F') {
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);
            printf("%.2lfF = %.2lfC\n", fahrenheit, (fahrenheit - 32) * F_TO_C);
        }
        else if(choice == 'Q') {
            // Exit the loop and end the program
            break;
        }
        else {
            // Invalid choice, display an error message
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}