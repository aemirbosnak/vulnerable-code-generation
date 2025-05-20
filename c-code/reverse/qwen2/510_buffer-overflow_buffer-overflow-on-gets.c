#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *text = (char *)malloc(1001 * sizeof(char));
    if (text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Enter text: ");
    gets(text);
    printf("Summary: %s\n", text);
    free(text);
    return 0;
}
