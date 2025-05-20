#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[1024];
    int result;

    printf("Enter a message: ");
    scanf("%s", buffer);

    result = strlen(buffer) + 1;
    if (result > 1024) {
        printf("Error: buffer overflow\n");
    } else {
        printf("Message: %s\n", buffer);
    }

    return 0;
}
