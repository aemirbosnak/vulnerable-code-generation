//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Function to count frequency of a character
int count(char *str, char ch)
{
    int count = 0;
    while (*str)
    {
        if (*str == ch)
            count++;
        str++;
    }
    return count;
}

// Function to print the most common character in the given string
void print_most_common(char *str)
{
    int freq[26] = {0};
    int max_freq = 0, max_char;
    for (int i = 0; i < strlen(str); i++)
    {
        int ch = (int)str[i];
        freq[ch - 'a']++;
        if (freq[ch - 'a'] > max_freq)
        {
            max_freq = freq[ch - 'a'];
            max_char = ch;
        }
    }
    printf("The most common character in the given string is %c and its frequency is %d\n", max_char, max_freq);
}

int main()
{
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Frequency of each character in the string:\n");
    for (int i = 0; i < strlen(str); i++)
    {
        int ch = (int)str[i];
        printf("%c: %d\n", ch, count(str, ch));
    }
    print_most_common(str);
    return 0;
}