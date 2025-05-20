//FormAI DATASET v1.0 Category: Binary Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 20

// Function to convert decimal value to binary
void decimalToBinary(int decimalValue, char *binaryValue){
    int binaryArray[MAX_BINARY_LENGTH];
    int i = 0;

    while(decimalValue > 0){
        binaryArray[i] = decimalValue % 2;
        decimalValue /= 2;
        i++;
    }

    int j = i - 1;
    for(i = 0; j >= 0; i++, j--){
        sprintf(&binaryValue[i], "%d", binaryArray[j]);
    }
}

// Function to convert binary value to decimal
int binaryToDecimal(char *binaryValue){
    int decimalValue = 0;
    int powerOfTwo = 1;

    for(int i = strlen(binaryValue) - 1; i >= 0; i--){
        if(binaryValue[i] == '1'){
            decimalValue += powerOfTwo;
        }
        powerOfTwo *= 2;
    }

    return decimalValue;
}

// Main function
int main(){
    // User input for decimal or binary value
    int choice;
    printf("Enter 1 to convert decimal to binary or 2 to convert binary to decimal: ");
    scanf("%d", &choice);

    // Convert decimal value to binary
    if(choice == 1){
        int decimalValue;
        char binaryValue[MAX_BINARY_LENGTH];

        printf("Enter decimal value: ");
        scanf("%d", &decimalValue);

        decimalToBinary(decimalValue, binaryValue);

        printf("Binary value is: %s\n", binaryValue);
    }
    // Convert binary value to decimal
    else if(choice == 2){
        char binaryValue[MAX_BINARY_LENGTH];

        printf("Enter binary value (up to 20 bits): ");
        scanf("%s", binaryValue);

        int decimalValue = binaryToDecimal(binaryValue);

        printf("Decimal value is: %d\n", decimalValue);
    }
    // Invalid choice
    else{
        printf("Invalid choice. Please select 1 or 2.\n");
    }

    return 0;
}