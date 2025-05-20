//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include<stdio.h>

/* A Visionary C Hexadecimal Converter Example Program */
/* Author: Chatbot-X */

// Function to convert decimal to hexadecimal
void decToHexa(int n) 
{    
    char hexaDeciNum[100];
    int i = 0;
    while(n!=0)
    {    
        int temp  = 0;
        temp = n % 16;
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
           
        n = n/16;
    }        
    printf("\nHexadecimal value is : ");
    for(int j=i-1;j>=0;j--)
    {
        printf("%c",hexaDeciNum[j]);
    }
}

// Function to convert hexadecimal to decimal
int hexToDec(char hex[]) 
{
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    for(int i=len-1; i>=0; i--)
    {   
        if(hex[i]>='0' && hex[i]<='9')
        {
            dec += (hex[i] - 48)*base;
            base = base * 16;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            dec += (hex[i] - 55)*base;
            base = base*16;
        }
    }
    return dec;
}

// Main function
int main()
{   
    int choice;
    printf("Welcome to Visionary Hexadecimal Converter!\n\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n\n");
    
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice == 1)
        {
            int decimal;
            printf("\nEnter Decimal Number: ");
            scanf("%d",&decimal);
            decToHexa(decimal);
            printf("\n\n");
        }

        else if (choice == 2)
        {
            char hex[100];
            printf("\nEnter Hexadecimal Number: ");
            scanf("%s",hex);
            int decimal = hexToDec(hex);
            printf("Decimal equivalent is: %d\n\n", decimal);
        }

        else if (choice == 3)
        {
            printf("Thank you for using Visionary Hexadecimal Converter!\n");
            break;
        }

        else
        {
            printf("Please enter a valid choice!\n");
        }
    }
   return 0;
}