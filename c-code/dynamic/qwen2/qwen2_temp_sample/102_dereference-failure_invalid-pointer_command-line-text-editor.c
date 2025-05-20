#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void edit_text(char* text) {
    char* ptr = NULL;
    *ptr = 'A'; // Dereference null pointer
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char* input_text = argv[1];
    edit_text(input_text);

    printf("Edited text: %s\n", input_text);
    return 0;
}
