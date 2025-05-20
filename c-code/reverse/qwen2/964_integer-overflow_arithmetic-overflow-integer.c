#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int bags[5];
    int n;

    printf("Enter the number of bags: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) { // Vulnerability here
        bags[i] = i * 2;
    }

    return 0;
}
