//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int data[MAX_SIZE];
    int i, n, clusters, new_cluster, min_val, max_val;
    srand(time(NULL));

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter %d data points:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    clusters = n;
    new_cluster = 1;

    min_val = data[0];
    max_val = data[0];

    printf("Clustering...\n");
    while (clusters > 1) {
        min_val = data[0];
        max_val = data[0];

        for (i = 0; i < n; i++) {
            if (data[i] < min_val)
                min_val = data[i];
            else if (data[i] > max_val)
                max_val = data[i];
        }

        if (min_val!= max_val) {
            new_cluster = 1;
            clusters--;
        } else {
            new_cluster = 0;
        }

        printf("%d %d\n", min_val, max_val);
    }

    printf("Data points grouped into %d clusters:\n", clusters);
    for (i = 0; i < n; i++) {
        if (i % clusters == 0)
            printf("\n");
        printf("%d ", data[i]);
    }

    return 0;
}