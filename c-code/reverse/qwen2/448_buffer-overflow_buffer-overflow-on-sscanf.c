#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char command[10];
    printf("Enter light control command: ");
    scanf("%9s", command);
    printf("Command received: %s\n", command);
    return 0;
}
