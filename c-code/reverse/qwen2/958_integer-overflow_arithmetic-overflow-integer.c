#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void move(int n, int *from, int *to, int *aux) {
    if (n == 1) {
        printf("Move disk 1 from tower %d to tower %d\n", from[0], to[0]);
        return;
    }
    move(n - 1, from, aux, to);
    printf("Move disk %d from tower %d to tower %d\n", n, from[0], to[0]);
    move(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    int *towers[3];
    for (int i = 0; i < 3; i++) {
        towers[i] = malloc(n * sizeof(int));
        if (towers[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        towers[0][i] = i + 1;
    }

    move(n, towers[0], towers[2], towers[1]);

    for (int i = 0; i < 3; i++) {
        free(towers[i]);
    }

    return 0;
}
