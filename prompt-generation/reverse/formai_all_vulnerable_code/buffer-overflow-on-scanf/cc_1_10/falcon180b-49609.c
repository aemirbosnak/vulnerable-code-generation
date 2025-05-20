//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define MAX_VARIABLES 100

int main(int argc, char *argv[]) {
    // Initialize variables
    int size = 0;
    int variables[MAX_VARIABLES] = {0};
    int values[MAX_VARIABLES] = {0};
    char *names[MAX_VARIABLES] = {0};
    char *search_term = NULL;

    // Prompt user for number of variables
    printf("Enter the number of variables: ");
    scanf("%d", &size);

    // Prompt user for variable names and values
    for (int i = 0; i < size; i++) {
        printf("Enter variable name %d: ", i+1);
        scanf("%s", names[i]);
        printf("Enter variable value %d: ", i+1);
        scanf("%d", &values[i]);
    }

    // Prompt user for search term
    printf("Enter search term: ");
    scanf("%s", search_term);

    // Perform search
    int results_size = 0;
    int results[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        if (strcmp(search_term, names[i]) == 0) {
            results[results_size++] = values[i];
        }
    }

    // Output results
    if (results_size == 0) {
        printf("No results found.\n");
    } else {
        printf("Results:\n");
        for (int i = 0; i < results_size; i++) {
            printf("%d\n", results[i]);
        }
    }

    return 0;
}