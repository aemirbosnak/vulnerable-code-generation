//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <limits.h>

int main()
{
    int decimal = 0, binary = 0, choice;
    char buffer[100];

    do
    {
        printf("\nBinary Converter\n");
        printf("--------------------\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                printf("The binary equivalent of %d is: ", decimal);
                for(int i=0; i<=31; i++)
                {
                    if(decimal & (1<<i))
                    {
                        printf("1");
                    }
                    else
                    {
                        printf("0");
                    }
                }
                printf("\n");
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", buffer);
                binary = strtol(buffer, NULL, 2);
                printf("The decimal equivalent of %s is: %d\n", buffer, binary);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice!= 3);

    return 0;
}