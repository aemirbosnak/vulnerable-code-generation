//FormAI DATASET v1.0 Category: String manipulation ; Style: scientific
#include <stdio.h>
#include <string.h>

int main()
{
    char string1[100];
    char string2[100];
    int len1, len2, i;
    printf("Enter the first string: ");
    fgets(string1,100,stdin);
    printf("Enter the second string: ");
    fgets(string2,100,stdin);
    
    len1 = strlen(string1);
    len2 = strlen(string2);
    
    printf("\n---- String Manipulation Program ----\n\n");
    
    printf("The length of the first string is: %d\n",len1);
    printf("The length of the second string is: %d\n",len2);

    printf("\n---- Concatenation ----\n\n");
    
    printf("The concatenated string is: ");
    strcat(string1,string2);
    puts(string1);

    printf("\n---- Copying ----\n\n");

    strcpy(string2,string1);
    printf("The copied string is: ");
    puts(string2);

    printf("\n---- Reversal ----\n\n");

    printf("The reversed string is: ");
    for(i=(len1-2); i>=0; i--)
    {
        printf("%c",string1[i]);
    }
    printf("\n");

    printf("\n---- Substring ----\n\n");

    char substring[20];
    int start, end;
    printf("Enter the starting index of the substring: ");
    scanf("%d",&start);
    printf("Enter the ending index of the substring: ");
    scanf("%d",&end);

    if (end > len1)
    {
        printf("Error: Ending index is out of range\n");
        return -1;
    }
    else if (start < 0)
    {
        printf("Error: Starting index is out of range\n");
        return -1;
    }
    else if (start > end)
    {
        printf("Error: Starting index is greater than ending index\n");
        return -1;
    }
    
    for (i=0; i<(end-start+1); i++)
    {
        substring[i] = string1[start+i];
    }
    substring[i] = '\0';
    printf("The substring is: %s\n",substring);

    return 0;
}