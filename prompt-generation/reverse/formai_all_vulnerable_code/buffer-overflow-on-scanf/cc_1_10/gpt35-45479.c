//FormAI DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>

//Function to convert RGB values to Hexadecimal Color Code
void RGBtoHex(int r, int g, int b)
{
    //Initialize variables to store hexadecimal values for R, G and B
    char hex[7];
  
    //Convert the RGB values to Hexadecimal values
    sprintf(hex,"#%02X%02X%02X", r, g, b);

    //Print the Hexadecimal Color Code
    printf("The Hexadecimal Color Code is: %s", hex);
}

//Function to convert Hexadecimal Color Code to RGB values
void HexToRGB(char hex[])
{
    //Initialize variables to store hexadecimal values for R, G and B
    int r, g, b;
  
    //Convert the Hexadecimal Color Code to RGB values
    sscanf(hex,"#%02X%02X%02X", &r, &g, &b);

    //Print the RGB values
    printf("The RGB values are: (%d,%d,%d)", r, g, b);
}

int main()
{
    int choice, r, g, b;
    char hex[7];

    //Loop to display menu until the user chooses to exit
    do
    {
        //Display menu
        printf("\n----------------------------------------\n");
        printf("\tC Color Code Converter");
        printf("\n----------------------------------------\n");
        printf("1. RGB to Hexadecimal Conversion");
        printf("\n2. Hexadecimal to RGB Conversion");
        printf("\n3. Exit");
        printf("\n----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Switch case to perform the conversion based on user's choice
        switch(choice)
        {
            case 1:
                //Prompt user for RGB values
                printf("Enter the Red value (0-255): ");
                scanf("%d", &r);
                printf("Enter the Green value (0-255): ");
                scanf("%d", &g);
                printf("Enter the Blue value (0-255): ");
                scanf("%d", &b);

                //Convert RGB values to Hexadecimal Color Code
                RGBtoHex(r,g,b);
                break;

            case 2:
                //Prompt user for Hexadecimal Color Code
                printf("Enter the Hexadecimal Color Code (e.g. #FFAABB): ");
                scanf("%s", hex);

                //Convert Hexadecimal Color Code to RGB values
                HexToRGB(hex);
                break;

            case 3:
                //Exit the program
                printf("\nExiting...\n");
                break;

            default:
                //Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 3);

    return 0;
}