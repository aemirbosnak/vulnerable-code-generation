//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10
#define SEQ_SIZE 10

typedef struct {
    int num;
    int shown;
} Sequence;

void initialize_sequence(Sequence *seq, int size) {
    int i;
    for (i = 0; i < size; i++) {
        seq[i].num = rand() % (MAX_NUM + 1);
        seq[i].shown = 0;
    }
}

void print_sequence(Sequence *seq, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (seq[i].shown) {
            printf("%3d ", seq[i].num);
        } else {
            printf(".   ");
        }
    }
    printf("\n");
}

void reveal_sequence(Sequence *seq, int size) {
    int i;
    for (i = 0; i < size; i++) {
        seq[i].shown = 1;
    }
}

int check_sequence(Sequence *seq, int size, int *guess) {
    int i, result = 1;
    for (i = 0; i < size; i++) {
        if (seq[i].num != *guess) {
            result = 0;
            break;
        }
        guess++;
    }
    return result;
}

int main() {
    Sequence seq[SEQ_SIZE];
    int guess, i, j, num_correct = 0;

    srand(time(NULL));
    initialize_sequence(seq, SEQ_SIZE);

    printf("Sequence: ");
    print_sequence(seq, SEQ_SIZE);

    for (i = 0; i < SEQ_SIZE; i++) {
        printf("\nEnter guess %d: ", i + 1);
        scanf("%d", &guess);

        if (check_sequence(seq, SEQ_SIZE, &guess)) {
            num_correct++;
            printf("Correct!\n");
        } else {
            printf("Incorrect! Try again.\n");
        }

        if (i < SEQ_SIZE - 1) {
            printf("Sequence: ");
            print_sequence(seq, SEQ_SIZE);
        }
    }

    printf("\nYou got %d numbers correct out of %d.", num_correct, SEQ_SIZE);

    return 0;
}