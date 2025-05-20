//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, choice, i, j;
    char input[100];

    // Seed the random number generator
    srand(time(NULL));

    // Prompt the user to enter two integers
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Prompt the user to choose a bitwise operation
    printf("Choose a bitwise operation:\n");
    printf("1. Bitwise OR\n");
    printf("2. Bitwise AND\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Bitwise Left Shift\n");
    printf("6. Bitwise Right Shift\n");
    scanf("%d", &choice);

    // Perform the chosen bitwise operation
    switch(choice) {
        case 1: // Bitwise OR
            printf("Bitwise OR of %d and %d is %d\n", num1, num2, num1 | num2);
            break;
        case 2: // Bitwise AND
            printf("Bitwise AND of %d and %d is %d\n", num1, num2, num1 & num2);
            break;
        case 3: // Bitwise XOR
            printf("Bitwise XOR of %d and %d is %d\n", num1, num2, num1 ^ num2);
            break;
        case 4: // Bitwise NOT
            printf("Bitwise NOT of %d is %d\n", num1, ~num1);
            break;
        case 5: // Bitwise Left Shift
            printf("Bitwise Left Shift of %d by %d positions is %d\n", num1, num2, num1 << num2);
            break;
        case 6: // Bitwise Right Shift
            printf("Bitwise Right Shift of %d by %d positions is %d\n", num1, num2, num1 >> num2);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}