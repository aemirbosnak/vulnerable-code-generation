//FormAI DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int choice, len1, len2;

    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    len1 = strlen(str1)-1;

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    len2 = strlen(str2)-1;

    printf("\n\t\t--------------------\n");
    printf("\t\tString Manipulation\n");
    printf("\t\t--------------------\n\n");
    printf("Menu:\n");
    printf("1. Concatenate two strings\n");
    printf("2. Copy one string to another\n");
    printf("3. Compare two strings\n");
    printf("4. Reverse a string\n");
    printf("5. Count vowels in a string\n");
    printf("6. Convert string to uppercase\n");
    printf("7. Convert string to lowercase\n");
    printf("8. Exit\n\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("\nString Concatenation\n");
                printf("--------------------\n");
                printf("Concatenated String: %s%s\n", str1, str2);
                break;
            }
            case 2:
            {
                printf("\nString Copy\n");
                printf("-----------\n");
                strcpy(str2, str1);
                printf("Copied String: %s\n", str2);
                break;
            }
            case 3:
            {
                printf("\nString Comparison\n");
                printf("------------------\n");
                if(strcmp(str1, str2) == 0)
                {
                    printf("The strings are equal.\n");
                }
                else
                {
                    printf("The strings are not equal.\n");
                }
                break;
            }
            case 4:
            {
                printf("\nString Reversal\n");
                printf("----------------\n");
                for(int i=len1-1; i>=0; i--)
                {
                    printf("%c", str1[i]);
                }
                printf("\n");
                break;
            }
            case 5:
            {
                printf("\nVowel Count\n");
                printf("------------\n");
                int count=0;
                for(int i=0; i<len1; i++)
                {
                    if(str1[i]=='a' || str1[i]=='e' || str1[i]=='i' || str1[i]=='o' || str1[i]=='u' || str1[i]=='A' || str1[i]=='E' || str1[i]=='I' || str1[i]=='O' || str1[i]=='U')
                    {
                        count++;
                    }
                }
                printf("Number of vowels in string: %d\n", count);
                break;
            }
            case 6:
            {
                printf("\nUppercase Conversion\n");
                printf("---------------------\n");
                for(int i=0; i<len1; i++)
                {
                    if(str1[i]>=97 && str1[i]<=122)
                    {
                        str1[i] = str1[i]-32;
                    }
                }
                printf("Uppercase String: %s\n", str1);
                break;
            }
            case 7:
            {
                printf("\nLowercase Conversion\n");
                printf("---------------------\n");
                for(int i=0; i<len1; i++)
                {
                    if(str1[i]>=65 && str1[i]<=90)
                    {
                        str1[i] = str1[i]+32;
                    }
                }
                printf("Lowercase String: %s\n", str1);
                break;
            }
            case 8:
            {
                printf("\nExiting Program\n");
                printf("----------------\n");
                break;
            }
            default:
            {
                printf("\nInvalid choice. Try again.\n");
            }
        }

    }while(choice != 8);

    return 0;
}