//FormAI DATASET v1.0 Category: Binary Converter ; Style: synchronous
#include<stdio.h>
#include<string.h>
#include<math.h>

/*
 * Function to convert decimal to binary
 * Parameters:
 *      - decimal : Decimal number to be converted
 *      - binary  : Pointer to string where the binary number will be stored
 */
void convertDecimalToBinary(int decimal, char* binary)
{
    int quotient = decimal;
    int remainder = 0;
    int index = 0;
    
    while(quotient != 0)
    {
        remainder = quotient % 2;
        binary[index] = (char)(remainder + '0'); // Convert integer to corresponding character
        index++;
        quotient = quotient / 2;
    }
    
    // Reverse the binary string
    int i = 0;
    int j = strlen(binary)-1;
    char temp;
    while (i<j)
    {
        temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
        i++;
        j--;
    }
}

/*
 * Function to convert binary to decimal
 * Parameters:
 *      - binary   : Pointer to string which contains the binary number
 *      - decimal : Pointer to integer where the decimal number will be stored
 */
void convertBinaryToDecimal(char* binary, int* decimal)
{
    int len = strlen(binary);
    int power = 0; // Stores the current power of 2
    int result = 0;
    for(int i=len-1; i>=0; i--)
    {
        if(binary[i] == '1')
        {
            result += pow(2, power); // Multiply the current power of 2 with 1 and add to result
        }
        power++;
    }
    *decimal = result;
}

int main()
{
    int choice;
    int decimal;
    char binary[32];
    do
    {
        // Display the menu
        printf("\nBinary Converter\n");
        printf("------------------------\n");
        printf("1) Decimal to Binary\n");
        printf("2) Binary to Decimal\n");
        printf("3) Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                // Decimal to Binary conversion
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                
                // Call the function to convert decimal to binary
                convertDecimalToBinary(decimal, binary);
                
                // Display the binary number
                printf("Binary number : %s", binary);
                break;
                
            case 2:
                // Binary to Decimal conversion
                printf("Enter binary number : ");
                scanf("%s", binary);
                
                // Call the function to convert binary to decimal
                convertBinaryToDecimal(binary, &decimal);
                
                // Display the decimal number
                printf("Decimal number : %d", decimal);
                break;
                
            case 3:
                // Exit
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.");
                break;
        }
    }while(choice != 3); // Repeat until user chooses to exit
    
    return 0;
}