//FormAI DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

/* 
* A futuristic binary converter program 
* that can handle both positive and negative binary numbers.
* It uses a custom datatype called Binary, which is essentially
* a signed long long integer.
*/

typedef signed long long int Binary;

Binary convertBinaryToDecimal(Binary binaryNum) {
    Binary decimalNum = 0, base = 1, temp = binaryNum;

    while (temp) {
        Binary lastDigit = temp % 10;
        temp /= 10;
        decimalNum += lastDigit * base;
        base *= 2;
    }

    return decimalNum;
}

Binary convertDecimalToBinary(Binary decimalNum) {
    Binary binaryNum = 0, base = 1;

    if (decimalNum < 0) {
        binaryNum += 1;
        decimalNum = abs(decimalNum);
    }

    while (decimalNum) {
        Binary lastDigit = decimalNum % 2;
        decimalNum /= 2;
        binaryNum += lastDigit * base;
        base *= 10;
    }

    return binaryNum;
}

void printBinary(Binary binaryNum) {
    Binary decimalNum = convertBinaryToDecimal(binaryNum);
    Binary binaryValue = convertDecimalToBinary(decimalNum);

    if (binaryNum < 0) {
        printf("-");
        binaryValue *= -1;
    }

    printf("%lld\n", binaryValue);
}

int main() {
    printf("Enter a binary number: ");

    Binary binaryNum;
    scanf("%lld", &binaryNum);

    printf("Decimal representation: %lld\n", convertBinaryToDecimal(binaryNum));
    printf("Binary representation: ");
    printBinary(binaryNum);

    return 0;
}