//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

void display_binary(int num) {
    int bit;
    for (int i = 31; i >= 0; i--) {
        bit = num >> i & 1;
        printf("%d", bit);
    }
    printf("\n");
}

void perform_bitwise_operation(int num, int operation, int value) {
    switch (operation) {
        case 1:
            num &= value;
            break;
        case 2:
            num |= value;
            break;
        case 3:
            num ^= value;
            break;
        case 4:
            num >>= value;
            break;
        case 5:
            num <<= value;
            break;
        case 6:
            num &= ~value;
            break;
        default:
            printf("Invalid operation!\n");
            exit(1);
    }
}

int main() {
    int num, operation, value;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter the operation number (1-6): ");
    scanf("%d", &operation);

    printf("Enter the value for the operation: ");
    scanf("%d", &value);

    printf("\nNumber before operation: ");
    display_binary(num);

    perform_bitwise_operation(num, operation, value);

    printf("\nNumber after operation: ");
    display_binary(num);

    return 0;
}