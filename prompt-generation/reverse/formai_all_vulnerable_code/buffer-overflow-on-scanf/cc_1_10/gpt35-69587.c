//FormAI DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50], str2[50], temp[50];
    int i, j, choice, length;

    printf("Enter a string: ");
    scanf("%s", str1); //Scanning first string

    printf("\nChoose an operation: \n1. String Copy\n2. String Concatenation\n3. String Reversal\n");
    scanf("%d", &choice);

    switch(choice)
    {
        //String Copy Operation
        case 1:
            strcpy(str2, str1); //Copying one string to another
            printf("\nOriginal string: %s\nCopied string: %s\n", str1, str2);
            break;

        //String Concatenation
        case 2:
            printf("\nEnter another string: ");
            scanf("%s", str2); //Scanning second string

            strcat(str1, str2); //Concatenating two strings
            printf("\nConcatenated string: %s\n", str1);
            break;

        //String Reversal
        case 3:
            length = strlen(str1);

            //Reversing the string using a temporary variable
            for(i=0, j=length-1; i<j; i++, j--)
            {
                temp[i] = str1[i];
                str1[i] = str1[j];
                str1[j] = temp[i];
            }
            
            printf("\nReversed string: %s\n", str1);
            break;

        default:
            printf("\nInvalid choice.\n");
    }

    return 0;
}