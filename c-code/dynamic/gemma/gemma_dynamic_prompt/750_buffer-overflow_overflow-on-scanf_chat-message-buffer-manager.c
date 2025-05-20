#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[1024];
    int i = 0;

    printf("Enter a message: ");
    scanf("%s", buffer);

    // Overflow the buffer by writing more than the size of the buffer
    for (i = 0; i < 1024; i++) {
        printf("A");
    }

    printf("\nYour message: %s", buffer);

    return 0;
}
