#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerable_function() {
    char buffer[10];
    printf("Enter data: ");
    fscanf(stdin, "%s", buffer); // Vulnerability here
}

int main() {
    vulnerable_function();
    return 0;
}
