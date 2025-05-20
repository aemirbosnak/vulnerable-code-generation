//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Function to print the tower
void print_tower(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%c\n", to);
        } else {
            printf("%c ", from);
        }
    }
}

// Function to move the disk from from_rod to to_rod using aux_rod
void move_disk(int n, char from_rod, char to_rod, char aux_rod) {
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    print_tower(n, from_rod, to_rod, aux_rod);
}

// Function to check if the move is valid
int is_valid_move(int n, char from_rod, char to_rod, char aux_rod) {
    if (from_rod == to_rod || to_rod == aux_rod) {
        return 0;
    } else if (from_rod == aux_rod) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the game is won
int is_game_won(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        move_disk(1, from_rod, to_rod, aux_rod);
        return 1;
    } else {
        return 0;
    }
}

// Function to play the game
void play_game(int n, char from_rod, char to_rod, char aux_rod) {
    int i;
    for (i = n; i >= 1; i--) {
        move_disk(i, from_rod, to_rod, aux_rod);
        if (is_game_won(i, from_rod, to_rod, aux_rod)) {
            printf("Congratulations! You won the game.\n");
            break;
        }
    }
}

int main() {
    int n, from_rod, to_rod, aux_rod, i;
    char choice;
    srand(time(NULL));
    n = rand() % MAX + 3;
    printf("Welcome to the Tower of Hanoi game!\n");
    printf("How many disks do you want to play with? ");
    scanf("%d", &n);
    printf("Enter the starting rod (A/B/C): ");
    scanf(" %c", &from_rod);
    printf("Enter the ending rod (A/B/C): ");
    scanf(" %c", &to_rod);
    printf("Enter the auxiliary rod (A/B/C): ");
    scanf(" %c", &aux_rod);
    play_game(n, from_rod, to_rod, aux_rod);
    return 0;
}