#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void read_data(char *buffer, int size) {
    printf("Enter data (up to %d characters):\n", size);
    fscanf(stdin, "%s", buffer);
}

void process_data(char *data) {
    // Pseudo-processing code for the sake of the example
    printf("Processing data: %s\n", data);
}

int main() {
    char input[10];
    read_data(input, 9);
    process_data(input);

    char data[1024];
    read_data(data, 1024);
    process_data(data);

    return 0;
}
