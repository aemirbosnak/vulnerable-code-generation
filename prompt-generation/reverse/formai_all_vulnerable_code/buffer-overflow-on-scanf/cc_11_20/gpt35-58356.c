//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main()
{
    char string[100], copy[100];
    int i, j, choice;

    printf("Enter a string: ");
    scanf("%s", string);

    printf("Select an operation:\n");
    printf("1. Reverse the string\n");
    printf("2. Copy the string\n");
    printf("3. Replace vowels with *\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1: // reverse the string
            j = strlen(string) - 1;
            for(i = 0; i < strlen(string); i++)
            {
                copy[i] = string[j];
                j--;
            }
            copy[i] = '\0'; // add null character to end of copied string
            printf("Reversed string: %s\n", copy);
            break;

        case 2: // copy the string
            strcpy(copy, string); // using strcpy to copy string
            printf("Copied string: %s\n", copy);
            break;

        case 3: // replace vowels with *
            for(i = 0; i < strlen(string); i++)
            {
                if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
                {
                    copy[i] = '*';
                }
                else
                {
                    copy[i] = string[i];
                }
            }
            copy[i] = '\0'; // add null character to end of copied string
            printf("String with vowels replaced: %s\n", copy);
            break;

        default: // Invalid choice
            printf("Invalid choice.\n");
    }

    return 0;
}