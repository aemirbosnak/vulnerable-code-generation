//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void move_disk(int n, char from, char to) {
    printf("%sMove disk %d from %c to %c%s\n", YELLOW, n, from, to, RESET);
}

void hanoi(int height, char from, char to, char aux) {
    if (height == 1) {
        move_disk(1, from, to);
        return;
    }
    hanoi(height - 1, from, aux, to);
    move_disk(height, from, to);
    hanoi(height - 1, aux, to, from);
}

int main() {
    printf("%sWelcome to the Post-Apocalyptic Tower of Hanoi!%s\n", RED, RESET);
    int height;
    printf("Enter the height of the tower (1-%d): ", 9);
    scanf("%d", &height);
    if (height < 1 || height > 9) {
        printf("%sError: Invalid height!%s\n", RED, RESET);
        return EXIT_FAILURE;
    }
    printf("\n%sInitial state%s:\n", CYAN, RESET);
    printf("   A   B   C\n");
    printf(" |%d| | | |\n", height);
    printf(" | | | | |\n");
    printf(" | | | | |\n");
    printf("---|---|---\n");
    hanoi(height, 'A', 'C', 'B');
    printf("\n%sFinal state%s:\n", GREEN, RESET);
    printf("   A   B   C\n");
    printf(" | | |%d|\n", height);
    printf(" | | | | |\n");
    printf(" | | | | |\n");
    printf("---|---|---\n");
    printf("%sCongratulations, you have solved the Tower of Hanoi!%s\n", MAGENTA, RESET);
    return EXIT_SUCCESS;
}