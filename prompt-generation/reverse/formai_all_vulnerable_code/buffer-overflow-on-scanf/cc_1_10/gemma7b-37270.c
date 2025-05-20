//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, l, o, p, q, r, t, u, v, w, x, y, z;
    n = 12;
    m = 20;
    i = 10;
    j = 22;
    k = 30;
    l = 42;
    o = 54;
    p = 66;
    q = 78;
    r = 90;
    t = 102;
    u = 114;
    v = 126;
    w = 138;
    x = 150;
    y = 162;
    z = 174;

    printf("The surreal expense tracker is ready!\n");
    printf("Please enter the category of your expense:\n");
    scanf("%d", &k);

    switch (k)
    {
        case 1:
            printf("Enter the amount of the expense:");
            scanf("%d", &l);
            printf("The expense of category 1 is: $%d\n", l);
            break;
        case 2:
            printf("Enter the amount of the expense:");
            scanf("%d", &m);
            printf("The expense of category 2 is: $%d\n", m);
            break;
        case 3:
            printf("Enter the amount of the expense:");
            scanf("%d", &n);
            printf("The expense of category 3 is: $%d\n", n);
            break;
        default:
            printf("Invalid category number.\n");
    }

    return 0;
}