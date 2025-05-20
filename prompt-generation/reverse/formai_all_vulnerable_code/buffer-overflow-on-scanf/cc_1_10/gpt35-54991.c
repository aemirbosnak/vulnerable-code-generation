//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h> 

void hexToDec(unsigned char hex[])
{
   int i = 0;
   unsigned int dec = 0;   
   while (hex[i] != '\0')
   {
       if (hex[i] >= 48 && hex[i] <= 57) //if 0-9
       {
           dec = dec * 16 + (hex[i] - 48);
       }
       else if (hex[i] >= 65 && hex[i] <= 70) //if A-F
       {
           dec = dec * 16 + (hex[i] - 55);
       }
       else if (hex[i] >= 97 && hex[i] <= 102) // if a-f
       {
           dec = dec * 16 + (hex[i] - 87);
       }
       i++;
   }
   printf("Decimal equivalent = %u\n", dec);
}

void decToHex(unsigned int dec)
{
    int i = 0;
    char hex[100]; 
    while(dec != 0)    
    {
        int temp = 0;
        temp = dec % 16; 
        if(temp < 10)   
        {
            hex[i] = temp + 48;
            i++;
        }
        else
        {
            hex[i] = temp + 55;
            i++;
        }
        dec = dec / 16; 
    }    
    printf("Hexadecimal equivalent = ");
    for(int j = i - 1; j >= 0; j--) //printing reversed hexadecimal
    {   
        printf("%c", hex[j]); 
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("Welcome to the Hexadecimal Converter\n");
    do{
        printf("Please choose an option:\n");
        printf("1. Hexadecimal to Decimal Conversion\n");
        printf("2. Decimal to Hexadecimal Conversion\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                unsigned char hex[100];
                printf("Enter the number in Hexadecimal format: ");
                scanf("%s", hex);
                hexToDec(hex);
                break;
            }
            case 2:{
                unsigned int dec;
                printf("Enter the number in Decimal format: ");
                scanf("%u", &dec);
                decToHex(dec);
                break;
            }
            case 3:
                printf("Thank you for using Hexadecimal Converter.\nGoodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 3);
    return 0;
}