//FormAI DATASET v1.0 Category: String manipulation ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50], str2[50], puzzle[50], check[50];
    int len1, len2, i, j, k, flag = 0;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);
    
    // creating a puzzle by alternating characters of two strings
    for(i=0, j=0, k=0; i<len1, j<len2; i++, j++)
    {
        puzzle[k++] = str1[i];
        puzzle[k++] = str2[j];
    }

    if(len1 > len2)
    {
        while(i < len1)
            puzzle[k++] = str1[i++];
    }
    else if(len2 > len1)
    {
        while(j < len2)
            puzzle[k++] = str2[j++];
    }

    puzzle[k] = '\0';

    printf("\nPuzzle string: %s\n\n", puzzle);

    // checking if the puzzle string can form given strings
    int p_len = strlen(puzzle), c_len;
    for(i=1; i<=p_len; i++)
    {
        for(j=0; j<i; j++)
            check[j] = puzzle[j];
        check[j] = '\0';

        c_len = strlen(check);
        if(c_len > len1 || c_len > len2)
            break;

        flag = 1;
        for(j=0, k=0; j<c_len; j+=2, k++)
        {
            if(check[j] != str1[k])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            for(j=1, k=0; j<c_len; j+=2, k++)
            {
                if(check[j] != str2[k])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                printf("Yes, puzzle string can form given strings.\n");
                return 0;
            }
        }
    }

    printf("No, puzzle string cannot form given strings.\n");
    return 0;
}