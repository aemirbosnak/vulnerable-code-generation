//FormAI DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <string.h>

int hexToDec(char hex[]);
void decToHex(int dec, char hex[]);
void inputValidation(char input[]);

int main()
{
    char input[10];
    char output[10] = "#";
    char color[3];
    int index = 1;
    
    printf("Enter the color code (in hex format): ");
    scanf("%s", input);

    inputValidation(input);
    
    for(int i=0; i<3; i++)
    {
        color[0] = input[index++];
        color[1] = input[index++];
        color[2] = '\0';
        
        int decColor = hexToDec(color);
        char hexColor[3];
        
        decToHex(decColor, hexColor);
        
        strcat(output, hexColor);
    }
    
    printf("The RGB color code is %s\n", output);
    
    return 0;
}

// Function to convert hexadecimal to decimal
int hexToDec(char hex[])
{
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    
    for(int i=len-1; i>=0; i--)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
        {
            dec += (hex[i] - 48) * base;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F')
        {
            dec += (hex[i] - 55) * base;
        }
        
        base *= 16;
    }
    
    return dec;
}

// Function to convert decimal to hexadecimal
void decToHex(int dec, char hex[])
{
    int rem;
    int i = 0;
    
    while(dec > 0)
    {
        rem = dec % 16;
        if(rem < 10)
        {
            hex[i++] = rem + 48;
        }
        else
        {
            hex[i++] = rem + 55;
        }
        dec = dec / 16;
    }
    
    hex[i] = '\0';
    
    // Reverse the hexadecimal string
    int len = strlen(hex);
    for(int j=0; j<len/2; j++)
    {
        char temp = hex[j];
        hex[j] = hex[len-j-1];
        hex[len-j-1] = temp;
    }
}

// Function to validate the user input
void inputValidation(char input[])
{
    int len = strlen(input);
    
    if(len != 7)
    {
        printf("Invalid color code! Please enter a 6-digit color code in hexadecimal format.\n");
        exit(0);
    }
    
    if(input[0] != '#')
    {
        printf("Invalid color code! Please enter a color code in hexadecimal format starting with #.\n");
        exit(0);
    }
    
    for(int i=1; i<len; i++)
    {
        if((input[i] < '0' || input[i] > '9') && (input[i] < 'A' || input[i] > 'F'))
        {
            printf("Invalid color code! Please enter a color code in hexadecimal format.\n");
            exit(0);
        }
    }
}