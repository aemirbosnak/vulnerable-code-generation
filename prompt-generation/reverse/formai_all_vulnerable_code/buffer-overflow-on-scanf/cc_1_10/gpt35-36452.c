//FormAI DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <string.h>

// function to convert binary to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0, multiplier = 1;
    int len = strlen(binary);
    
    // iterate backwards through the binary string
    for(int i = len-1; i >= 0; i--) {
        if(binary[i] == '1') {
            decimal += multiplier;
        }
        multiplier *= 2;
    }
    return decimal;
}

// function to convert decimal to binary
void decimalToBinary(int decimal, char *binary) {
    int index = 0;
    
    // calculate binary representation of decimal
    while(decimal > 0) {
        binary[index] = decimal%2 + '0';
        decimal /= 2;
        index++;
    }
    binary[index] = '\0';
    
    // reverse binary string
    int len = strlen(binary);
    for(int i = 0; i < len/2; i++) {
        char temp = binary[i];
        binary[i] = binary[len-i-1];
        binary[len-i-1] = temp;
    }
}

int main() {
    int choice = 0, decimal = 0;
    char binary[32] = "";
    
    // display menu options
    printf("Binary Converter\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Exit\n");
    
    // get user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    // perform selected operation
    switch(choice) {
        case 1:
            printf("Enter binary number: ");
            scanf("%s", binary);
            
            // validate binary input
            int valid_input = 1;
            for(int i = 0; i < strlen(binary); i++) {
                if(binary[i] != '0' && binary[i] != '1') {
                    printf("Invalid input!\n");
                    valid_input = 0;
                    break;
                }
            }
            
            // convert binary to decimal
            if(valid_input) {
                decimal = binaryToDecimal(binary);
                printf("Decimal equivalent: %d\n", decimal);
            }
            break;
            
        case 2:
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            
            // convert decimal to binary
            decimalToBinary(decimal, binary);
            printf("Binary equivalent: %s\n", binary);
            break;
            
        case 3:
            printf("Exiting...\n");
            break;
            
        default:
            printf("Invalid option selected\n");
            break;
    }
    
    return 0;
}