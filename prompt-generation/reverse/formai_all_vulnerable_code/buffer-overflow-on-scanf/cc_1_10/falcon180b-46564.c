//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: irregular
#include <stdio.h>

#define NUM_BITS 32

void print_binary(unsigned int num) {
    for (int i = 0; i < NUM_BITS; i++) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

void set_bit(unsigned int *num, int pos) {
    *num |= (1 << pos);
}

void clear_bit(unsigned int *num, int pos) {
    *num &= ~(1 << pos);
}

void toggle_bit(unsigned int *num, int pos) {
    *num ^= (1 << pos);
}

int main() {
    unsigned int num = 0;
    int choice, pos;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Binary representation: ");
    print_binary(num);

    do {
        printf("\nBitwise operations:\n");
        printf("1. Set bit\n");
        printf("2. Clear bit\n");
        printf("3. Toggle bit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the position of the bit to set: ");
            scanf("%d", &pos);
            set_bit(&num, pos);
            printf("Binary representation after setting bit: ");
            print_binary(num);
            break;
        case 2:
            printf("Enter the position of the bit to clear: ");
            scanf("%d", &pos);
            clear_bit(&num, pos);
            printf("Binary representation after clearing bit: ");
            print_binary(num);
            break;
        case 3:
            printf("Enter the position of the bit to toggle: ");
            scanf("%d", &pos);
            toggle_bit(&num, pos);
            printf("Binary representation after toggling bit: ");
            print_binary(num);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }

    } while (choice!= 4);

    return 0;
}