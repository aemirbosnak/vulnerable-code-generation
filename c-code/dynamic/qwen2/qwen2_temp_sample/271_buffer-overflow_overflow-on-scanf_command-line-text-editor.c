#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

void edit_text(char *text) {
    char buffer[MAX_SIZE];
    printf("Enter your text: ");
    scanf("%s", buffer);
    strcpy(text, buffer);
}

int main() {
    char text[20];
    memset(text, 'A', sizeof(text));
    edit_text(text);
    printf("Text after editing: %s\n", text);
    return 0;
}
