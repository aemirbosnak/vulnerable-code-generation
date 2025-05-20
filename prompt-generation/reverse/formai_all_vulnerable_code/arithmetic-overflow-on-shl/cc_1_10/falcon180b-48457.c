//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BIT_MASK 0xff

void set_bit(unsigned char* byte, int position) {
    *byte |= (1 << position);
}

void clear_bit(unsigned char* byte, int position) {
    *byte &= ~(1 << position);
}

int get_bit(unsigned char* byte, int position) {
    return (*byte & (1 << position)) >> position;
}

void toggle_bit(unsigned char* byte, int position) {
    *byte ^= (1 << position);
}

void print_binary(unsigned char byte) {
    for (int i = 0; i < 8; i++) {
        printf("%d", (byte >> i) & 1);
    }
    printf("\n");
}

int main() {
    unsigned char byte = 0;
    int position = 0;
    int choice = 0;

    do {
        printf("Enter your choice:\n");
        printf("1. Set bit\n");
        printf("2. Clear bit\n");
        printf("3. Get bit\n");
        printf("4. Toggle bit\n");
        printf("5. Print binary\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position: ");
                scanf("%d", &position);
                set_bit(&byte, position);
                printf("Byte after setting bit: ");
                print_binary(byte);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &position);
                clear_bit(&byte, position);
                printf("Byte after clearing bit: ");
                print_binary(byte);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Value of bit: %d\n", get_bit(&byte, position));
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                toggle_bit(&byte, position);
                printf("Byte after toggling bit: ");
                print_binary(byte);
                break;
            case 5:
                printf("Byte: ");
                print_binary(byte);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 6);

    return 0;
}