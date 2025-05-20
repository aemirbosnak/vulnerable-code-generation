//FormAI DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[100], c;
    int count = 0, len;

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin); // Read input from user
    len = strlen(text);
    printf("The entered string is: %s", text);

    printf("\nSelect an operation to perform on the string:\n");
    printf("1. Count the number of characters in the string.\n");
    printf("2. Reverse the string.\n");
    printf("3. Convert the string to upper case.\n");
    printf("4. Exit the program.\n");

    scanf("%c", &c); // Read operation choice from user

    switch(c)
    {
        case '1': // Count the number of characters in the string
            for(int i=0; i<len; i++)
            {
                if(text[i] != '\n')
                    count++;
            }
            printf("\nThe number of characters in the string: %d", count);
            break;
        
        case '2': // Reverse the string
            printf("\nThe reversed string is: ");
            for(int i=len-1; i>=0; i--)
            {
                printf("%c", text[i]);
            }
            break;
        
        case '3': // Convert the string to upper case
            printf("\nThe upper case string is: ");
            for(int i=0; i<len; i++)
            {
                printf("%c", toupper(text[i]));
            }
            break;
        
        case '4': // Exit the program
            printf("\nExiting the program...");
            exit(0);
            break;

        default:
            printf("\nInvalid choice. Please try again.");
            break;
    }

    return 0;
}