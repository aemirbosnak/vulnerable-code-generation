//FormAI DATASET v1.0 Category: Color Code Converter ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

//Function prototypes
void RGBtoHex(int, int, int);
void HexToRGB(char[]);

int main(){
    int choice,r,g,b;
    char hex[7];

    do{
        printf("\n\n\tColor Converter\n\n");
        printf("1. RGB to Hex\n");
        printf("2. Hex to RGB\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: //RGB to Hex Conversion
                printf("\n\tRGB to HEX conversion\n");
                printf("Enter value for Red (0-255): ");
                scanf("%d",&r);
                printf("Enter value for Green (0-255): ");
                scanf("%d",&g);
                printf("Enter value for Blue (0-255): ");
                scanf("%d",&b);
                RGBtoHex(r,g,b);
                break;
            case 2: //Hex to RGB Conversion
                printf("\n\tHEX to RGB conversion\n");
                printf("Enter a hexadecimal value: ");
                scanf("%s",hex);
                HexToRGB(hex);
                break;
            case 3: //Exit the program
                exit(0);
                break;
            default:
                printf("\nInvalid choice, try again!\n");
        }
    }while(choice<3);

    return 0;
}

/*Function to convert RGB to Hex code*/
void RGBtoHex(int r, int g, int b){
    char hex[7];
    sprintf(hex,"%02X%02X%02X",r,g,b);
    printf("Hex code for the given RGB values is #%s\n",hex);
}

/*Function to convert Hex to RGB code*/
void HexToRGB(char hex[]){
    int r,g,b;
    sscanf(hex,"%02X%02X%02X",&r,&g,&b);
    printf("RGB representation for the given HEX value is %d %d %d\n",r,g,b);
}