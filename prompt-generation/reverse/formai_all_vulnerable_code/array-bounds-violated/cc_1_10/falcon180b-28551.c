//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, n, m, l, c, d, s = 0, count = 0, flag = 0;
    int sum = 0;
    float avg;
    char ch;
    char str[100];
    char word[50];
    char *token;
    struct tm *tm;
    time_t now;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of strings: ");
    scanf("%d", &m);

    char *strings[m];

    printf("Enter %d strings:\n", m);
    for(i=0; i<m; i++)
    {
        scanf("%s", strings[i]);
    }

    printf("Enter the delimiter: ");
    scanf(" %c", &ch);

    token = strtok(strings[0], &ch);

    while(token!= NULL)
    {
        if(flag == 0)
        {
            s = atoi(token);
            flag = 1;
        }
        else
        {
            sum += atoi(token);
        }
        token = strtok(NULL, &ch);
    }

    avg = (float)sum/s;

    printf("Average: %.2f\n", avg);

    return 0;
}