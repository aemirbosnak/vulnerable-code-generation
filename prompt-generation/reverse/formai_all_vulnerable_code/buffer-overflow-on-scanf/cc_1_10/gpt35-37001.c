//FormAI DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h> 

void decimalToBinary(unsigned int num) {
    int binary[32];
    int i = 0;
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

unsigned int binaryToDecimal(int binaryNum) {
    unsigned int decimalNum = 0, base = 1, rem;
    while (binaryNum > 0) {
        rem = binaryNum % 10;
        decimalNum = decimalNum + rem * base;
        binaryNum = binaryNum / 10;
        base = base * 2;
    }
    return decimalNum;
}
 
int main() {
    unsigned int decimalNum;
    int binaryNum;
    int choice;
 
    printf("Binary Conversion Menu\n");
    printf("-----------------------------\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &decimalNum);
            decimalToBinary(decimalNum);
            break;
        case 2:
            printf("Enter binary number: ");
            scanf("%d", &binaryNum);
            printf("Decimal equivalent: %u", binaryToDecimal(binaryNum));
            break;
        default:
            printf("Invalid choice!");
            break;
    }
    return 0;
}