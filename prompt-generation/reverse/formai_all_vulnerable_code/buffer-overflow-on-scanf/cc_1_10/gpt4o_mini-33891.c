//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Let's create a funny and ridiculous arithmetic adventure program!
int main() {
    printf("Welcome to the Crazy Arithmetic Adventure!\n");
    printf("Where the numbers do all the crazy talking!\n");
    
    int choice;
    int num1, num2;

    while (1) {
        printf("\nPick your poison:\n");
        printf("1. Add two numbers (let's make some sweet addition)\n");
        printf("2. Subtract one number from another (when subtraction feels like a breakup)\n");
        printf("3. Multiply two numbers (let's do some explosive math!)\n");
        printf("4. Divide one number by another (careful, it can be a rough ride)\n");
        printf("5. Exit the Crazy Arithmetic Adventure (bail out)\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting the Crazy Arithmetic Adventure. Remember, numbers are always there for you!\n");
            break; // Exit the loop and end the adventure
        }

        printf("Enter your first number: ");
        scanf("%d", &num1);
        printf("Enter your second number: ");
        scanf("%d", &num2);
        
        switch (choice) {
            case 1:
                printf("Adding %d and %d: %d (Sweet math sugar!)\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("Subtracting %d from %d: %d (Ouch, that's a little painful!)\n", num2, num1, num1 - num2);
                break;
            case 3:
                printf("Multiplying %d with %d: %d (Boom! That's explosive!)\n", num1, num2, num1 * num2);
                break;
            case 4:
                if (num2 != 0) {
                    printf("Dividing %d by %d: %.2f (Math in action, don't drop it!)\n", num1, num2, (float)num1 / num2);
                } else {
                    printf("Error: Division by zero! That's like trying to divide a pizza by nothing!\n");
                }
                break;
            default:
                printf("Oops! Invalid choice. Pick a number from 1 to 5, please.\n");
        }

        // Give the users some numbers to ponder
        printf("\nWant to know a math joke?\n");
        printf("Why was the equal sign so humble?\n");
        printf("Because it realized it wasn't less than or greater than anyone else!\n");

        // A mini length check for extra fun
        int length_check = num1 + num2;
        if (length_check > 100) {
            printf("Whoa! Those numbers are longer than my to-do list!\n");
        } else {
            printf("Those numbers are just cozy and comfortable.\n");
        }

        printf("Would you like to continue? (1 for Yes, 0 for No): ");
        int continue_choice;
        scanf("%d", &continue_choice);
        if (continue_choice != 1) {
            printf("Thanks for joining the Crazy Arithmetic Adventure! Until we meet again!\n");
            break;
        }
    }

    // Closing the adventure with a flourish
    printf("\nThe Crazy Arithmetic Adventure is now closed.\n");
    printf("Remember, every calculation counts - even your absences in class!\n");
    printf("Goodbye, and may your future calculations be ever in your favor!\n");

    return 0;
}