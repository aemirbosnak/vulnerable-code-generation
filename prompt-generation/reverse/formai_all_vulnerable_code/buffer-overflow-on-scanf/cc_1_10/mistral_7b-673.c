//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct fact_t {
    int num;
    struct fact_t *next;
} fact_t;

void factorial(int n, fact_t **result) {
    fact_t *new_node = NULL;

    if (n < 0) {
        printf("Error: Negative number is not supported!\n");
        exit(EXIT_FAILURE);
    }

    if (n == 0) {
        *result = malloc(sizeof(fact_t));
        (*result)->num = 1;
        (*result)->next = NULL;
        return;
    }

    factorial(n - 1, &new_node);
    new_node = (fact_t *) malloc(sizeof(fact_t));

    new_node->num = n;
    new_node->next = *result;
    *result = new_node;
}

void print_fact(fact_t *node) {
    if (node == NULL) {
        return;
    }

    printf("%d x ", node->num);
    print_fact(node->next);
}

int main() {
    fact_t *fact_list = NULL;
    int num;

    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &num);

    factorial(num, &fact_list);
    printf("\nThe factorial of %d is: ", num);

    print_fact(fact_list);
    printf("\n1\n");

    while (fact_list != NULL) {
        fact_t *temp = fact_list;
        fact_list = fact_list->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}