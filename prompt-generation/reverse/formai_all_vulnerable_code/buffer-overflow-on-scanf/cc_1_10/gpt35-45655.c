//FormAI DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j, n, m, k, total, recovered = 0;
    int *data, *backup;

    printf("Enter the total number of data points: ");
    scanf("%d", &n);

    data = (int*)malloc(n * sizeof(int));
    backup = (int*)malloc(n * sizeof(int));

    for(i=0; i<n; i++)
    {
        printf("Enter the data point #%d: ", i+1);
        scanf("%d", &data[i]);
    }

    // Creating Backup
    for(i=0; i<n; i++)
        backup[i] = data[i];

    // Simulating Data Loss
    printf("Enter the percentage of data lost: ");
    scanf("%d", &m);

    k = n*m/100;
    total = n;

    for(i=0; i<k; i++)
    {
        j = rand()%total;
        data[j] = 0;
        total--;
    }

    // Recovering Data
    for(i=0; i<n; i++)
    {
        if(data[i] == 0)
        {
            data[i] = backup[i];
            recovered++;
        }
    }

    printf("Total Data Points: %d\nData Points Lost: %d\nData Points Recovered: %d\nRecovered Data:\n", n, k, recovered);

    for(i=0; i<n; i++)
        printf("%d ", data[i]);

    return 0;
}