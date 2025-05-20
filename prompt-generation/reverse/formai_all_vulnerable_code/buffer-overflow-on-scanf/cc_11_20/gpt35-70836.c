//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Alan Touring
// This is a C color code converter program written in Alan Turing-style
// This program converts RGB color code into hexadecimal format and vice versa using mathematical operations

#include <stdio.h>

int main() {
    int option;
    printf("Welcome to the Color Code Converter\n");
    printf("Please select the conversion option:\n");
    printf("1. RGB to Hex\n2. Hex to RGB\n");
    scanf("%d", &option);
  
    if (option == 1) {
        int red, green, blue;
        printf("Enter RGB values between 0 and 255\n");
        printf("Red: ");
        scanf("%d", &red);
        printf("Green: ");
        scanf("%d", &green);
        printf("Blue: ");
        scanf("%d", &blue);
    
        if (red > 255 || green > 255 || blue > 255) {
            printf("Error: RGB value exceeds 255\n");
        } else {
            int hex1 = red / 16;
            int hex2 = red % 16;
            int hex3 = green / 16;
            int hex4 = green % 16;
            int hex5 = blue / 16;
            int hex6 = blue % 16;
      
            printf("The hexadecimal value is: #%X%X%X%X%X%X\n", hex1, hex2, hex3, hex4, hex5, hex6);
        }
    
    } else if (option == 2) {
        char hex[7];
        printf("Enter hexadecimal value (include # before the code): ");
        scanf("%s", hex);
    
        int red = (hex[1] > '9') ? ((hex[1] - 'A' + 10) * 16) : ((hex[1] - '0') * 16);
        red += (hex[2] > '9') ? (hex[2] - 'A' + 10) : (hex[2] - '0');
    
        int green = (hex[3] > '9') ? ((hex[3] - 'A' + 10) * 16) : ((hex[3] - '0') * 16);
        green += (hex[4] > '9') ? (hex[4] - 'A' + 10) : (hex[4] - '0');
    
        int blue = (hex[5] > '9') ? ((hex[5] - 'A' + 10) * 16) : ((hex[5] - '0') * 16);
        blue += (hex[6] > '9') ? (hex[6] - 'A' + 10) : (hex[6] - '0');
    
        printf("The RGB value is: %d %d %d\n", red, green, blue);
        
    } else {
        printf("Error: Invalid option selected. Please try again.\n");
    }
    
    return 0;
}