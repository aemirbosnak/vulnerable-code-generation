//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_BITS 32

void set_bit(unsigned int *num, int bit_pos) {
    *num |= (1 << bit_pos);
}

void clear_bit(unsigned int *num, int bit_pos) {
    *num &= ~(1 << bit_pos);
}

void toggle_bit(unsigned int *num, int bit_pos) {
    *num ^= (1 << bit_pos);
}

void clear_all_bits(unsigned int *num) {
    *num = 0;
}

int count_bits(unsigned int num) {
    int count = 0;
    while (num) {
        count++;
        num &= (num - 1);
    }
    return count;
}

int main() {
    unsigned int num = 0;
    int bit_pos = 0;
    int choice = 0;
    int exit_choice = 0;

    while (!exit_choice) {
        printf("Enter your choice:\n");
        printf("1. Set bit\n");
        printf("2. Clear bit\n");
        printf("3. Toggle bit\n");
        printf("4. Clear all bits\n");
        printf("5. Count bits\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter bit position (0-31): ");
            scanf("%d", &bit_pos);
            set_bit(&num, bit_pos);
            printf("Bit set at position %d\n", bit_pos);
            break;
        case 2:
            printf("Enter bit position (0-31): ");
            scanf("%d", &bit_pos);
            clear_bit(&num, bit_pos);
            printf("Bit cleared at position %d\n", bit_pos);
            break;
        case 3:
            printf("Enter bit position (0-31): ");
            scanf("%d", &bit_pos);
            toggle_bit(&num, bit_pos);
            printf("Bit toggled at position %d\n", bit_pos);
            break;
        case 4:
            clear_all_bits(&num);
            printf("All bits cleared\n");
            break;
        case 5:
            printf("Number of set bits: %d\n", count_bits(num));
            break;
        case 6:
            exit_choice = 1;
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}