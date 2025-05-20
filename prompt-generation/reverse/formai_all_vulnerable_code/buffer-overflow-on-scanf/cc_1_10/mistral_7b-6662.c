//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER 20

typedef struct Fact_t {
    int num;
    struct Fact_t *next;
} Fact_t;

Fact_t *fact(int n);
void free_fact_list(Fact_t *list);

int main() {
    int number;
    Fact_t *fact_list;

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &number);

    if (number < 0 || number > MAX_NUMBER) {
        printf("Invalid number! Please enter a number between 0 and %d.\n", MAX_NUMBER);
        return 1;
    }

    fact_list = fact(number);

    printf("The factorial of %d is:\n", number);
    while (fact_list != NULL) {
        printf("%d ", fact_list->num);
        fact_list = fact_list->next;
    }
    printf("\n");

    free_fact_list(fact_list);

    return 0;
}

Fact_t *fact(int n) {
    Fact_t *new_node, *current = NULL, *previous = NULL;
    int i;

    new_node = (Fact_t *) malloc(sizeof(Fact_t));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_node->num = n;
    new_node->next = NULL;

    if (previous == NULL) {
        current = new_node;
    } else {
        current = previous;
        previous->next = new_node;
    }

    previous = new_node;

    for (i = n - 1; i > 0; i--) {
        new_node = (Fact_t *) malloc(sizeof(Fact_t));
        if (new_node == NULL) {
            printf("Memory allocation failed!\n");
            free_fact_list(current);
            exit(EXIT_FAILURE);
        }

        new_node->num = i;
        new_node->next = NULL;

        previous->next = new_node;
        previous = new_node;
    }

    return current;
}

void free_fact_list(Fact_t *list) {
    Fact_t *current = list;
    Fact_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}