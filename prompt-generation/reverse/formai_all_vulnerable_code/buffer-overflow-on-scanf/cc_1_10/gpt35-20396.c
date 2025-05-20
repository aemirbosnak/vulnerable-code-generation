//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Alan Touring
// Creating a C Hexadecimal Converter Program in Alan Turing Style

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert a decimal number to hexadecimal
char* toHex(int decimal)
{
    char* hex = (char*) malloc(100 * sizeof(char));  // Allocate memory for the hexadecimal string
    int i = 0;
    
    while (decimal != 0)
    {
        int temp = 0;
        temp = decimal % 16;
        
        if (temp < 10)
        {
            hex[i] = temp + 48;
            i++;
        }
        else
        {
            hex[i] = temp + 55;   // ASCII value for A = 65, so A = 10 + 55 = 65
            i++;
        }
        
        decimal /= 16;
    }
    
    hex[i] = '\0';
    
    for (int j = 0; j < i / 2; j++)
    {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
    
    return hex;
}

int main()
{
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    char* hexadecimal = toHex(decimal);   // Convert decimal to hexadecimal
    
    printf("Hexadecimal equivalent: %s", hexadecimal);  // Print the hexadecimal equivalent
    
    free(hexadecimal);  // Free the memory
    
    return 0;
}