//FormAI DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <stdbool.h>

// Function to convert a decimal number to its hexadecimal equivalent
void decimal_to_hexadecimal(int decimal_value, char hex_value[])
{
    int remainder, quotient;
    int index = 0;
    
    // Continue till the decimal value is greater than 0
    while(decimal_value > 0)
    {
        remainder = decimal_value % 16;
        quotient = decimal_value / 16;
        
        if(remainder < 10)
            hex_value[index++] = remainder + 48; // Add 48 to convert to ASCII value of corresponding digit
        else
            hex_value[index++] = remainder + 55; // Add 55 to convert to ASCII value of corresponding character
        
        decimal_value = quotient;
    }
    
    // Reverse the hexadecimal value array
    for(int i=0; i<= index/2 - 1; i++)
    {
        char temp = hex_value[i];
        hex_value[i] = hex_value[index-1-i];
        hex_value[index-1-i] = temp;
    }
    hex_value[index] = '\0'; // Add null character at the end of hexadecimal value array
}

// Function to convert a hexadecimal value to its decimal equivalent
int hexadecimal_to_decimal(const char hex_value[])
{
    int decimal_value = 0;
    int size = 0;
    
    // Find the size of hexadecimal array
    for(int i=0; hex_value[i] != '\0'; i++)
        size++;
        
    // Convert each digit of hexadecimal array to decimal
    for(int i=0; hex_value[i] != '\0'; i++)
    {
        int base_value;
        size--;
        
        if(hex_value[i] >= '0' && hex_value[i] <= '9')
            base_value = hex_value[i] - 48;
        else if(hex_value[i] >= 'a' && hex_value[i] <= 'f')
            base_value = hex_value[i] - 87;
        else if(hex_value[i] >= 'A' && hex_value[i] <= 'F')
            base_value = hex_value[i] - 55;
        
        // Multiply the decimal value of each digit to appropriate power of 16
        decimal_value += base_value * pow(16, size);
    }
    return decimal_value;
}

int main()
{
    bool continue_program = true; // A flag to continue to run the program
    
    while(continue_program)
    {
        int option;
        printf("Choose your option: ");
        printf("\n 1: Convert Decimal to Hexadecimal \n 2: Convert Hexadecimal to Decimal \n 3: Exit the Program \n");
        scanf("%d", &option);
        
        // Switch case to select the option
        switch(option)
        {
            case 1:
            {
                int decimal_value;
                char hex_value[100];
                printf("Enter the Decimal Value: ");
                scanf("%d", &decimal_value);
                
                decimal_to_hexadecimal(decimal_value, hex_value);
                
                printf("The Hexadecimal Equivalent of %d is %s\n", decimal_value, hex_value);
                
                break;
            }
            
            case 2:
            {
                char hex_value[100];
                printf("Enter the Hexadecimal Value: ");
                scanf("%s", hex_value);
                
                int decimal_value = hexadecimal_to_decimal(hex_value);
                
                printf("The Decimal Equivalent of %s is %d\n", hex_value, decimal_value);
                
                break;
            }
            
            case 3:
            {
                continue_program = false;
                printf("Exiting the Program. Thank you for using.\n");
                break;
            }
            
            default:
            {
                printf("Invalid option selected. Please choose a valid option.\n");
                
                break;
            }
        }
    }
    
    return 0;
}