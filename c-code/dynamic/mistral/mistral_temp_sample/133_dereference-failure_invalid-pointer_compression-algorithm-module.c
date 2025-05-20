#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress(char *input, char *output) {
    int i;
    char *ptr = (char *) malloc(sizeof(char) * strlen(input));

    for(i = 0; i < strlen(input); i++) {
        ptr[i] = input[i];
        if(ptr[i] == 'a') {
            strcat(ptr, " (vowel)");
        }
    }

    strcpy(output, ptr);
    free(ptr);
}

int main() {
    char input[100], output[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    compress(input, output);
    printf("Compressed string: %s\n", output);

    char *invalid_ptr = NULL;
    printf("Accessing invalid memory location: %c\n", *invalid_ptr);

    return 0;
}
