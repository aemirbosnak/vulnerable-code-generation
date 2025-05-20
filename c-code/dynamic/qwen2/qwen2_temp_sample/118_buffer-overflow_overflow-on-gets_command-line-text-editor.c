#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void edit_text(char *text) {
    printf("Enter your text: ");
    gets(text); // Vulnerability: No bounds checking
}

int main() {
    char buffer[10];
    printf("Welcome to the insecure Text Editor!\n");
    edit_text(buffer);
    printf("Your text: %s\n", buffer);
    return 0;
}
