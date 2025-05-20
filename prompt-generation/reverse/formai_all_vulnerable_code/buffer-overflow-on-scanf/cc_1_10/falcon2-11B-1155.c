//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_SIZE 10

void generate_sequence(int* sequence, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        sequence[i] = rand() % 100;
    }
}

int check_sequence(int* sequence, int size) {
    int correct = 1;
    for (int i = 0; i < size; i++) {
        if (sequence[i]!= i + 1) {
            correct = 0;
            break;
        }
    }
    return correct;
}

int main() {
    int sequence[MAX_SEQUENCE_SIZE];
    int size = MAX_SEQUENCE_SIZE;
    int correct = 1;

    generate_sequence(sequence, size);
    printf("The sequence is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    int answer;
    printf("Please enter the sequence in the correct order: ");
    scanf("%d", &answer);

    while (correct && (answer < 1 || answer > size)) {
        printf("Invalid input. Please try again: ");
        scanf("%d", &answer);
    }

    if (answer == 0) {
        printf("Congratulations! You've won the game.\n");
    } else {
        printf("Sorry, you've lost the game.\n");
    }

    return 0;
}