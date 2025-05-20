//FormAI DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>
#define MAX 100

void encryption(char *str, int shift);

int main()
{
    int shift;
    char str[MAX];

    printf("Enter the string to be encrypted: ");
    fgets(str, MAX, stdin);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    encryption(str, shift);
    return 0;
}

void encryption(char *str, int shift)
{
    int i;
    char ch;

    for(i = 0; i < strlen(str); i++)
    {
        ch = str[i];

        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + shift;

            if(ch > 'z')
            {
                ch = ch - 26;
            }
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + shift;

            if(ch > 'Z')
            {
                ch = ch - 26;
            }
        }
        else
        {
            ch = ch;
        }

        printf("%c", ch);
    }
}