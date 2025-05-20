//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mathematical
#include<stdio.h>
#include<string.h>

//Function declarations
void rgbToHex(int r, int g, int b);
void hexToRgb(char hexCode[]);

int main()
{
    int r, g, b, option;
    char hexCode[7];

    //Prompt user to choose between RGB to Hex or Hex to RGB conversion
    printf("Choose an option: \n");
    printf("1: Convert RGB to Hex\n");
    printf("2: Convert Hex to RGB\n");
    scanf("%d", &option);

    switch(option)
    {
        case 1: //RGB to Hex conversion
            printf("Enter the RGB values: \n");
            printf("Red: ");
            scanf("%d", &r);
            printf("Green: ");
            scanf("%d", &g);
            printf("Blue: ");
            scanf("%d", &b);
            rgbToHex(r, g, b);
            break;

        case 2: //Hex to RGB conversion
            printf("Enter the hexadecimal code: ");
            scanf("%s", hexCode);
            hexToRgb(hexCode);
            break;

        default:
            printf("Invalid option selected\n");
            break;
    }

    return 0;
}

//Function to convert RGB values to Hex code
void rgbToHex(int r, int g, int b)
{
    int hexCode[6];

    hexCode[0] = r / 16;
    hexCode[1] = r % 16;
    hexCode[2] = g / 16;
    hexCode[3] = g % 16;
    hexCode[4] = b / 16;
    hexCode[5] = b % 16;

    printf("The Hexadecimal code for RGB(%d, %d, %d) is: #", r, g, b);
    for(int i=0; i<6; i++)
    {
        switch(hexCode[i])
        {
            case 0:
                printf("0");
                break;

            case 1:
                printf("1");
                break;

            case 2:
                printf("2");
                break;

            case 3:
                printf("3");
                break;

            case 4:
                printf("4");
                break;

            case 5:
                printf("5");
                break;

            case 6:
                printf("6");
                break;

            case 7:
                printf("7");
                break;

            case 8:
                printf("8");
                break;

            case 9:
                printf("9");
                break;

            case 10:
                printf("A");
                break;

            case 11:
                printf("B");
                break;

            case 12:
                printf("C");
                break;

            case 13:
                printf("D");
                break;

            case 14:
                printf("E");
                break;

            case 15:
                printf("F");
                break;
        }
    }
}

//Function to convert Hex code to RGB values
void hexToRgb(char hexCode[])
{
    int r, g, b;

    //Check if the entered Hex code is valid
    if(strlen(hexCode) != 6)
    {
        printf("Invalid Hexadecimal code\n");
        return;
    }

    //Convert the Hex code into RGB values
    r = (hexCode[0] * 16) + hexCode[1];
    g = (hexCode[2] * 16) + hexCode[3];
    b = (hexCode[4] * 16) + hexCode[5];

    printf("The RGB values for #%s are: (%d, %d, %d)\n", hexCode, r, g, b);
}