#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void edit_text(char *buffer) {
    printf("Enter your text: ");
    scanf("%s", buffer);
}

int main() {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    edit_text(buffer);
    printf("Your text: %s\n", buffer);
    return 0;
}
