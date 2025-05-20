//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct {
    int *arr;
    int n;
    int m;
} bucket;

static bucket *bucket_new(int n, int m)
{
    bucket *b = malloc(sizeof(bucket));
    b->arr = malloc(n * sizeof(int));
    b->n = n;
    b->m = m;
    return b;
}

static void bucket_free(bucket *b)
{
    free(b->arr);
    free(b);
}

static void bucket_sort(bucket *b)
{
    int i, j, k, l;
    int *counts = malloc(b->m * sizeof(int));
    int *idx = malloc(b->n * sizeof(int));

    for (i = 0; i < b->m; i++)
        counts[i] = 0;

    for (i = 0; i < b->n; i++)
        counts[b->arr[i]]++;

    for (i = 1; i < b->m; i++)
        counts[i] += counts[i - 1];

    for (i = b->n - 1; i >= 0; i--) {
        l = b->arr[i];
        j = counts[l] - 1;

        while (j >= 0 && b->arr[idx[j]] == l)
            j--;

        idx[j + 1] = i;
        counts[l]--;
    }

    for (i = 0; i < b->n; i++)
        b->arr[i] = b->arr[idx[i]];

    free(counts);
    free(idx);
}

int main(void)
{
    int i, n, m;
    bucket *b;

    scanf("%d %d", &n, &m);
    b = bucket_new(n, m);

    for (i = 0; i < n; i++)
        scanf("%d", &b->arr[i]);

    bucket_sort(b);

    for (i = 0; i < n; i++)
        printf("%d ", b->arr[i]);

    printf("\n");

    bucket_free(b);

    return 0;
}