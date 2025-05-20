#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void read_message(char *buffer) {
    printf("Enter your message: ");
    fscanf(stdin, "%s", buffer);
}

int main() {
    char buffer[BUFFER_SIZE];
    int i;

    while (1) {
        read_message(buffer);
        printf("Your message: %s\n", buffer);

        // Simulate processing time
        for (i = 0; i < 1000000; i++) {
            // Do nothing
        }
    }

    return 0;
}
