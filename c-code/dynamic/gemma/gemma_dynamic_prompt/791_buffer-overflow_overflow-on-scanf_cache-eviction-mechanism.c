#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[1024];
    int size = 0;

    printf("Enter the size of the data to be stored: ");
    scanf("%d", &size);

    if (size > 1024) {
        printf("Error: The size of the data exceeded the buffer size.\n");
        exit(1);
    }

    printf("Enter the data: ");
    scanf("%s", buffer);

    // Overflow the buffer to exploit the vulnerability
    buffer[size] = '\x0a';

    printf("Data stored successfully.\n");

    return 0;
}
