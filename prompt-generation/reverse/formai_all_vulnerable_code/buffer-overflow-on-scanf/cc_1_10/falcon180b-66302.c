//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>

/* Function to convert decimal to binary */
void dec_to_bin(int n) {
    int i = 1;
    while (n > 0) {
        printf("%d", n % 2);
        n /= 2;
        i++;
        if (i % 4 == 0) {
            printf(" ");
        }
    }
}

/* Function to convert binary to decimal */
int bin_to_dec(char* bin) {
    int dec = 0, base = 1;
    int i = strlen(bin) - 1;
    while (i >= 0) {
        if (bin[i] == '1') {
            dec += base;
        }
        base *= 2;
        i--;
    }
    return dec;
}

int main() {
    int choice, n;
    char bin[100];

    printf("Enter 1 to convert decimal to binary\n");
    printf("Enter 2 to convert binary to decimal\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &n);
            dec_to_bin(n);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%s", bin);
            printf("The decimal equivalent is: %d\n", bin_to_dec(bin));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}