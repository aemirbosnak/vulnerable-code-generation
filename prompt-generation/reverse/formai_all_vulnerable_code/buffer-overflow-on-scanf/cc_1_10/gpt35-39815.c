//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Function prototypes
void convertToHex(int decimalNum, char hexNum[]);
int getDigitValue(char hexDigit);

int main() {
    int decimalNum;
    char hexNum[100];

    // Prompt user for decimal number input
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    // Convert decimal number to hexadecimal
    convertToHex(decimalNum, hexNum);

    // Display hexadecimal conversion result
    printf("The hexadecimal equivalent of %d is: %s\n", decimalNum, hexNum);
    
    return 0;
}

// Function takes a decimal number and returns its hexadecimal equivalent
void convertToHex(int decimalNum, char hexNum[]) {
    int remainder, i = 0;

    // Iterate until decimal number is zero
    while(decimalNum != 0) {
        remainder = decimalNum % 16;  // Obtain the remainder after dividing by 16
        hexNum[i] = remainder < 10 ? remainder + 48 : remainder + 55;  // Convert the remainder to its corresponding hexadecimal digit
        decimalNum /= 16;
        i++;
    }
    hexNum[i] = '\0';  // Add null character to mark end of string

    // Reverse the order of hexadecimal digits in the string
    int j, k;
    char temp;
    for(j=0, k=strlen(hexNum)-1; j<k; j++, k--) {
        temp = hexNum[j];
        hexNum[j] = hexNum[k];
        hexNum[k] = temp;
    }
}

// Function takes a single hexadecimal digit and returns its decimal equivalent
int getDigitValue(char hexDigit) {
    if(hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0';
    }
    else if(hexDigit >= 'A' && hexDigit <= 'F') {
        return hexDigit - 'A' + 10;
    }
    else if(hexDigit >= 'a' && hexDigit <= 'f') {
        return hexDigit - 'a' + 10;
    }
    else {
        return -1;
    }
}