//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j, k, l, n, m, flag = 0;
    char a[1000], b[1000], c[1000], d[1000], e[1000];

    printf("Enter the number of secret messages: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the secret message: ");
        scanf("%s", a);

        printf("Enter the image file name: ");
        scanf("%s", b);

        k = 0;
        l = 0;
        m = 0;

        FILE *fp = fopen(b, "r");
        FILE *fp2 = fopen("output.jpg", "w");

        while (!feof(fp))
        {
            fscanf(fp, "%c", &c[k]);
            k++;
        }

        fclose(fp);

        for (j = 0; j < strlen(a); j++)
        {
            if (c[l] != a[j])
            {
                c[l] = a[j];
                m++;
            }
            l++;
        }

        fprintf(fp2, "%c", c);

        fclose(fp2);

        printf("Number of changes: %d\n", m);

        if (m > flag)
        {
            flag = m;
        }
    }

    printf("The maximum number of changes is: %d\n", flag);
}