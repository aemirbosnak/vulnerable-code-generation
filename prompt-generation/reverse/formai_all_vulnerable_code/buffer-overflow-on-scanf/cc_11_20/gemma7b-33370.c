//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, phone_num, count = 0;
    char name[20];

    printf("Enter the number of entries: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the name: ");
        scanf("%s", name);

        printf("Enter the phone number: ");
        scanf("%d", &phone_num);

        count++;
        k = phone_num;
        j = 0;
        while (k)
        {
            int digit = k % 10;
            k /= 10;
            j++;
            switch (digit)
            {
                case 0:
                    printf("(%c) ", '0' + j - 1);
                    break;
                case 1:
                    printf("(%c) ", '0' + j - 1);
                    break;
                case 2:
                    printf("(%c) ", '0' + j - 1);
                    break;
                case 3:
                    printf("(%c) ", '0' + j - 1);
                    break;
                case 4:
                    printf("(%c) ", '0' + j - 1);
                    break;
                case 5:
                    printf("(%c) ", '0' + j - 1);
                    break;
                case 6:
                    printf("(%c) ", '0' + j - 1);
                    break;
                case 7:
                    printf("(%c) ", '0' + j - 1);
                    break;
                case 8:
                    printf("(%c) ", '0' + j - 1);
                    break;
                case 9:
                    printf("(%c) ", '0' + j - 1);
                    break;
            }
        }

        printf("\n");
    }

    printf("Total number of entries: %d\n", count);

    return 0;
}