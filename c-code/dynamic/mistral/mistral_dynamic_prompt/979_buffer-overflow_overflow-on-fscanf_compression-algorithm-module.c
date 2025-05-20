#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFF_SIZE 100

void compress(char *input, char *output) {
    int i, count[128];
    memset(count, 0, sizeof(count));

    for (i = 0; input[i]; ++i) {
        count[input[i]]++;
    }

    for (i = 0; i < 128; ++i) {
        if (count[i]) {
            sprintf(output, "%c%d", i, count[i]);
            output += 2; // Move output pointer ahead
        }
    }
}

int main(int argc, char **argv) {
    char input[MAX_BUFF_SIZE];
    char output[MAX_BUFF_SIZE];
    char temp[MAX_BUFF_SIZE];

    printf("Compression Tool\n");
    printf("Enter text to compress: ");
    fgets(input, MAX_BUFF_SIZE, stdin);

    compress(input, output);
    printf("Compressed data:\n%s\n", output);

    printf("Enter more text to append and compress (type end to stop):\n");
    while (1) {
        fgets(temp, MAX_BUFF_SIZE, stdin);
        strcat(output, temp);
        compress(output, output);
        printf("Updated compressed data:\n%s\n", output);

        if (strcmp(temp, "end\n") == 0) {
            break;
        }
    }

    return 0;
}
