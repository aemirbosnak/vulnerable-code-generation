#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 10

void edit_text(char *buffer) {
    printf("Enter text: ");
    scanf("%s", buffer);
}

int main() {
    char buffer[MAX_LINE_LENGTH];
    memset(buffer, 0, sizeof(buffer));
    edit_text(buffer);
    printf("Buffer content: %s\n", buffer);
    return 0;
}
