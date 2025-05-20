//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

void generate_random_sequence(Sequence *sequence, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence->length = length;
}

int main() {
    Sequence sequence1, sequence2;
    int alignment_score, gap_penalty;

    printf("Enter the length of the sequences: ");
    scanf("%d", &sequence1.length);
    generate_random_sequence(&sequence1, sequence1.length);
    printf("Sequence 1: %s\n", sequence1.sequence);

    printf("Enter the length of the sequences: ");
    scanf("%d", &sequence2.length);
    generate_random_sequence(&sequence2, sequence2.length);
    printf("Sequence 2: %s\n", sequence2.sequence);

    printf("Enter the gap penalty: ");
    scanf("%d", &gap_penalty);

    alignment_score = 0;
    int i = 0, j = 0;
    while (i < sequence1.length || j < sequence2.length) {
        if (sequence1.sequence[i] == sequence2.sequence[j]) {
            alignment_score++;
            i++;
            j++;
        } else if (sequence1.sequence[i]!= sequence2.sequence[j]) {
            if (alignment_score > 0) {
                alignment_score--;
            } else {
                printf("-");
                i++;
            }
            j++;
        }
    }

    printf("\nAlignment score: %d\n", alignment_score);

    return 0;
}