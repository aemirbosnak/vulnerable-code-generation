//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
char *decimalToBinary(int n) {
    int i, k;
    char *arr, *arrTemp;
    
    // Allocate memory for the binary string
    arr = (char *)malloc(sizeof(char) * 32);
    arr[0] = '\0';
    
    // Iterate until the number is 0
    for (i = 31; n > 0; i--) {
        // Check if the last bit of the number is 1
        if (n & 1) {
            // Append 1 to the binary string
            arr[i] = '1';
        } else {
            // Append 0 to the binary string
            arr[i] = '0';
        }
        
        // Right shift the number by 1
        n >>= 1;
    }
    
    // Reverse the binary string
    arrTemp = (char *)malloc(sizeof(char) * 32);
    for (i = 0, k = 31; i < 32; i++, k--) {
        arrTemp[i] = arr[k];
    }
    arrTemp[32] = '\0';
    
    // Return the binary string
    return arrTemp;
}

// Main function
int main() {
    int n;
    char *binaryString;
    
    // Get the decimal number from the user
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    
    // Convert the decimal number to binary
    binaryString = decimalToBinary(n);
    
    // Print the binary string
    printf("The binary string is: %s\n", binaryString);
    
    // Free the memory allocated for the binary string
    free(binaryString);
    
    return 0;
}