//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>

int main() {
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100];
    printf("Welcome to the Magical Number Game!\n");
    printf("Please enter the number of players: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", a[i]);
    }

    for (i = 0; i < n; i++) {
        printf("Enter the initial score of player %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n; i++) {
        c[i] = b[i] * 2;
    }

    for (i = 0; i < n; i++) {
        d[i] = c[i] - 10;
    }

    for (i = 0; i < n; i++) {
        e[i] = d[i] + 5;
    }

    for (i = 0; i < n; i++) {
        f[i] = e[i] * 3;
    }

    for (i = 0; i < n; i++) {
        g[i] = f[i] - 20;
    }

    for (i = 0; i < n; i++) {
        h[i] = g[i] + 15;
    }

    printf("The final scores are: ");

    for (i = 0; i < n; i++) {
        printf("%s: %d\n", a[i], h[i]);
    }

    return 0;
}