//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void printBinary(unsigned int n) {
    unsigned int mask = 1 << (sizeof(n) * 8 - 1);

    printf("Binary representation: ");
    for (int i = 0; i < sizeof(n) * 8; i++) {
        putchar((n & mask) ? '1' : '0');
        mask >>= 1;
    }
    printf("\n");
}

void displayMenu() {
    printf("\n🎉 Welcome to the Magic Bitwise Calculator! 🎉\n");
    printf("Choose an operation:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT (on first number)\n");
    printf("5. Left Shift (first number)\n");
    printf("6. Right Shift (first number)\n");
    printf("7. Exit\n");
}

int main() {
    unsigned int num1, num2;
    int choice;

    printf("🤗 Let's get started! Please enter two positive integers:\n");
    printf("Enter first number: ");
    scanf("%u", &num1);
    printf("Enter second number: ");
    scanf("%u", &num2);

    do {
        displayMenu();
        printf("📥 Your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n🎈 Bitwise AND: %u & %u = %u\n", num1, num2, num1 & num2);
                printBinary(num1);
                printBinary(num2);
                break;

            case 2:
                printf("\n🎊 Bitwise OR: %u | %u = %u\n", num1, num2, num1 | num2);
                printBinary(num1);
                printBinary(num2);
                break;

            case 3:
                printf("\n🎉 Bitwise XOR: %u ^ %u = %u\n", num1, num2, num1 ^ num2);
                printBinary(num1);
                printBinary(num2);
                break;

            case 4:
                printf("\n🎵 Bitwise NOT: ~%u = %u\n", num1, ~num1);
                printBinary(num1);
                break;

            case 5:
                printf("\n🎈 Left Shift: %u << 1 = %u\n", num1, num1 << 1);
                printBinary(num1);
                break;

            case 6:
                printf("\n🎊 Right Shift: %u >> 1 = %u\n", num1, num1 >> 1);
                printBinary(num1);
                break;

            case 7:
                printf("\n🔚 Thank you for using the Magic Bitwise Calculator! Goodbye! 👋\n");
                break;

            default:
                printf("\n🚫 Invalid choice. Please pick a number between 1 and 7.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}