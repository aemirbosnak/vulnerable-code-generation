//Falcon2-11B DATASET v1.0 Category: String manipulation ; Style: shape shifting
#include<stdio.h>
#include<string.h>

// Function to get the length of the string
int getLength(char *str)
{
    int len = 0;
    while (str[len]!= '\0')
        len++;
    return len;
}

// Function to reverse the string
void reverseString(char *str)
{
    int len = getLength(str);
    char temp;
    for (int i = 0; i < len/2; i++)
    {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to print the string in a different case
void changeCase(char *str, int caseNum)
{
    int len = getLength(str);
    for (int i = 0; i < len; i++)
    {
        if (caseNum == 0)
            str[i] = str[i];
        else if (caseNum == 1)
            str[i] = toupper(str[i]);
        else
            str[i] = tolower(str[i]);
    }
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    printf("Original string: %s\n", str);
    
    // Reverse the string
    reverseString(str);
    printf("Reversed string: %s\n", str);
    
    // Change the case of the string
    changeCase(str, 1);
    printf("String with capital case: %s\n", str);
    
    changeCase(str, 0);
    printf("String with lower case: %s\n", str);
    
    return 0;
}