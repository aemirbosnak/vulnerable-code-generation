//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    FILE *fp;
    char filename[100], ch;
    int i, j, n, sum, key, k, count = 0;
    char text[1000], cipher[1000];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("File not found!\n");
        return 0;
    }

    printf("Enter the key: ");
    scanf("%d", &key);

    while((ch = getc(fp))!= EOF)
    {
        if(isalpha(ch))
        {
            text[count++] = ch;
        }
    }

    n = count;
    sum = 0;

    for(i = 0; i < n; i++)
    {
        sum += text[i];
    }

    k = sum % key;

    for(i = 0; i < n; i++)
    {
        cipher[i] = text[i] + k;

        if(isupper(text[i]))
        {
            cipher[i] = cipher[i] % 26 + 65;
        }
        else
        {
            cipher[i] = cipher[i] % 26 + 97;
        }
    }

    for(i = 0; i < n; i++)
    {
        printf("%c", cipher[i]);
    }

    fclose(fp);
    return 0;
}