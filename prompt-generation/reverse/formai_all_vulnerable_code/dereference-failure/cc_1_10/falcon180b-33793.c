//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    char *input_string = (char *) malloc(MAX_SIZE * sizeof(char));
    char *output_string = (char *) malloc(MAX_SIZE * sizeof(char));
    int input_size = 0;
    int output_size = 0;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    clock_t start_time;
    clock_t end_time;
    double elapsed_time;

    printf("Enter a string: ");
    fgets(input_string, MAX_SIZE, stdin);
    input_size = strlen(input_string);
    input_string[input_size - 1] = '\0';

    start_time = clock();

    for (i = 0; i < input_size; i++) {
        if (input_string[i] == 'a' || input_string[i] == 'A') {
            output_string[output_size++] = 'b';
        } else if (input_string[i] == 'b' || input_string[i] == 'B') {
            output_string[output_size++] = 'c';
        } else {
            output_string[output_size++] = input_string[i];
        }
    }

    end_time = clock();
    elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    printf("Input string: %s\n", input_string);
    printf("Output string: %s\n", output_string);
    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    free(input_string);
    free(output_string);

    return 0;
}