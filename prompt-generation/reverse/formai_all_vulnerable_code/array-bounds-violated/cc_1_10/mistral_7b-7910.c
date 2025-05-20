//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ORDER 3
#define ALPHABET_SIZE 26
#define MAX_TEXT_SIZE 1000

typedef struct TransitionMatrix {
    int transitions[ALPHABET_SIZE][ALPHABET_SIZE];
    int total_transitions;
} TransitionMatrix;

TransitionMatrix build_transition_matrix(char *text, int text_size) {
    TransitionMatrix transition_matrix;
    memset(&transition_matrix, 0, sizeof(TransitionMatrix));

    for (int i = 0; i < text_size - MAX_ORDER; i++) {
        int current_char = text[i] - 'a';
        int next_char = text[i + MAX_ORDER] - 'a';

        transition_matrix.transitions[current_char][next_char]++;
        transition_matrix.total_transitions++;
    }

    return transition_matrix;
}

void generate_random_text(TransitionMatrix transition_matrix, int text_length) {
    int current_char = rand() % ALPHABET_SIZE;

    printf("Text: ");
    for (int i = 0; i < text_length; i++) {
        printf("%c", 'a' + current_char);

        int next_char;
        if (i < text_length - 1) {
            next_char = rand() % ALPHABET_SIZE;
            while (transition_matrix.transitions[current_char][next_char] == 0) {
                next_char = rand() % ALPHABET_SIZE;
            }
            current_char = next_char;
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char text[MAX_TEXT_SIZE];
    fgets(text, sizeof(text), file);
    int text_size = strlen(text) - 1;

    TransitionMatrix transition_matrix = build_transition_matrix(text, text_size);

    int text_length = rand() % (MAX_TEXT_SIZE / 2) + MAX_ORDER;
    generate_random_text(transition_matrix, text_length);

    fclose(file);

    return 0;
}