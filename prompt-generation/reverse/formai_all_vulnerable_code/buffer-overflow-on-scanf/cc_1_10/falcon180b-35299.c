//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

/* Function prototypes */
void move_disk(int n, char from, char to, char aux);
void print_disks(int n, char tower[]);

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    char tower[MAX_DISKS];
    for(int i = n; i >= 1; i--) {
        tower[n - i] = 'A' + i;
    }

    printf("Initial configuration:\n");
    print_disks(n, tower);

    move_disk(n, 'A', 'C', 'B');

    printf("\nFinal configuration:\n");
    print_disks(n, tower);

    return 0;
}

/* Recursive function to move n disks from from_rod to to_rod
   using aux_rod as auxiliary */
void move_disk(int n, char from, char to, char aux) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    move_disk(n - 1, from, aux, to);

    printf("Move disk %d from %c to %c\n", n, from, to);

    move_disk(n - 1, aux, to, from);
}

/* Function to print the current configuration of the towers */
void print_disks(int n, char tower[]) {
    printf("Tower A: ");
    for(int i = 0; i < n; i++) {
        printf("%c ", tower[i]);
    }
    printf("\n");

    printf("Tower B: ");
    for(int i = 0; i < n; i++) {
        if(tower[i]!= 'A') {
            printf("%c ", tower[i]);
        }
    }
    printf("\n");

    printf("Tower C: ");
    for(int i = 0; i < n; i++) {
        if(tower[i]!= 'A' && tower[i]!= 'B') {
            printf("%c ", tower[i]);
        }
    }
    printf("\n");
}