//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>

void printSeparator() {
    printf("\n========================================\n");
}

void displayMenu() {
    printf("🎉 Welcome to the Cheerful Arithmetic Program! 🎉\n");
    printf("Let's add some fun to your calculations!\n");
    printSeparator();
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printSeparator();
}

int main() {
    int choice;
    float num1, num2, result;

    do {
        displayMenu();
        printf("Please choose an operation (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Thank you for using the Cheerful Arithmetic Program! Bye-bye! 🎈\n");
            break;
        }

        printf("🎈 Great choice! Now, let's have some fun with numbers!\n");
        printf("Please enter the first number: ");
        scanf("%f", &num1);
        printf("Please enter the second number: ");
        scanf("%f", &num2);

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("🎊 Hooray! The result of %.2f + %.2f is: %.2f\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("😄 Yay! The result of %.2f - %.2f is: %.2f\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("🌟 Awesome! The result of %.2f * %.2f is: %.2f\n", num1, num2, result);
                break;
            case 4:
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("✨ Woohoo! The result of %.2f / %.2f is: %.2f\n", num1, num2, result);
                } else {
                    printf("🚫 Oops! Division by zero is not allowed! Please try again with a different number.\n");
                }
                break;
            default:
                printf("🤔 Hmm, that doesn't look like a valid option! Give it another shot!\n");
                break;
        }

        printSeparator();
    } while (choice != 5);

    return 0;
}