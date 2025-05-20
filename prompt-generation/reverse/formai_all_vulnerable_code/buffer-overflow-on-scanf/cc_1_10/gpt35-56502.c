//FormAI DATASET v1.0 Category: Bitwise operations ; Style: medieval
#include <stdio.h>

int main() {

    printf("Milord, what type of bitwise operation may I assist thee with?\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT\n");

    int choice;
    scanf("%d", &choice);

    int a, b, result;
    switch(choice) {
        case 1:
            printf("Milord, please give me two integers to AND together: ");
            scanf("%d %d", &a, &b);
            result = a & b;
            printf("The result of the AND operation is %d.\n", result);
            break;

        case 2:
            printf("Milord, please give me two integers to OR together: ");
            scanf("%d %d", &a, &b);
            result = a | b;
            printf("The result of the OR operation is %d.\n", result);
            break;

        case 3:
            printf("Milord, please give me two integers to XOR together: ");
            scanf("%d %d", &a, &b);
            result = a ^ b;
            printf("The result of the XOR operation is %d.\n", result);
            break;

        case 4:
            printf("Milord, please give me an integer to NOT: ");
            scanf("%d", &a);
            result = ~a;
            printf("The result of the NOT operation is %d.\n", result);
            break;

        default:
            printf("Milord, thou hast chosen an invalid option. Please try again.\n");
            break;
    }

    return 0;
}