//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

int main()
{
    char str1[MAX_STR_LEN], str2[MAX_STR_LEN];

    printf("Enter two strings: ");
    scanf("%s %s", str1, str2);

    // Concatenate the two strings
    char *str3 = (char *)malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(str3, str1);
    strcat(str3, str2);

    // Reverse the concatenated string
    char *str4 = (char *)malloc(strlen(str3) + 1);
    int i;
    for (i = 0; i < strlen(str3); i++)
    {
        str4[i] = str3[strlen(str3) - i - 1];
    }
    str4[i] = '\0';

    // Find the length of the longest common substring
    int max_len = 0;
    int start = 0;
    for (i = 0; i < strlen(str1); i++)
    {
        for (int j = 0; j < strlen(str2); j++)
        {
            int k;
            for (k = 0; i + k < strlen(str1) && j + k < strlen(str2) && str1[i + k] == str2[j + k]; k++)
            {
                ;
            }
            if (k > max_len)
            {
                max_len = k;
                start = i;
            }
        }
    }

    // Print the results
    printf("Concatenated string: %s\n", str3);
    printf("Reversed concatenated string: %s\n", str4);
    if (max_len == 0)
    {
        printf("No common substring found.\n");
    }
    else
    {
        printf("Longest common substring: %s\n", str1 + start);
        printf("Length of longest common substring: %d\n", max_len);
    }

    free(str3);
    free(str4);

    return 0;
}