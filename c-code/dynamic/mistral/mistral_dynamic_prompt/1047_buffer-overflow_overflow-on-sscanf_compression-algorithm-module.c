#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Function to compress data by replacing consecutive duplicates of a character with the count and character
void compress(char *input, char *output) {
    int i, j = 0, count = 1;
    for (i = 0; input[i]; i++) {
        if (i > 0 && input[i] == input[i - 1]) {
            count++;
        } else {
            output[j++] = count + '0';
            output[j++] = input[i];
            count = 1;
        }
    }
    output[j] = '\0';
}

int main() {
    char input[1024], output[1024];
    int size;

    printf("Enter the string to compress:\n");
    fgets(input, sizeof(input), stdin);

    compress(input, output);
    printf("Compressed string:\n%s\n", output);

    // Overflow by supplying a larger string to sscanf than the allocated buffer
    char input2[10];
    size = sscanf(output, "%s%n", input2, sizeof(input2));
    printf("Number of tokens read: %d\n", size); // This line should print more than 10 to trigger the buffer overflow

    return 0;
}
