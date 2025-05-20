//FormAI DATASET v1.0 Category: Color Code Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void convertToRGB(int hexValue){
    int red = (hexValue >> 16) & 0xFF;
    int green = (hexValue >> 8) & 0xFF;
    int blue = hexValue & 0xFF;
    printf("RGB value is: (%d, %d, %d)\n", red, green, blue);
}

void convertToHex(int red, int green, int blue){
    int hexValue = (red << 16) | (green << 8) | blue;
    printf("Hex value is: #%06X\n", hexValue);
}

int main() {
    int choice;
    printf("\nWelcome to the Color Code Converter!\n\n");
    while(1){
        printf("Enter 1 to convert RGB to HEX\n");
        printf("Enter 2 to convert HEX to RGB\n");
        printf("Enter 3 to exit the program\n");
        scanf("%d", &choice);
        if(choice == 1){
            int red, green, blue;
            printf("\nEnter the values for Red, Green, and Blue respectively:\n");
            scanf("%d%d%d", &red, &green, &blue);
            if(red > 255 || green > 255 || blue > 255){
                printf("Invalid Input! Please enter values between 0 and 255.\n\n");
                continue;
            }
            convertToHex(red, green, blue);
            printf("\n");
        }
        else if(choice == 2){
            int hexValue;
            printf("\nEnter the HEX code without the '#' symbol:\n");
            scanf("%X", &hexValue);
            convertToRGB(hexValue);
            printf("\n");
        }
        else if(choice == 3){
            printf("\nThank you for using our Color Code Converter!\n\n");
            break;
        }
        else{
            printf("\nInvalid Input! Please enter a valid choice.\n\n");
        }
    }
    return 0;
}