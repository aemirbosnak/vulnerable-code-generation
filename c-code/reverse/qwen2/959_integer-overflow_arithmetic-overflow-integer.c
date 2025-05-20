#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void move(char from_rod, char to_rod, int n) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    move(from_rod, 'C', n - 1);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    move('C', to_rod, n - 1);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    move('A', 'B', n);
    return 0;
}
