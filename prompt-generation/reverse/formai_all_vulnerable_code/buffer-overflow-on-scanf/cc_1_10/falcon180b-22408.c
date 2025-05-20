//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: irregular
#include <stdio.h>

// Function to convert decimal to binary
void dec_to_bin(int num) {
    int rem;
    char bin[50];
    bin[49] = '\0';
    int i = 0;

    while (num!= 0) {
        rem = num % 2;
        bin[i++] = rem + '0';
        num /= 2;
    }

    // Printing binary in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", bin[j]);
    }
}

// Function to convert binary to decimal
int bin_to_dec(char bin[]) {
    int dec = 0, i = 0;

    while (bin[i]!= '\0') {
        dec += (bin[i] - '0') * pow(2, i);
        i++;
    }

    return dec;
}

int main() {
    int choice;
    char bin[50];

    printf("Enter 1 to convert decimal to binary\n");
    printf("Enter 2 to convert binary to decimal\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int num;
        printf("Enter a decimal number: ");
        scanf("%d", &num);
        dec_to_bin(num);
    } else if (choice == 2) {
        printf("Enter a binary number: ");
        scanf("%s", bin);
        printf("Decimal equivalent: %d\n", bin_to_dec(bin));
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}