#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_user_input(int input) {
    int buffer_size = 1024;
    char *buffer = (char *)malloc(buffer_size);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Vulnerability: Integer Overflow
    int data = input * 10; // This can cause an overflow if input is large

    if (data > buffer_size) {
        printf("Buffer overflow detected!\n");
        free(buffer);
        return;
    }

    snprintf(buffer, data + 1, "User input processed: %d", input);
    printf("%s\n", buffer);

    free(buffer);
}

int main() {
    int user_input;

    printf("Enter a number: ");
    scanf("%d", &user_input);

    process_user_input(user_input);

    return 0;
}
