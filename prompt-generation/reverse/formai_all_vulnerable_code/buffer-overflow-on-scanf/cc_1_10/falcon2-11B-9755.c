//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Cannot divide by zero\n");
        return -1;
    } else {
        return a / b;
    }
}

int main() {
    int choice;
    do {
        printf("Please select an operation:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Result of %d + %d = %d\n", __FILE__, __LINE__, add(3, 4));
                break;
            case 2:
                printf("Result of %d - %d = %d\n", __FILE__, __LINE__, subtract(3, 4));
                break;
            case 3:
                printf("Result of %d * %d = %d\n", __FILE__, __LINE__, multiply(3, 4));
                break;
            case 4:
                printf("Result of %d / %d = %d\n", __FILE__, __LINE__, divide(3, 4));
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (choice!= 5);

    return 0;
}