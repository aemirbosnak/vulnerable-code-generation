//FormAI DATASET v1.0 Category: Binary Converter ; Style: innovative
#include<stdio.h>
#include<math.h>

void binary_conversion(int number) //Function for binary conversion
{
    int binary_array[32], i=0; //Initialize variables

    while(number != 0)  //Loop until number becomes 0
    {
        binary_array[i] = number % 2; //Store binary remainder in an array
        number = number/2; //Dividing the quotient by 2 to get the remainder
        i++;
    }

    printf("\nBinary equivalent of the given number is: "); //Print binary equivalent of the given number
    for(i=i-1; i>=0; i--) //Loop for printing binary number
    {
        printf("%d", binary_array[i]);
    }

    printf("\n");
}

int decimal_conversion(long binary_number) //Function for decimal conversion
{
    int decimal_number=0, i=0, remainder;

    while(binary_number != 0) //Loop until binary_number becomes 0
    {
        remainder = binary_number % 10; //Calculate remainder
        binary_number = binary_number / 10; //Divide the quotient by 10 to get the remainder

        decimal_number = decimal_number + remainder * pow(2,i); //Convert binary to decimal
        i++;
    }

    return decimal_number; //Return the decimal number
}

int main()
{
    int choice, number;
    long binary_number;

    printf("***BINARY CONVERTER PROGRAM***\n\n");

    do {
        printf("Choose one of the following number systems:\n");
        printf("1. Decimal to Binary conversion\n");
        printf("2. Binary to Decimal conversion\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); //Take user input for choice

        if (choice == 1) //If choice is 1 then perform decimal to binary conversion
        {
            printf("\nEnter decimal number to convert to binary: ");
            scanf("%d", &number); //Take user input for decimal number

            if (number < 0) //Check if number is negative
            {
                printf("\nInvalid Input! Number should be non-negative.\n");
            }
            else
            {
                binary_conversion(number); //Function call for binary conversion
            }
        }
        else if (choice == 2) //If choice is 2 then perform binary to decimal conversion
        {
            printf("\nEnter binary number to convert to decimal: ");
            scanf("%ld", &binary_number); //Take user input for binary number

            if (binary_number < 0) //Check if number is negative
            {
                printf("\nInvalid Input! Number should be non-negative.\n");
            }
            else
            {
                printf("\nDecimal equivalent of the given binary number is: %d\n", decimal_conversion(binary_number)); //Function call for decimal conversion
            }
        }
        else if (choice == 3) //If choice is 3 then exit the program
        {
            printf("\nExiting program...Thanks for using our converter!\n");
            break;
        }
        else //If choice is invalid then print error message and ask for input again
        {
            printf("\nInvalid choice! Please choose 1, 2, or 3 only.\n");
        }

    }while(choice != 3); //Loop until choice is 3

    return 0;
}