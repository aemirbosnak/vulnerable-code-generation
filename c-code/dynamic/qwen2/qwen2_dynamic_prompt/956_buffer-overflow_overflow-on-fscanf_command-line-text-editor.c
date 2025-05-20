#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerable_function() {
    char buffer[10];
    printf("Enter a string: ");
    fscanf(stdin, "%s", buffer); // Vulnerable to buffer overflow
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "w");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    vulnerable_function();

    fclose(file);
    return 0;
}
