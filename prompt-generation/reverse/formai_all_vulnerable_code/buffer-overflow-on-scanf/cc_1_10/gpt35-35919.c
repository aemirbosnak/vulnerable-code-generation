//FormAI DATASET v1.0 Category: Binary Converter ; Style: funny
#include<stdio.h>
#include<stdlib.h>

void convert(int); //function prototype declaration

int main()
{
    int decimal, choice;

    printf("Welcome to the Crazy Binary Converter!\n");

    do // We use a do-while loop to execute the menu options repeatedly until the user exits the program.
    {
        printf("\nPlease select from the following options:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Exit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nPlease enter a decimal number: ");
                scanf("%d", &decimal);
                printf("The binary equivalent of %d is: ", decimal);
                convert(decimal); // Function call
                break;

            case 2:
                printf("\nThanks for using the Crazy Binary Converter! See ya later, alligator!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Try again, pumpkin.\n");
                break;
        }
    } while(choice != 2);

    return 0;
}

void convert(int decimal)
{
    int i, j, binary[32];

    if(decimal == 0) // If the decimal number entered is zero, then its binary equivalent will also be zero.
    {
        printf("0");
        return;
    }

    for(i = 0; decimal > 0; i++) // A loop that runs until the decimal number becomes zero.
    {
        binary[i] = decimal % 2; // Dividing the decimal number by 2 and storing the remainder in an array.
        decimal = decimal / 2;
    }

    for(j = i - 1; j >= 0; j--) // A loop that runs from the last index of the array to the first, to display the binary number in the correct order.
    {
        printf("%d", binary[j]);
    }
}