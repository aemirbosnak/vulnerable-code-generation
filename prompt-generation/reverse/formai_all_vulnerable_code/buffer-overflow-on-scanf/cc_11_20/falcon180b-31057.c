//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[])
{
    char input[MAX_SIZE], output[MAX_SIZE];
    int i, j, choice;

    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Enter 1 to convert from hexadecimal to decimal\n");
    printf("Enter 2 to convert from decimal to hexadecimal\n");
    printf("Enter 3 to exit\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter a hexadecimal number: ");
            scanf("%s", input);

            for(i = 0, j = strlen(input) - 1; i < strlen(input); i++, j--)
            {
                if(input[i] >= '0' && input[i] <= '9')
                {
                    output[j] = input[i] - '0';
                }
                else if(input[i] >= 'A' && input[i] <= 'F')
                {
                    output[j] = input[i] - 'A' + 10;
                }
                else if(input[i] >= 'a' && input[i] <= 'f')
                {
                    output[j] = input[i] - 'a' + 10;
                }
                else
                {
                    printf("Invalid input!\n");
                    exit(0);
                }
            }

            printf("Decimal equivalent: %s\n", output);
            break;

        case 2:
            printf("Enter a decimal number: ");
            scanf("%s", input);

            for(i = strlen(input) - 1, j = 0; i >= 0; i--, j++)
            {
                if(input[i] >= '0' && input[i] <= '9')
                {
                    output[j] = input[i];
                }
                else
                {
                    printf("Invalid input!\n");
                    exit(0);
                }
            }

            printf("Hexadecimal equivalent: %s\n", output);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    return 0;
}