//FormAI DATASET v1.0 Category: String manipulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    int choice, length, position, i;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    while (1)
    {
        printf("Select an option to manipulate the string:\n");
        printf("1. Get length of the string\n");
        printf("2. Reverse the string\n");
        printf("3. Convert string to uppercase\n");
        printf("4. Convert string to lowercase\n");
        printf("5. Replace character in string\n");
        printf("6. Remove character from string\n");
        printf("Enter 0 to exit.\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 0:
                printf("Exiting program.\n");
                exit(0);
                break;
            case 1:
                length = strlen(str);
                printf("Length of the string is %d\n", length);
                break;
            case 2:
                for (i = strlen(str)-1; i >= 0; i--)
                    printf("%c", str[i]);
                printf("\n");
                break;
            case 3:
                for (i = 0; str[i] != '\0'; i++)
                {
                    if (str[i] >= 'a' && str[i] <= 'z')
                        str[i] = str[i] - 32;
                }
                printf("String in uppercase: %s\n", str);
                break;
            case 4:
                for (i = 0; str[i] != '\0'; i++)
                {
                    if (str[i] >= 'A' && str[i] <= 'Z')
                        str[i] = str[i] + 32;
                }
                printf("String in lowercase: %s\n", str);
                break;
            case 5:
                printf("Enter character to replace: ");
                char searchChar;
                getchar();
                scanf("%c", &searchChar);

                printf("Enter character to replace with: ");
                char replaceChar;
                getchar();
                scanf("%c", &replaceChar);

                for (i = 0; str[i] != '\0'; i++)
                {
                    if (str[i] == searchChar)
                        str[i] = replaceChar;
                }
                printf("String after replacing %c with %c: %s\n", searchChar, replaceChar, str);
                break;
            case 6:
                printf("Enter position of character to remove: ");
                scanf("%d", &position);

                memmove(&str[position], &str[position+1], strlen(str)-position);
                printf("String after removing character at position %d: %s\n", position, str);
                break;
            default:
                printf("Invalid option, try again.\n");
                break;
        }
    }

    return 0;
}