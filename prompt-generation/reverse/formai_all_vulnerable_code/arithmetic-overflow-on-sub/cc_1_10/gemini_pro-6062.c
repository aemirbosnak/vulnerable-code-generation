//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define CYAN "\x1b[36m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define RESET "\x1b[0m"

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("%sMove disk 1 from %c to %c%s\n", GREEN, from_rod, to_rod, RESET);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("%sMove disk %d from %c to %c%s\n", RED, n, from_rod, to_rod, RESET);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n, i, j;
    char rods[3] = {'A', 'B', 'C'};
    char from_rod, to_rod, aux_rod;

    printf("%sEnter the number of disks: %s", CYAN, RESET);
    scanf("%d", &n);

    printf("%sInitial state:\n", BLUE);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            if (j == 0) {
                printf("%s%c |%s", MAGENTA, rods[j], RESET);
            } else {
                printf("%s%c |%s", YELLOW, rods[j], RESET);
            }
        }
        printf("\n");
    }

    printf("\n%sEnter the from rod: %s", CYAN, RESET);
    scanf(" %c", &from_rod);
    printf("%sEnter the to rod: %s", CYAN, RESET);
    scanf(" %c", &to_rod);
    printf("%sEnter the auxiliary rod: %s", CYAN, RESET);
    scanf(" %c", &aux_rod);

    tower_of_hanoi(n, from_rod, to_rod, aux_rod);

    return 0;
}