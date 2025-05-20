//FormAI DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>  

void rgbToHex(int r, int g, int b)  
{  
    char hexValue[7];  
    sprintf(hexValue, "%02x%02x%02x", r, g, b);  
  
    printf("Hex value is #%s\n", hexValue);  
}  
  
void hexToRgb(char* hexValue)  
{  
    int r, g, b;  
    sscanf(hexValue, "%02x%02x%02x", &r, &g, &b);  
  
    printf("RGB values are (%d, %d, %d)\n", r, g, b);  
}  
  
int main()  
{  
    printf("Choose an option:\n");  
    printf("1. Convert RGB to HEX\n");  
    printf("2. Convert HEX to RGB\n");  

    int option;  
    scanf("%d", &option);  

    if (option == 1)  
    {  
        int r, g, b;  
        printf("Enter the RGB values (0-255):\n");  
        scanf("%d %d %d", &r, &g, &b);  

        rgbToHex(r, g, b);  
    }  
    else if (option == 2)  
    {  
        char hexValue[7];  
        printf("Enter the HEX value (without #):\n");  
        scanf("%s", hexValue);  

        hexToRgb(hexValue);  
    }  
    else  
    {  
        printf("Invalid option!\n");  
    }  
  
    return 0;  
}