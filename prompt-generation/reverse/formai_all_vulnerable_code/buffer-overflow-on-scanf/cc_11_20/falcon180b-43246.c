//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 1000

int main()
{
    char str[MAX_LEN];
    printf("Enter a string: ");
    scanf("%s", str);

    // Count the number of words in the string
    int count = 0;
    char *ptr = strtok(str, " ");
    while (ptr!= NULL)
    {
        count++;
        ptr = strtok(NULL, " ");
    }
    printf("Number of words: %d\n", count);

    // Reverse the string
    char rev_str[MAX_LEN];
    strcpy(rev_str, str);
    int len = strlen(rev_str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = rev_str[i];
        rev_str[i] = rev_str[len - i - 1];
        rev_str[len - i - 1] = temp;
    }
    printf("Reversed string: %s\n", rev_str);

    // Convert the string to uppercase
    strcpy(str, rev_str);
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = toupper(str[i]);
    }
    printf("Uppercase string: %s\n", str);

    // Count the number of vowels in the string
    int vowel_count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]) && (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'))
        {
            vowel_count++;
        }
    }
    printf("Number of vowels: %d\n", vowel_count);

    return 0;
}