//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, l, n, m;
    float a, b, c, d, e, f;
    char str[100], str1[100], str2[100];

    printf("Enter the number of lines you want to analyze:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the line:");
        scanf("%s", str);

        for (j = 0; str[j] != '\0'; j++)
        {
            switch (str[j])
            {
                case 'a':
                    a++;
                    break;
                case 'b':
                    b++;
                    break;
                case 'c':
                    c++;
                    break;
                case 'd':
                    d++;
                    break;
                case 'e':
                    e++;
                    break;
                case 'f':
                    f++;
                    break;
                default:
                    break;
            }
        }

        printf("The number of occurrences of each letter in the line are:\n");
        printf("a: %d\n", a);
        printf("b: %d\n", b);
        printf("c: %d\n", c);
        printf("d: %d\n", d);
        printf("e: %d\n", e);
        printf("f: %d\n", f);

        a = b = c = d = e = f = 0;
    }

    printf("The average number of occurrences of each letter in the file is:\n");
    printf("a: %.2f\n", (a / n));
    printf("b: %.2f\n", (b / n));
    printf("c: %.2f\n", (c / n));
    printf("d: %.2f\n", (d / n));
    printf("e: %.2f\n", (e / n));
    printf("f: %.2f\n", (f / n));

    return 0;
}