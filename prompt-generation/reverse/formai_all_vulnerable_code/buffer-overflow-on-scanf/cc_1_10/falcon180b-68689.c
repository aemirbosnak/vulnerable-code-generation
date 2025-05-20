//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int x;
    int y;
} point;

void init(int *a, int n) {
    int i;
    for(i = 0; i < n; i++)
        a[i] = rand() % 100 + 1;
}

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

void euclid(int a, int b, int *x, int *y) {
    int g = gcd(a, b);
    *x = (a / g) % b;
    *y = (b / g) % a;
}

int main() {
    int a[MAX], b[MAX];
    int x, y, i, j, n;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    init(a, n);
    init(b, n);

    for(i = 0; i < n; i++) {
        printf("Enter the value of a%d: ", i + 1);
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++) {
        printf("Enter the value of b%d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nThe GCD of the given numbers is: ");
    euclid(a[0], b[0], &x, &y);
    printf("%d = %d * %d + %d\n", a[0], x, y, a[0]);

    return 0;
}