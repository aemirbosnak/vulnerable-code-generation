//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, q;
    int items[100], shelves[100], w[100], x[100], qty[100];
    char cust[100];

    printf("Enter the number of shelves: ");
    scanf("%d", &n);

    printf("Enter the weight of items:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    printf("Enter the number of items:\n");
    scanf("%d", &n);

    printf("Enter the capacity of each shelf:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &shelves[i]);
    }

    printf("Enter the quantity of each item:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &qty[i]);
    }

    printf("Enter the items:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &items[i]);
    }

    printf("Enter the customer orders:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", &cust[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("Shelf %d has %d kg of item %d with a quantity of %d.\n", i + 1, w[i], items[i], qty[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("Customer %s wants item %d.\n", cust[i], items[i]);
    }

    printf("Enter the item number to be removed: ");
    scanf("%d", &q);

    if (q > n)
    {
        printf("Invalid item number.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        if (items[i] == q)
        {
            x[i] = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (x[i] == 1)
        {
            for (j = i; j < n; j++)
            {
                if (x[j] == 0)
                {
                    for (k = j + 1; k < n; k++)
                    {
                        if (x[k] == 0)
                        {
                            if (w[j] + w[k] <= shelves[i])
                            {
                                x[j] = 1;
                                x[k] = 1;
                                w[j] += w[k];
                                w[k] = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Removing item %d.\n", q);

    for (i = 0; i < n; i++)
    {
        printf("Shelf %d has %d kg of item %d with a quantity of %d.\n", i + 1, w[i], items[i], qty[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("Customer %s wants item %d.\n", cust[i], items[i]);
    }

    printf("Enter the item number to be removed: ");
    scanf("%d", &q);

    if (q > n)
    {
        printf("Invalid item number.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        if (items[i] == q)
        {
            x[i] = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (x[i] == 1)
        {
            for (j = i; j < n; j++)
            {
                if (x[j] == 0)
                {
                    for (k = j + 1; k < n; k++)
                    {
                        if (x[k] == 0)
                        {
                            if (w[j] + w[k] <= shelves[i])
                            {
                                x[j] = 1;
                                x[k] = 1;
                                w[j] += w[k];
                                w[k] = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Removing item %d.\n", q);

    for (i = 0; i < n; i++)
    {
        printf("Shelf %d has %d kg of item %d with a quantity of %d.\n", i + 1, w[i], items[i], qty[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("Customer %s wants item %d.\n", cust[i], items[i]);
    }

    return 0;
}