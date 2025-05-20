//Gemma-7B DATASET v1.0 Category: Firewall ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1024];
    int i, j, k, l, m, n;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("String: %s\n", str);

    i = 0;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
    n = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            j++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            k++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            l++;
        }
        else if (str[i] == ' ')
        {
            m++;
        }
        else if (str[i] == '.')
        {
            n++;
        }

        i++;
    }

    printf("Number of lowercase letters: %d\n", j);
    printf("Number of uppercase letters: %d\n", k);
    printf("Number of digits: %d\n", l);
    printf("Number of spaces: %d\n", m);
    printf("Number of dots: %d\n", n);

    return 0;
}