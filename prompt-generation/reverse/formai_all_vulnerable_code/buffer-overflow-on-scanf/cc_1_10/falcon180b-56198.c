//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void display_towers(int n, char from, char to, char aux, int *towers) {
    int i;
    printf("\n");
    for (i = 0; i <= n; i++) {
        if (i == n || towers[i] == -1) {
            printf("    ");
        } else {
            printf("   %c ", towers[i] + 'A');
        }
    }
    printf("\n");
    printf("\n");
}

void move_disk(int n, char from, char to, char aux, int *towers) {
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c\n", from, to);
        towers[to] = towers[from];
        towers[from] = -1;
        display_towers(n, from, to, aux, towers);
        printf("\n");
        return;
    }
    char temp = aux;
    aux = from;
    from = to;
    to = temp;
    move_disk(n - 1, from, aux, to, towers);
    towers[to] = towers[from];
    towers[from] = -1;
    display_towers(n, from, to, aux, towers);
    printf("\n");
}

int main() {
    int n;
    printf("\nEnter the number of disks: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_DISKS) {
        printf("\nInvalid number of disks\n");
        return 1;
    }
    int towers[MAX_DISKS];
    for (int i = 0; i <= n; i++) {
        towers[i] = -1;
    }
    towers[0] = 0;
    srand(time(NULL));
    int from_rod = rand() % 3;
    int to_rod = rand() % 3;
    while (from_rod == to_rod) {
        to_rod = rand() % 3;
    }
    char from = 'A' + from_rod;
    char to = 'A' + to_rod;
    char aux = 'A' + (3 - from_rod - to_rod);
    move_disk(n, from, to, aux, towers);
    printf("\n\n");
    return 0;
}