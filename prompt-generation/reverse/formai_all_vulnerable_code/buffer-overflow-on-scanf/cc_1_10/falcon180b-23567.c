//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

void generate_random_sequence(Sequence *sequence, int length) {
    srand(time(NULL));
    sequence->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence->length = length;
    sequence->sequence[length] = '\0';
}

void print_sequence(Sequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
    printf("Length: %d\n", sequence->length);
}

int main() {
    Sequence sequence1, sequence2;
    int length1, length2;

    printf("Enter the length of the first sequence: ");
    scanf("%d", &length1);
    generate_random_sequence(&sequence1, length1);
    print_sequence(&sequence1);

    printf("Enter the length of the second sequence: ");
    scanf("%d", &length2);
    generate_random_sequence(&sequence2, length2);
    print_sequence(&sequence2);

    int overlap_length = 0;
    int match_count = 0;

    for (int i = 0; i < length1 && i < length2; i++) {
        if (sequence1.sequence[i] == sequence2.sequence[i]) {
            overlap_length++;
            match_count++;
        } else {
            break;
        }
    }

    printf("Overlap length: %d\n", overlap_length);
    printf("Match count: %d\n", match_count);

    return 0;
}