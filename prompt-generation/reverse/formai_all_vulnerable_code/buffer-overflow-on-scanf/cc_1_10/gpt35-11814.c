//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i, len, flag = 0;

    printf("Welcome to my C Palindrome Checker!\n\n");

    do
    {
        printf("Please enter a string to check if it is a palindrome: ");
        scanf("%s", str);
        len = strlen(str);
        
        for(i=0 ; i<len/2 ; i++)
        {
            if(str[i] != str[len-i-1])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            printf("\nYes! The given string '%s' is a Palindrome\n", str);
        }
        else
        {
            printf("\nNo! The given string '%s' is Not a Palindrome\n", str);
        }

        flag = 0; // Reset the flag for next input string

        printf("\nDo you want to check another string? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if(choice == 'n')
        {
            break;
        }

    }while(1);

    printf("\nThanks for using my C Palindrome Checker!");

    return 0;
}