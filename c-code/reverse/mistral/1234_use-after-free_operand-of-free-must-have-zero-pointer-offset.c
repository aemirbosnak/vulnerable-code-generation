#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable_function(char *str) {
    char *temp = malloc(strlen(str) * sizeof(char));
    strcpy(temp, str);

    free(temp + strlen(temp) - 1); // Free a portion of the dynamically allocated block

    printf("%c\n", temp[strlen(temp)]); // Access the freed memory
}

int main() {
    char *str = malloc(10 * sizeof(char));
    strcpy(str, "Hello, World!");
    vulnerable_function(str);
    free(str);

    return 0;
}
