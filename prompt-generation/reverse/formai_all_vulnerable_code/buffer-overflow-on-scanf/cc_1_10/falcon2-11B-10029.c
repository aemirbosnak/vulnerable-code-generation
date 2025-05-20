//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void memoryGame(int memory[], int size);
void displayMemory(int memory[], int size);
void generateRandomArray(int memory[], int size);
int checkWinner(int memory[], int size);
int main() {
    int memory[10];
    int size;

    printf("Welcome to the memory game!\n");
    printf("Enter the size of the memory array: ");
    scanf("%d", &size);

    memoryGame(memory, size);

    printf("Game over!\n");
    if (checkWinner(memory, size)) {
        printf("Congratulations! You won the game!\n");
    }

    return 0;
}

void memoryGame(int memory[], int size) {
    srand(time(NULL));
    generateRandomArray(memory, size);

    int index = 0;
    while (index < size) {
        displayMemory(memory, size);
        printf("Enter your guess: ");
        scanf("%d", &index);
        index++;
    }
}

void generateRandomArray(int memory[], int size) {
    for (int i = 0; i < size; i++) {
        memory[i] = rand() % 10;
    }
}

void displayMemory(int memory[], int size) {
    printf("Memory:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", memory[i]);
    }
    printf("\n");
}

int checkWinner(int memory[], int size) {
    for (int i = 0; i < size; i++) {
        if (memory[i]!= i + 1) {
            return 0;
        }
    }
    return 1;
}