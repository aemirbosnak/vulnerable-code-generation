#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void edit_text(char *buffer) {
    printf("Enter your text: ");
    gets(buffer); // Vulnerable to buffer overflow
}

int main() {
    char buffer[BUFFER_SIZE];
    edit_text(buffer);
    printf("Your text: %s\n", buffer);
    return 0;
}
