//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 10

void print_bits(unsigned int num) {
    for (int i = 0; i < sizeof(unsigned int) * 8; i++) {
        printf("%d", (num & (1 << i)) >> i);
    }
}

int main() {
    unsigned int arr[SIZE] = {0};
    int choice, num, pos;

    do {
        printf("\nMENU:\n");
        printf("1. Set bit\n");
        printf("2. Clear bit\n");
        printf("3. Toggle bit\n");
        printf("4. Check bit\n");
        printf("5. Print bits\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &num);
                arr[pos] |= (1 << num);
                printf("Bit set successfully!\n");
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &num);
                arr[pos] &= ~(1 << num);
                printf("Bit cleared successfully!\n");
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &num);
                arr[pos] ^= (1 << num);
                printf("Bit toggled successfully!\n");
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Bit %d is %s\n", pos, (arr[pos] & (1 << pos))? "set" : "not set");
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                print_bits(arr[pos]);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 6);

    return 0;
}