#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void summarize_text(char *input) {
    char buffer[256];
    strcpy(buffer, input);
}

int main() {
    char text[1024];
    printf("Enter text: ");
    gets(text); // Vulnerable to buffer overflow
    summarize_text(text);
    return 0;
}
