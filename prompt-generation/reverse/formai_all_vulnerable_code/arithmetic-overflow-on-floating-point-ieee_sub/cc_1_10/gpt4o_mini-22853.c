//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>

void displayMenu() {
    printf("\n=====================================\n");
    printf("          Grateful Arithmetic        \n");
    printf("=====================================\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulo (%%)\n");
    printf("6. Exit\n");
    printf("=====================================\n");
}

int main() {
    int choice;
    double num1, num2, result;
    
    printf("Welcome to the Grateful Arithmetic Program! \n");
    printf("Thank you for the opportunity to perform calculations for you. \n");
    
    do {
        // Display menu
        displayMenu();
        printf("Please choose an option (1-6): ");
        scanf("%d", &choice);
        
        // Check if the user wants to exit
        if (choice == 6) {
            printf("Thank you for using Grateful Arithmetic! Have a great day!\n");
            break;
        }

        // Get numbers from user
        printf("Please enter the first number: ");
        scanf("%lf", &num1);
        printf("Please enter the second number: ");
        scanf("%lf", &num2);
        
        // Perform the chosen operation
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Adding %.2f and %.2f, we have: %.2f\n", num1, num2, result);
                printf("Thank you for spreading positivity through numbers!\n");
                break;
            case 2:
                result = num1 - num2;
                printf("Subtracting %.2f from %.2f, we get: %.2f\n", num2, num1, result);
                printf("Your calculations inspire me to keep going!\n");
                break;
            case 3:
                result = num1 * num2;
                printf("Multiplying %.2f with %.2f results in: %.2f\n", num1, num2, result);
                printf("Every number has its own story, and I'm grateful to tell it!\n");
                break;
            case 4:
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Dividing %.2f by %.2f gives: %.2f\n", num1, num2, result);
                    printf("Thank you for sharing your numbers with me!\n");
                } else {
                    printf("Whoa! Division by zero is not possible. Please try again.\n");
                    printf("Grateful for your understanding on this matter.\n");
                }
                break;
            case 5:
                if ((int)num2 != 0) {
                    result = (int)num1 % (int)num2;
                    printf("The remainder of %.2f divided by %.2f is: %.2f\n", num1, num2, result);
                    printf("Thank you for the opportunity to explore divisions together!\n");
                } else {
                    printf("Whoa! Modulo by zero isn't allowed. Please correct that.\n");
                    printf("I'm grateful for your patience!\n");
                }
                break;
            default:
                printf("Invalid choice. Thank you for trying to engage with me!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}