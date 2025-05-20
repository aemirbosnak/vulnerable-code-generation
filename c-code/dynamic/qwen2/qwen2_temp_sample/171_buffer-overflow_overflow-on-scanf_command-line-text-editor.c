#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 10

void edit_text(char *text) {
    char input[MAX_LINE_LENGTH];
    printf("Enter your text: ");
    scanf("%[^\n]%*c", input); // Vulnerable to buffer overflow
    strcat(text, input);
}

int main() {
    char text[MAX_LINE_LENGTH] = "Initial text";
    printf("Current text: %s\n", text);

    for (int i = 0; i < 20; i++) {
        edit_text(text);
        printf("Updated text: %s\n", text);
    }

    return 0;
}
