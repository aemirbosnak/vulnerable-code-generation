//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

// Function prototypes
void displayMenu();
int getUserInput();
void performBitwiseOperations(int num1, int num2);
void showResults(int num1, int num2, int andResult, int orResult, int xorResult, int notNum1, int notNum2, int leftShiftNum1, int leftShiftNum2, int rightShiftNum1, int rightShiftNum2);

int main() {
    int num1, num2;
    char choice;

    printf("Welcome to the Bitwise Operations Explorer!\n");
    printf("Let's embark on a journey to explore how bitwise operations work.\n\n");

    do {
        printf("Please enter the first number: ");
        num1 = getUserInput();
        
        printf("Please enter the second number: ");
        num2 = getUserInput();
        
        performBitwiseOperations(num1, num2);
        
        printf("Do you want to perform operations with new numbers? (y/n): ");
        getchar(); // To consume the newline character
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for exploring bitwise operations with us!\n");
    return 0;
}

void displayMenu() {
    printf("Choose a bitwise operation to perform:\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT (first number)\n");
    printf("5. NOT (second number)\n");
    printf("6. LEFT SHIFT (first number)\n");
    printf("7. LEFT SHIFT (second number)\n");
    printf("8. RIGHT SHIFT (first number)\n");
    printf("9. RIGHT SHIFT (second number)\n");
}

int getUserInput() {
    int num;
    while (1) {
        if (scanf("%d", &num) == 1) {
            break;
        } else {
            printf("Invalid input! Please enter a valid integer number: ");
            while (getchar() != '\n'); // Clear invalid input
        }
    }
    return num;
}

void performBitwiseOperations(int num1, int num2) {
    int andResult = num1 & num2;
    int orResult = num1 | num2;
    int xorResult = num1 ^ num2;
    int notNum1 = ~num1;
    int notNum2 = ~num2;
    int leftShiftNum1 = num1 << 1; // shift left by 1
    int leftShiftNum2 = num2 << 1; // shift left by 1
    int rightShiftNum1 = num1 >> 1; // shift right by 1
    int rightShiftNum2 = num2 >> 1; // shift right by 1

    showResults(num1, num2, andResult, orResult, xorResult, notNum1, notNum2, leftShiftNum1, leftShiftNum2, rightShiftNum1, rightShiftNum2);
}

void showResults(int num1, int num2, int andResult, int orResult, int xorResult, int notNum1, int notNum2, int leftShiftNum1, int leftShiftNum2, int rightShiftNum1, int rightShiftNum2) {
    printf("\nResults of bitwise operations between %d and %d:\n", num1, num2);
    printf("1. AND: %d & %d = %d\n", num1, num2, andResult);
    printf("2. OR: %d | %d = %d\n", num1, num2, orResult);
    printf("3. XOR: %d ^ %d = %d\n", num1, num2, xorResult);
    printf("4. NOT of %d: ~%d = %d\n", num1, num1, notNum1);
    printf("5. NOT of %d: ~%d = %d\n", num2, num2, notNum2);
    printf("6. LEFT SHIFT %d: %d << 1 = %d\n", num1, num1, leftShiftNum1);
    printf("7. LEFT SHIFT %d: %d << 1 = %d\n", num2, num2, leftShiftNum2);
    printf("8. RIGHT SHIFT %d: %d >> 1 = %d\n", num1, num1, rightShiftNum1);
    printf("9. RIGHT SHIFT %d: %d >> 1 = %d\n\n", num2, num2, rightShiftNum2);
}