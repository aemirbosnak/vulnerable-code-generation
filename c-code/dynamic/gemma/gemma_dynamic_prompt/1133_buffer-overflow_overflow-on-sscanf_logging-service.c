#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[1024];
    char input[256];

    printf("Enter a message: ");
    scanf("%s", input);

    sprintf(buffer, "Log entry: %s", input);

    printf("%s\n", buffer);

    return 0;
}
