#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[1024];
    int len;

    printf("Enter file name: ");
    scanf("%s", buffer);

    len = strlen(buffer);
    if (len > 1024) {
        printf("Error: File name too long.\n");
        exit(1);
    }

    // Deliberate buffer overflow
    buffer[len] = 'A';
    buffer[len + 1] = 'A';
    buffer[len + 2] = 'A';

    printf("File name: %s\n", buffer);

    return 0;
}
