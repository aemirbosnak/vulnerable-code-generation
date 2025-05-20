//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

int main() {
    int size, i, j, k;
    char *array[MAX_SIZE];
    char search_term[MAX_SIZE];

    // Read the input file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Count the number of lines in the input file
    size = 0;
    char c;
    while ((c = fgetc(input_file))!= EOF) {
        if (c == '\n') {
            size++;
        }
    }
    rewind(input_file);

    // Read the input file into an array
    for (i = 0; i < size; i++) {
        array[i] = (char *) malloc(MAX_SIZE);
        fgets(array[i], MAX_SIZE, input_file);
    }
    fclose(input_file);

    // Prompt the user for a search term
    printf("Enter a search term: ");
    scanf("%s", search_term);

    // Perform the search
    int found = 0;
    for (i = 0; i < size; i++) {
        if (strstr(array[i], search_term)!= NULL) {
            printf("Line %d contains the search term\n", i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("The search term was not found\n");
    }

    // Clean up
    for (i = 0; i < size; i++) {
        free(array[i]);
    }
    return 0;
}