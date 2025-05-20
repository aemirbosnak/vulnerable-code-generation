//FormAI DATASET v1.0 Category: Color Code Converter ; Style: relaxed
#include<stdio.h>

//function to convert hexadecimal to decimal
int hexToDec(char hex[]){
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    int i;

    for(i=len-1; i>=0; i--){
        if(hex[i]>='0' && hex[i]<='9'){
            dec += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i]>='A' && hex[i]<='F'){
            dec += (hex[i] - 55) * base;
            base *= 16;
        }
        else if(hex[i]>='a' && hex[i]<='f'){
            dec += (hex[i] - 87) * base;
            base *= 16;
        }   
    }
    return dec;
}

//function to convert RGB to hexadecimal
void rgbToHex(int r, int g, int b){
    char hex[7];

    sprintf(hex, "%02X%02X%02X", r, g, b);
    printf("Hexadecimal equivalent: #%s\n", hex);
}

//function to convert hexadecimal to RGB
void hexToRgb(char hex[]){
    int r, g, b;

    r = hexToDec(strncpy(hex, 1, 2));
    g = hexToDec(strncpy(hex, 3, 2));
    b = hexToDec(strncpy(hex, 5, 2));

    printf("RGB equivalent: (%d,%d,%d)\n", r, g, b);
}

int main(){
    int choice, r, g, b;
    char hex[7];

    do{
        printf("\nChoose the conversion you would like to perform:\n");
        printf("1. RGB to hexadecimal\n");
        printf("2. Hexadecimal to RGB\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: printf("Enter the RGB values (0-255):\n");
                    printf("Red: ");
                    scanf("%d", &r);
                    printf("Green: ");
                    scanf("%d", &g);
                    printf("Blue: ");
                    scanf("%d", &b);
                    rgbToHex(r, g, b);
                    break;
            case 2: printf("Enter the hexadecimal code: ");
                    scanf("%s", hex);
                    hexToRgb(hex);
                    break;
            case 3: printf("Exiting program...\n");
                    break;
            default: printf("Invalid choice. Please try again.\n");
        }

    }while(choice != 3);

    return 0;
}