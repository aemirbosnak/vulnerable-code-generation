#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress(char *input) {
    char compressed[10];
    int i, count = 0;

    for (i = 0; input[i]; ++i) {
        if (i > 0 && input[i] == input[i - 1]) {
            if (count < 9)
                compressed[count++] = input[i];
        } else {
            if (count > 0) {
                compressed[count++] = input[i];
                compressed[count++] = ' ';
            }
            if (count == 9) {
                compressed[count++] = '\0';
                fputs(compressed, stdout);
                memcpy(compressed, &input[i], sizeof(char) * (strlen(input) - i));
                i = i - 1;
                count = 0;
            }
        }
    }

    if (count > 0)
        fputs(compressed, stdout);
}

int main() {
    char buffer[1024];

    printf("Enter a string to compress: ");
    fscanf(stdin, "%1023s", buffer); // Buffer overflow vulnerability here
    compress(buffer);

    return 0;
}
