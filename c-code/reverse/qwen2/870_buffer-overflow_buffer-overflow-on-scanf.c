#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define BUFFER_SIZE 10

int main() {
    char buffer[BUFFER_SIZE];
    printf("Enter a command: ");
    scanf("%s", buffer);
    return 0;
}
