#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, m, cache_size = 10, item_count = 0, item_size = 10;
    int *cache = NULL;

    cache = (int *)malloc(cache_size * item_size);

    printf("Enter the number of items to be inserted: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the item name: ");
        scanf("%d", &m);

        cache[item_count] = m;
        item_count++;
    }

    printf("Items inserted: %d\n", item_count);

    printf("Evict items until cache size is %d: ", cache_size);
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        cache[item_count - 1] = -1;
        item_count--;
    }

    printf("Items remaining: %d\n", item_count);

    return 0;
}
