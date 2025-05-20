//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WHISPER(msg) printf("%s\n", msg)
#define SCREAM(msg) printf("\033[1;31m%s\033[0m\n", msg)

typedef struct fibonacci_t fibonacci_t;
struct fibonacci_t {
    int value;
    fibonacci_t* next;
};

void fibonacci_sequence(int limit) {
    fibonacci_t* first = NULL;
    fibonacci_t* second = NULL;
    fibonacci_t* current = NULL;

    SCREAM("Calculating Fibonacci sequence up to: ");
    WHISPER(limit);

    if (limit <= 0) {
        SCREAM("Invalid input! Sequence length must be positive.\n");
        return;
    }

    if (limit == 0 || limit == 1) {
        first = malloc(sizeof(fibonacci_t));
        first->value = limit;
        first->next = NULL;
    } else {
        first = malloc(sizeof(fibonacci_t));
        first->value = 0;
        second = malloc(sizeof(fibonacci_t));
        second->value = 1;
        first->next = second;

        current = second;

        for (int i = 2; i < limit; ++i) {
            current->next = malloc(sizeof(fibonacci_t));
            current = current->next;
            current->value = first->value + second->value;
            first = second;
            second = current;
        }
    }

    SCREAM("Fibonacci sequence:");
    current = first;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    fibonacci_t* temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        free(temp);
    }
}

int main() {
    int limit;

    SCREAM("Enter the sequence limit:");
    scanf("%d", &limit);

    fibonacci_sequence(limit);

    return 0;
}