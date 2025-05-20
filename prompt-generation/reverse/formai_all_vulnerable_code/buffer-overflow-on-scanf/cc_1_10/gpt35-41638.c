//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>

// Function to convert hexadecimal to decimal
int hexToDec(char hexVal[]) {
    int len = strlen(hexVal);
    int base = 1;
    int decVal = 0;

    // Go from right to left 
    for (int i=len-1; i>=0; i--) {
        // If character is 0-9, convert to int and add to decVal
        if (hexVal[i]>='0' && hexVal[i]<='9') {
            decVal += (hexVal[i] - 48)*base;
            base = base*16;
        }
        // If character is A-F, convert to int and add to decVal
        else if (hexVal[i]>='A' && hexVal[i]<='F') {
            decVal += (hexVal[i] - 55)*base;
            base = base*16;
        }
    }

    return decVal;
}

// Function to convert decimal to hexadecimal
void decToHex(int num) {
    // Array to store hexadecimal number
    char hexNum[100];

    // Counter for hexadecimal number array
    int i = 0;

    while (num!=0) {
        // Get remainder 
        int temp  = 0;
        temp = num % 16;

        // If remainder is 10-15, add A-F to character array
        if (temp < 10) {
            hexNum[i] = temp + 48;
            i++;
        }
        else {
            hexNum[i] = temp + 55;
            i++;
        }

        num = num/16;
    }

    // Print hexadecimal number array in reverse order
    printf("The hexadecimal value is: ");
    for (int j=i-1; j>=0; j--) {
        printf("%c", hexNum[j]);
    }
    printf("\n");
}

int main() {

    char input[50];
    printf("Please enter a hexadecimal color code (with or without #): ");
    scanf("%s", input);
    
    int decValue = 0;
    // If input starts with #, remove # before converting
    if (input[0] == '#') {
        char newInput[50];
        // Iterate through input and remove #
        for (int i=1; i<strlen(input); i++) {
            newInput[i-1] = input[i];
        }
        // Convert newInput to decimal
        decValue = hexToDec(newInput);
    }
    else {
        // Convert input directly to decimal
        decValue = hexToDec(input);
    }

    printf("The decimal value is: %d\n", decValue);
    
    decToHex(decValue);

    return 0;
}