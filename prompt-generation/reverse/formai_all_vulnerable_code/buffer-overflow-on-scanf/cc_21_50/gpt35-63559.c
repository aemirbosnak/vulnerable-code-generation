//FormAI DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int choice, len, i, j, k, l, m;
    
    printf("Retro Style String Manipulation Program\n");
    
    do
    {
        printf("\nChoose an option from the following:\n");
        printf("1. Reverse the string\n");
        printf("2. Remove vowels from the string\n");
        printf("3. Replace a character in the string\n");
        printf("4. Check if string is palindrome\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: // Reverse the string
                printf("\nEnter a string: ");
                scanf("%s", str);
                len = strlen(str);
                for(i = 0, j = len-1; i < j; i++, j--)
                {
                    char temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
                printf("Reversed string: %s\n", str);
                break;
                
            case 2: // Remove vowels from the string
                printf("\nEnter a string: ");
                scanf("%s", str);
                len = strlen(str);
                for(i = 0; i < len; i++)
                {
                    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') 
                    {
                        for(j = i; j < len; j++)
                        {
                            str[j] = str[j+1];
                        }
                        len--;
                        i--;
                    }
                }
                printf("String without vowels: %s\n", str);
                break;
                
            case 3: // Replace a character in the string
                printf("\nEnter a string: ");
                scanf("%s", str);
                len = strlen(str);
                printf("Enter the character to be replaced: ");
                char old_char, new_char;
                scanf(" %c", &old_char);
                printf("Enter the new character: ");
                scanf(" %c", &new_char);
                for(i = 0; i < len; i++)
                {
                    if(str[i] == old_char)
                    {
                        str[i] = new_char;
                    }
                }
                printf("String after replacement: %s\n", str);
                break;
                
            case 4: // Check if string is palindrome
                printf("\nEnter a string: ");
                scanf("%s", str);
                len = strlen(str);
                for(i = 0, j = len-1; i < j; i++, j--)
                {
                    if(str[i] != str[j])
                    {
                        printf("Not a palindrome\n");
                        break;
                    }
                }
                if(i >= j)
                {
                    printf("Palindrome\n");
                }
                break;
                
            case 5: // Exit
                printf("\nGoodbye!\n");
                break;
                
            default:
                printf("\nInvalid choice, try again\n");
        }
        
    }while(choice != 5);

    return 0;
}