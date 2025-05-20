//FormAI DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[50], str2[50], temp[50];
    int opt, len, i, j;

    printf("Enter the first string: ");
    fgets(str1, 50, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // remove the newline character from the input

    printf("\nEnter the second string: ");
    fgets(str2, 50, stdin);
    str2[strcspn(str2, "\n")] = '\0'; // remove the newline character from the input
    
    printf("\nChoose an option:\n1. Concatenate\n2. Reverse\n3. Swap\n4. Exit\n");
    scanf("%d", &opt);

    switch(opt)
    {
        case 1: // concatenate
            strcat(str1, str2);
            printf("\nConcatenated string: %s\n", str1);
            break;

        case 2: // reverse
            len = strlen(str1);
            for(i=0,j=len-1; i<len/2; i++,j--)
            {
                temp[i] = str1[i];
                str1[i] = str1[j];
                str1[j] = temp[ i];
            }
            printf("\nReversed string: %s\n", str1);
            break;

        case 3: // swap
            strcpy(temp, str1);
            strcpy(str1, str2);
            strcpy(str2, temp);
            printf("\nSwapped strings:\nString 1: %s\nString 2: %s\n", str1, str2);
            break;

        case 4: // exit
            printf("\nExiting program.\n");
            exit(0);

        default: // invalid input
            printf("\nInvalid option. Please choose again.\n");
            break;
    }

    return 0;
}