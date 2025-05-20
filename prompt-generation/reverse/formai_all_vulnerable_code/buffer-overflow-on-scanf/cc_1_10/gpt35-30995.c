//FormAI DATASET v1.0 Category: String manipulation ; Style: detailed
#include <stdio.h>
#include <string.h>

int main() 
{
    char str1[50], str2[50], temp[50];
    int choice, len1, len2, count = 0;
 
    printf("Enter string 1: ");
    fgets(str1, 50, stdin);
    len1 = strlen(str1);
    printf("Enter string 2: ");
    fgets(str2, 50, stdin);
    len2 = strlen(str2);

    printf("\nChoose an operation to perform on the strings:");
    printf("\n1. Concatenate the strings");
    printf("\n2. Swap the strings");
    printf("\n3. Compare the strings");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            strcat(str1, str2);
            printf("\nAfter concatenation: %s", str1);
            break;

        case 2:
            strcpy(temp, str1);
            strcpy(str1, str2);
            strcpy(str2, temp);
            printf("\nAfter swap: ");
            printf("\nString 1: %s", str1);
            printf("\nString 2: %s", str2);
            break;

        case 3:
            for (int i = 0; i < len1; i++) 
            {
                if (str1[i] == str2[i]) 
                {
                    count++;
                }
            }

            if (count == len1 - 1) 
            {
                printf("\nThe strings are equal");
            } 
            else 
            {
                printf("\nThe strings are not equal");
            }
            break;

        default:
            printf("\nInvalid choice!");
            break;
    }
    return 0;
}