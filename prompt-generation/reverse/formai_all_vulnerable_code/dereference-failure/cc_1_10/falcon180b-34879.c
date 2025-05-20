//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main(int argc, char **argv) {

    char *input_string = NULL;
    char *output_string = NULL;
    int input_length = 0;
    int output_length = 0;

    if (argc < 2) {
        printf("Error: No input string provided\n");
        return 1;
    }

    input_string = argv[1];
    input_length = strlen(input_string);

    if (input_length > MAX_STRING_LENGTH) {
        printf("Error: Input string is too long\n");
        return 1;
    }

    output_string = malloc(input_length + 1);
    if (output_string == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    output_length = reverse_string(input_string, output_string);

    printf("Input string: %s\n", input_string);
    printf("Output string: %s\n", output_string);

    free(output_string);
    return 0;
}

int reverse_string(char *input_string, char *output_string) {

    int i = 0;
    int j = strlen(input_string) - 1;

    while (i <= j) {
        output_string[i] = input_string[j];
        i++;
        j--;
    }

    output_string[i] = '\0';

    return i;
}