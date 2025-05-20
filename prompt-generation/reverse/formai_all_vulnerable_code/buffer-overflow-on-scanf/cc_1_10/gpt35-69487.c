//FormAI DATASET v1.0 Category: Bitwise operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Bitwise Opera!\n");
    printf("We take your bits and flip them around,\n");
    printf("we perform some magic without a sound.\n");
    printf("So let's start with some bitwise fun,\n");
    printf("just sit back and let us get the jobdone!\n");

    unsigned int a, b;
    printf("Enter the first integer: ");
    scanf("%u", &a);
    printf("Enter the second integer: ");
    scanf("%u", &b);

    int choice;
    printf("\nChoose from the following bitwise operations:\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. Shift left\n");
    printf("5. Shift right\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\n");

    switch(choice) {
        case 1:
            printf("%u AND %u = %u\n", a, b, (a & b));
            break;
        case 2:
            printf("%u OR %u = %u\n", a, b, (a | b));
            break;
        case 3:
            printf("%u XOR %u = %u\n", a, b, (a ^ b));
            break;
        case 4:
            printf("%u Shifted left by %u = %u\n", a, b, (a << b));
            break;
        case 5:
            printf("%u Shifted right by %u = %u\n", a, b, (a >> b));
            break;
        default:
            printf("You chose a wrong option!\n");
            break;
    }

    printf("\nThanks for letting us play with your bits!\n");
    printf("Hope to see you again soon, with some more!\n");

    return 0;
}