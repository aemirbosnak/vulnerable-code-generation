//FormAI DATASET v1.0 Category: Binary Converter ; Style: surprised
#include<stdio.h>
#include<string.h>

// Function to convert decimal to binary
void decimalToBinary(int n)
{
    // to store binary number
    int binaryNum[1000];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // printing binary array in reverse order
    printf("\nBinary Conversion: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main()
{
    // Variable to store decimal number
    int decimalNum;

    printf("Oh boy! This is amazing! Looks like it's a C Binary Converter program! Let's rock and code! \n");

    // Taking user input for decimal number
    printf("Please enter the decimal number you want to convert to binary: ");
    scanf("%d", &decimalNum);

    // Checking for valid input range
    if(decimalNum < 0 || decimalNum > 255)
    {
        printf("\nOops, I'm surprised! Looks like the number is not within the valid range (0-255) for a binary conversion! Please try again! \n\n");
        return 0;
    }

    printf("\nWow, that's a unique decimal number you've got there! Let's convert it to binary! \n");

    // Converting decimal to binary
    decimalToBinary(decimalNum);
    
    printf("\n\nWhoa! That was awesome! I hope you enjoyed it too! \n");

    return 0;
}