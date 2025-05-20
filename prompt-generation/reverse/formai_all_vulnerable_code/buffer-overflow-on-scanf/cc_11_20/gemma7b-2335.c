//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], str3[100], str4[100], str5[100];
    int i, j, k, l, m, n, flag = 0;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("Enter the third string: ");
    scanf("%s", str3);

    printf("Enter the fourth string: ");
    scanf("%s", str4);

    printf("Enter the fifth string: ");
    scanf("%s", str5);

    for (i = 0; str1[i] != '\0'; i++)
    {
        for (j = 0; str2[j] != '\0'; j++)
        {
            for (k = 0; str3[k] != '\0'; k++)
            {
                for (l = 0; str4[l] != '\0'; l++)
                {
                    for (m = 0; str5[m] != '\0'; m++)
                    {
                        if (str1[i] == str2[j] && str2[j] == str3[k] && str3[k] == str4[l] && str4[l] == str5[m])
                        {
                            flag = 1;
                        }
                    }
                }
            }
        }
    }

    if (flag == 1)
    {
        printf("The strings are similar.\n");
    }
    else
    {
        printf("The strings are not similar.\n");
    }

    return 0;
}