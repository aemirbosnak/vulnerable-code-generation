//Falcon-180B DATASET v1.0 Category: Encryption ; Style: recursive
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

void encrypt(char *str, int key, int n);

int main()
{
    char str[MAX];
    printf("Enter the string to be encrypted: ");
    scanf("%[^\n]", str);
    int key, n;
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    printf("Enter the number of times to encrypt: ");
    scanf("%d", &n);
    encrypt(str, key, n);
    return 0;
}

void encrypt(char *str, int key, int n)
{
    if(n == 0)
    {
        printf("%s", str);
        return;
    }
    else if(n == 1)
    {
        int len = strlen(str);
        for(int i=0; i<len; i++)
        {
            if(isalpha(str[i]))
            {
                if(isupper(str[i]))
                {
                    str[i] = str[i] + key - 65;
                }
                else
                {
                    str[i] = str[i] + key - 97;
                }
            }
        }
        printf("%s", str);
        return;
    }
    else
    {
        encrypt(str, key, n-1);
        encrypt(str, key, n-1);
    }
}