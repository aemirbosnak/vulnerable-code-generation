#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = (char *)malloc(10);
    strcpy(str, "Hello, World!");

    printf("Original String: %s\n", str);

    char *new_str = (char *)realloc(str, 20);
    strcpy(new_str, "New String");

    printf("New String: %s\n", new_str);

    free(new_str + 6); // Freeing a portion of the reallocated memory block

    printf("Accessing freed memory: %c\n", new_str[10]); // Accessing the freed portion before freeing the remaining block

    free(str); // Freeing the original memory block

    return 0;
}
