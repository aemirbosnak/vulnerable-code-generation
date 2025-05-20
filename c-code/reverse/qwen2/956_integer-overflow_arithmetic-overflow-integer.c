#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void move(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    move(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    move(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Intentionally causing integer overflow for demonstration purposes
    int *disks = (int *)malloc((n * n) * sizeof(int));
    if (disks == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    free(disks); // Freeing the allocated memory

    move(n, 'A', 'C', 'B'); // A, B and C are names of rods

    return 0;
}
