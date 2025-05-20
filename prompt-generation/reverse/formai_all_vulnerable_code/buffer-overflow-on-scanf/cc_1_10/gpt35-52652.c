//FormAI DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary(int n); //function to convert decimal to binary

int main()
{
    int num, choice, i, j, k, flag;
    char str[50], newstr[50];
    printf("Welcome to the Binary Converter!\n\n");
    while (1)
    {
        printf("Enter the type of input:\n1. Decimal\n2. Binary\n3. Quit\n");
        scanf("%d", &choice); //getting input option
        if (choice == 1) //if decimal
        {
            printf("Enter the decimal number you want to convert: ");
            scanf("%d", &num);
            binary(num); //calling binary function
            printf("\n");
        }
        else if (choice == 2) //if binary
        {
            printf("Enter the binary number you want to convert: ");
            scanf("%s", &str);
            for (i = 0; i < strlen(str); i++) //checking if all elements in string are 1 or 0
            {
                if (str[i] != '0' && str[i] != '1')
                {
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                }
            }
            if (flag == 1) //if invalid input
            {
                printf("Invalid input: Enter only binary digits\n");
            }
            else //if valid input
            {
                j = strlen(str) - 1; //getting the last index position of the input string
                k = 0;
                while (j >= 0)
                {
                    newstr[k] = str[j]; //reversing the input string
                    k++;
                    j--;
                }
                newstr[k] = '\0'; //adding null character at the end 
                int decimal = 0;
                for (i = 0; i < strlen(newstr); i++) //converting binary to decimal
                {
                    if (newstr[i] == '1')
                    {
                        decimal += pow(2, i);
                    }
                }
                printf("%d\n", decimal); //printing decimal equivalent
            }
        }
        else if (choice == 3) //if quit
        {
            printf("Thank you for using the Binary Converter!\n");
            break;
        }
        else //if invalid choice
        {
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void binary(int n) //function to convert decimal to binary
{
    int arr[50];
    int i = 0, j;
    while (n > 0)
    {
        arr[i] = n % 2; //getting remainder
        n /= 2; //getting quotient
        i++;
    }
    for (j = i - 1; j >= 0; j--) //printing binary equivalent
    {
        printf("%d", arr[j]);
    }
}