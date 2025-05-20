#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LEN 10

void vulnerable_editor() {
    char buffer[MAX_LEN];
    printf("Welcome to the Vulnerable Text Editor!\n");
    printf("Enter your text: ");
    scanf("%s", buffer);
    printf("You entered: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    vulnerable_editor();
    return 0;
}
