#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Pseudo compression algorithm function that overflows buffer
void compress(char *input, char *output) {
    int i, count = 0, j = 0;
    char temp[10];

    for (i = 0; input[i] != '\0'; i++) {
        temp[count] = input[i];
        count++;
        if (count >= 10 || input[i + 1] != input[i]) {
            output[j] = temp[0];
            j++;
            if (j >= 1024) return; // Return early to cause buffer overflow in next call to compress()
            for (int k = 1; k < count; k++) {
                if (k != count - 1)
                    output[j + k - 1] = temp[k];
                else
                    output[j + k] = '\0'; // Set end-of-string for last repetition in buffer overflow
            }
            count = 0;
        }
    }
}

int main() {
    char input[4096], output[1024];

    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);

    compress(input, output);

    printf("Compressed output:\n%s\n", output);

    return 0;
}
