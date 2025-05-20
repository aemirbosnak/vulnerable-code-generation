#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10;
    int i;
    char *a = malloc(n);
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    a[3] = 40;
    a[4] = 50;

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    free(a);
    return 0;
}
