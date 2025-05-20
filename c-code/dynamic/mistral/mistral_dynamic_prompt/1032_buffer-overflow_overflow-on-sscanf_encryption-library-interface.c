#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

/* Fake encryption library interface */
void encrypt(char* input, char* output, int key) {
    int i;
    for (i = 0; input[i]; i++) {
        output[i] = (char)(input[i] + key);
    }
    output[i] = '\0';
}

/* Function to read input for encryption */
void read_input(char* buffer, int buffer_size) {
    printf("Enter data to encrypt (up to %d characters):\n", buffer_size);
    fgets(buffer, buffer_size, stdin);
}

int main() {
    char input_buffer[256];
    char output_buffer[256];
    int key;

    printf("Enter encryption key (1-1024):\n");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input. Exiting...\n");
        return 1;
    }

    read_input(input_buffer, sizeof(input_buffer));

    encrypt(input_buffer, output_buffer, key);
    printf("Encrypted output:\n%s\n", output_buffer);

    /* Deliberate buffer overflow exploit: exceed the buffer size provided to sscanf */
    char exploit_buffer[8];
    if (sscanf(input_buffer, "%s", exploit_buffer) >= 789) {
        /* Buffer overflow occurs here */
    }

    return 0;
}
