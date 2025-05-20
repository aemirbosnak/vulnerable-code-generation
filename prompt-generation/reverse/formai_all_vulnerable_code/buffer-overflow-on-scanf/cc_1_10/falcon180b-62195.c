//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>

//Function to convert decimal to binary
void decimal_to_binary(int decimal_num) {
    int binary_num[100];
    int i = 0;
    while (decimal_num > 0) {
        binary_num[i] = decimal_num % 2;
        decimal_num /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary_num[j]);
    }
    printf("\n");
}

//Function to convert binary to decimal
int binary_to_decimal(char binary_num[]) {
    int decimal_num = 0;
    int power = 0;
    int length = strlen(binary_num) - 1;
    for (int i = length; i >= 0; i--) {
        if (binary_num[i] == '1') {
            decimal_num += pow(2, power);
        }
        power++;
    }
    return decimal_num;
}

int main() {
    int choice;
    char binary_num[100];

    printf("Welcome to the Funny Binary Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &choice);
            decimal_to_binary(choice);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%s", binary_num);
            printf("The decimal equivalent is: %d\n", binary_to_decimal(binary_num));
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }

    return 0;
}