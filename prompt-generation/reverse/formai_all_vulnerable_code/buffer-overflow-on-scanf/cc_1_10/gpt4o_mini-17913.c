//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void printBinary(int num);
void convertToBinary(int num);
void displayHeader();
void displayFooter();

int main() {
    displayHeader();

    int number;
    
    printf("Enter a positive integer to convert to binary (enter -1 to exit): ");
    
    while (1) {
        scanf("%d", &number);
        
        if (number == -1) {
            break;
        }

        if (number >= 0) {
            printf("The binary representation of %d is: ", number);
            convertToBinary(number);
            printf("\n");
        } else {
            printf("Please enter a non-negative integer.\n");
        }
        printf("\nEnter another positive integer (or -1 to exit): ");
    }
    
    displayFooter();
    return 0;
}

void convertToBinary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    int binary[32];
    int index = 0;

    while (num > 0) {
        binary[index] = num % 2;
        num = num / 2;
        index++;
    }
    
    // Printing the binary array in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

void displayHeader() {
    printf("*****************************************\n");
    printf("          Welcome to Binary Converter!  \n");
    printf("*****************************************\n");
    printf("This program converts a positive integer to its binary representation.\n");
    printf("You can continue entering numbers until you decide to exit.\n");
    printf("*****************************************\n");
}

void displayFooter() {
    printf("*****************************************\n");
    printf("           Thank you for using!         \n");
    printf("             Bye! Have a great day!    \n");
    printf("*****************************************\n");
}