//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name;
    int pos;
} Rod;

Rod rods[3] = {{'A', 1}, {'B', 2}, {'C', 0}};

void print_rods() {
    int i;
    for (i = 0; i < 3; i++)
        printf("%c: %d\n", rods[i].name, rods[i].pos);
}

void move_disk(int from, int to) {
    rods[from].pos -= 1;
    rods[to].pos += 1;
    rods[to].name = rods[from].name;
    rods[from].name = ' ';
}

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        move_disk(from, to);
        print_rods();
    } else {
        hanoi(n - 1, from, aux, to);
        hanoi(1, from, to, aux);
        hanoi(n - 1, aux, to, from);
        print_rods();
    }
}

int main() {
    int n;
    char from, to, aux;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("Enter starting rod: ");
    scanf(" %c", &from);
    from = toupper(from);

    printf("Enter destination rod: ");
    scanf(" %c", &to);
    to = toupper(to);

    printf("Enter auxiliary rod: ");
    scanf(" %c", &aux);
    aux = toupper(aux);

    if (from < 'A' || from > 'C' || to < 'A' || to > 'C' || aux < 'A' || aux > 'C' || from == to || from == aux || to == aux) {
        printf("Invalid input!\n");
        return 1;
    }

    hanoi(n, from, to, aux);

    return 0;
}