//FormAI DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50], str2[50], temp[50];
    int len1, len2;
    
    printf("Enter the first string: ");
    gets(str1);
    
    printf("Enter the second string: ");
    gets(str2);
    
    len1 = strlen(str1);
    len2 = strlen(str2);
    
    printf("\n\nThe length of the first string is %d and the length of the second string is %d.\n\n", len1, len2);
    
    if(len1 > len2)
    {
        printf("The first string is longer than the second string. Swapping the strings...\n\n");
        
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
        
        printf("The first string is now %s and the second string is now %s.\n\n", str1, str2);
    }
    else
    {
        printf("The second string is longer than the first string. Keeping the strings as they are.\n\n");
    }
    
    printf("Concatenating the strings...\n\n");
    
    strcat(str1, str2);
    
    printf("The concatenated string is %s.\n\n", str1);
    
    printf("Converting the first letter of every word in the string to uppercase...\n\n");
    
    for(int i=0; str1[i]!='\0'; i++)
    {
        if(i==0 || str1[i-1]==' ')
        {
            if(str1[i]>='a' && str1[i]<='z')
            {
                str1[i] = str1[i] - 32;
            }
        }
        else if(str1[i]>='A' && str1[i]<='Z')
        {
            str1[i] = str1[i] + 32;
        }
    }
    
    printf("The transformed string is %s.\n\n", str1);
    
    printf("Finding the number of times the word 'surprise' appears in the string...\n\n");
    
    char *ptr = str1;
    int count = 0;
    
    while(ptr = strstr(ptr, "surprise"))
    {
        count++;
        ptr++;
    }
    
    printf("The word 'surprise' appears %d times in the string.\n\n", count);
    
    printf("Replacing all occurrences of the word 'surprise' with 'WOW'...\n\n");
    
    ptr = str1;
    
    while(ptr = strstr(ptr, "surprise"))
    {
        memcpy(ptr, "WOW", 3);
        ptr += 3;
    }
    
    printf("The modified string is %s.\n\n", str1);
    
    return 0;
}