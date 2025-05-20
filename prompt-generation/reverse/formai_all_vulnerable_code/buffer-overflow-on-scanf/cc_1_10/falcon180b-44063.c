//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void dec_to_bin(int n) {
    char bin[33]; // Maximum 32 bits + null terminator
    int i = 0;
    while (n > 0) {
        bin[i++] = n % 2 + '0';
        n /= 2;
    }
    bin[i] = '\0';
    printf("%s\n", bin);
}

// Function to convert binary to decimal
int bin_to_dec(char *bin) {
    int dec = 0, i = 0;
    while (bin[i]!= '\0') {
        dec += (bin[i] - '0') * pow(2, strlen(bin) - 1 - i);
        i++;
    }
    return dec;
}

int main() {
    int choice, num;

    do {
        printf("\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &num);
            dec_to_bin(num);
            break;

        case 2:
            printf("Enter a binary number: ");
            char bin[33];
            scanf("%s", bin);
            printf("Decimal equivalent: %d\n", bin_to_dec(bin));
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}