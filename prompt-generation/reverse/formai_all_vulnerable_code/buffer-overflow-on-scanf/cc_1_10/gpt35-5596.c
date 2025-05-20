//FormAI DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert decimal to binary
void decToBin(int decimal_num, int binary_num[]){
    int i = 0;
    // Loop through until decimal number becomes 0
    while(decimal_num > 0){
        // Store the remainder in an array
        binary_num[i] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        i++;
    }
    // Print the binary number
    printf("The binary number is: ");
    for(int j = i - 1; j >= 0; j--){
        printf("%d", binary_num[j]);
    }
    printf("\n");
}

// Function to convert binary to decimal
void binToDec(int binary_num[], int size){
    int decimal_num = 0;
    for(int i = size - 1; i >= 0; i--){
        // Calculate the decimal equivalent
        decimal_num += binary_num[i] * pow(2, size - i - 1);
    }
    // Print the decimal number
    printf("The decimal number is: %d\n", decimal_num);
}

int main(){
    int choice, decimal_num, size, binary_num[32];
    // Print menu
    printf("\nWelcome to Binary Converter!\n");
    printf("Select an operation to perform:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Quit\n");
    
    while(1){
        // Take user input for choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                // Take user input for decimal number
                printf("Enter decimal number: ");
                scanf("%d", &decimal_num);
                // Call function to convert decimal to binary
                decToBin(decimal_num, binary_num);
                break;
            case 2:
                // Take user input for binary number
                printf("Enter size of binary number: ");
                scanf("%d", &size);
                printf("Enter binary number: ");
                for(int i = 0; i < size; i++){
                    scanf("%d", &binary_num[i]);
                }
                // Call function to convert binary to decimal
                binToDec(binary_num, size);
                break;
            case 3:
                // Quit the program
                printf("Exiting Binary Converter...\n");
                exit(0);
            default:
                // Invalid choice
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}