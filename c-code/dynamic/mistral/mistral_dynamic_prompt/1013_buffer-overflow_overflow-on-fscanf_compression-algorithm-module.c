#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Define our "compression" function, which is actually a decompression function (for amusement)
void decompress(char *input, char *output) {
    int i, j, k;
    char temp[3];

    for (i = 0, j = 0, k = 0; input[i] != '\0'; ++i) {
        temp[k++] = input[i];
        if (k >= 3) {
            output[j++] = temp[0];
            output[j++] = temp[1];
            output[j++] = temp[2];
            k = 0;
        }
    }

    // Handle the remaining characters if there are any
    if (k != 0) {
        for (int t = k; t < 3; ++t)
            temp[t] = temp[t % k];
        for (i = 0; temp[i] != '\0'; ++i)
            output[j++] = temp[i];
    }
}

int main(int argc, char *argv[]) {
    char input[1024], output[1024 * 10];

    printf("Enter data to 'compress'\n");
    fscanf(stdin, "%s", input); // Potential buffer overflow here
    decompress(input, output);
    printf("Compressed data:\n%s\n", output);

    return 0;
}
