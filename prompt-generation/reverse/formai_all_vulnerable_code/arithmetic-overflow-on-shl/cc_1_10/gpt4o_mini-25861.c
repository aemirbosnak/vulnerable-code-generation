//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: invasive
#include <stdio.h>

void displayBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int bitwiseAnd(int a, int b) {
    return a & b;
}

int bitwiseOr(int a, int b) {
    return a | b;
}

int bitwiseXor(int a, int b) {
    return a ^ b;
}

int bitwiseNot(int a) {
    return ~a;
}

int leftShift(int a, int positions) {
    return a << positions;
}

int rightShift(int a, int positions) {
    return a >> positions;
}

int main() {
    int choice, a, b, result;
    
    printf("Bitwise Operations Menu:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    printf("7. Exit\n");

    while (1) {
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        
        if (choice == 7) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two integers (a and b): ");
                scanf("%d %d", &a, &b);
                result = bitwiseAnd(a, b);
                printf("Bitwise AND of ");
                displayBinary(a);
                printf("and ");
                displayBinary(b);
                printf("is ");
                displayBinary(result);
                break;

            case 2:
                printf("Enter two integers (a and b): ");
                scanf("%d %d", &a, &b);
                result = bitwiseOr(a, b);
                printf("Bitwise OR of ");
                displayBinary(a);
                printf("and ");
                displayBinary(b);
                printf("is ");
                displayBinary(result);
                break;

            case 3:
                printf("Enter two integers (a and b): ");
                scanf("%d %d", &a, &b);
                result = bitwiseXor(a, b);
                printf("Bitwise XOR of ");
                displayBinary(a);
                printf("and ");
                displayBinary(b);
                printf("is ");
                displayBinary(result);
                break;

            case 4:
                printf("Enter an integer (a): ");
                scanf("%d", &a);
                result = bitwiseNot(a);
                printf("Bitwise NOT of ");
                displayBinary(a);
                printf("is ");
                displayBinary(result);
                break;

            case 5:
                printf("Enter an integer (a) and number of positions to shift: ");
                scanf("%d %d", &a, &b);
                result = leftShift(a, b);
                printf("Left shifting ");
                displayBinary(a);
                printf("by %d positions results in ", b);
                displayBinary(result);
                break;

            case 6:
                printf("Enter an integer (a) and number of positions to shift: ");
                scanf("%d %d", &a, &b);
                result = rightShift(a, b);
                printf("Right shifting ");
                displayBinary(a);
                printf("by %d positions results in ", b);
                displayBinary(result);
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}