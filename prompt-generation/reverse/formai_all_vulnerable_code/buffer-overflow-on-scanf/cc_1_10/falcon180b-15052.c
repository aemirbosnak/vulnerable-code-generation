//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 100

int main()
{
    char str[MAX_LEN];
    int len, i, j, k;
    
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    
    // Convert string to lowercase
    for(i = 0; i < len; i++)
    {
        if(isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
    
    // Find the longest palindrome substring
    int start = 0, end = 0;
    for(i = 0; i < len; i++)
    {
        int isPalindrome = 1;
        for(j = i, k = i; j < len && k >= 0; j++, k--)
        {
            if(str[j]!= str[k])
            {
                isPalindrome = 0;
                break;
            }
        }
        if(isPalindrome && j - i + 1 > end - start)
        {
            start = i;
            end = j;
        }
    }
    
    // Print the longest palindrome substring
    printf("The longest palindrome substring is: ");
    for(i = start; i <= end; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    
    return 0;
}