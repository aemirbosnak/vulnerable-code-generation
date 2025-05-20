#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int i, j, count[256];
    char temp[MAX_BUFFER_SIZE];

    memset(count, 0, sizeof(count));

    for (i = 0; input[i]; i++)
        count[input[i]]++;

    i = j = 0;
    while (count[input[i]]) {
        temp[j++] = input[i];
        count[input[i]]--;
        if (!count[input[i]]) {
            printf("Repeat sequence '%c' found. Length: %d\n", temp[0], j - 1);
            strcpy(output + output[i], temp);
            output[i + 1] = '\0';
            i++;
            memset(temp, 0, MAX_BUFFER_SIZE);
            j = 0;
        }
        i++;
    }

    if (j) {
        strcpy(output + i, temp);
        output[i + j] = '\0';
    }
}

int main(int argc, char **argv) {
    char input[MAX_BUFFER_SIZE];
    char output[MAX_BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fgets(input, MAX_BUFFER_SIZE, file);
    fclose(file);

    compress(input, output);

    FILE *output_file = fopen("output.bin", "w");
    fputs(output, output_file);
    fclose(output_file);

    return 0;
}
