#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char playerName[10];
    printf("Enter your name: ");
    scanf("%s", playerName);
    printf("Hello, %s!\n", playerName);
    return 0;
}
