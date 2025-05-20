#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void win() {
    printf("Congratulations! You've won!\n");
}

int main() {
    char name[16];
    printf("Enter your name: ");
    gets(name); // Vulnerable to buffer overflow
    return 0;
}
