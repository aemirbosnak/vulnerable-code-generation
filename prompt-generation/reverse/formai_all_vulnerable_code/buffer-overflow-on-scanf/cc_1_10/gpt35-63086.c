//FormAI DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>

// Function to convert color code from #RRGGBB format to RGB format
int hexToDecimal(char hexVal[])
{
    int len = strlen(hexVal);
    
    // Finding the first character of string
    int base = 1;
    int decVal = 0;
    
    // Extracting characters as digits from last character
    for (int i = len - 1; i >= 0; i--)
    {
        // If character lies in '0'-'9', converting char to digit
        if (hexVal[i] >= '0' && hexVal[i] <= '9')
        {
            decVal += (hexVal[i] - 48) * base;
            
            // Incrementing base by power of 16
            base = base * 16;
        }
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F')
        {
            decVal += (hexVal[i] - 55) * base;
            
            // Incrementing base by power of 16
            base = base * 16;
        }
    }
    
    // Returning integer equivalent of hexVal
    return decVal;
}

int main()
{
    char hexColor[7];
    
    printf("Enter the color code in #RRGGBB format: ");
    scanf("%s", hexColor);
    
    // Extracting RR, GG and BB color codes from hexColor
    char rr[3], gg[3], bb[3];
    strncpy(rr, hexColor + 1, 2);
    strncpy(gg, hexColor + 3, 2);
    strncpy(bb, hexColor + 5, 2);
    rr[2] = gg[2] = bb[2] = '\0';
    
    // Converting hex values to decimal
    int red = hexToDecimal(rr);
    int green = hexToDecimal(gg);
    int blue = hexToDecimal(bb);
    
    // Printing RGB color code
    printf("RGB color code: (%d, %d, %d)\n", red, green, blue);
    
    return 0;
}