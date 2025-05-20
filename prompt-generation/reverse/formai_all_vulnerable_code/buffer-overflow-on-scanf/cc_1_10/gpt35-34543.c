//FormAI DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 100

//Function declarations
void to_lower(char *);
void to_upper(char *);
int str_cnt(const char *, char);
char *str_rev(const char *);
char *str_copy(char *, const char *);
char *str_cat(char *, const char *);

int main()
{
    char str1[MAX_STR_LEN], str2[MAX_STR_LEN];

    printf("Enter the first string: ");
    fgets(str1, MAX_STR_LEN, stdin);

    printf("Enter the second string: ");
    fgets(str2, MAX_STR_LEN, stdin);

    //String concatenation
    printf("String concatenation: %s\n", str_cat(str1, str2));

    //String copy
    char *str_cpy = str_copy(str1, str2);
    printf("String copy: %s\n", str_cpy);
    free(str_cpy);

    //String reverse
    char *str_rev_ptr = str_rev(str1);
    printf("String reverse: %s\n", str_rev_ptr);
    free(str_rev_ptr);

    //Count the number of occurrences of a character in a string
    char ch;
    printf("Enter the character to count: ");
    scanf("%c", &ch);
    getchar(); //Flush the newline character

    printf("Count of character '%c' in string 1: %d\n", ch, str_cnt(str1, ch));

    //String to lowercase
    to_lower(str1);
    printf("String 1 in lowercase: %s\n", str1);

    //String to uppercase
    to_upper(str2);
    printf("String 2 in uppercase: %s\n", str2);

    return 0;
}

//Functions definitions
void to_lower(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

void to_upper(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

int str_cnt(const char *str, char ch)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == ch)
        {
            count++;
        }
    }
    return count;
}

char *str_rev(const char *str)
{
    int len = strlen(str);
    char *str_rev_ptr = (char *)malloc((len + 1) * sizeof(char));
    if (str_rev_ptr == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    for (int i = 0, j = len - 1; j >= 0; i++, j--)
    {
        str_rev_ptr[i] = str[j];
    }
    str_rev_ptr[len] = '\0';

    return str_rev_ptr;
}

char *str_copy(char *dest, const char *src)
{
    int len = strlen(src);
    char *dest_ptr = (char *)malloc((len + 1) * sizeof(char));
    if (dest_ptr == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    for (int i = 0; i <= len; i++)
    {
        dest_ptr[i] = src[i];
    }

    return dest_ptr;
}

char *str_cat(char *dest, const char *src)
{
    int len_dest = strlen(dest);
    int len_src = strlen(src);

    for (int i = 0, j = len_dest; j <= (len_dest + len_src); i++, j++)
    {
        dest[j] = src[i];
    }

    return dest;
}