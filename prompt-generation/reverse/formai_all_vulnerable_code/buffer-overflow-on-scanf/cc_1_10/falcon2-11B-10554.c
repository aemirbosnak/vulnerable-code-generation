//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define MAX_LENGTH 100000

int main() {
    srand(time(NULL));
    int length;
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int count = 0;
    int i, j;
    int bit;
    char buf[2];
    char output_buf[MAX_LENGTH];

    printf("Enter a string of maximum length %d:\n", MAX_LENGTH);
    scanf("%s", input);

    length = strlen(input);
    if (length > MAX_LENGTH) {
        printf("Input string too long. Maximum length is %d.\n", MAX_LENGTH);
        return 1;
    }

    for (i = 0; i < length; i++) {
        buf[0] = input[i];
        buf[1] = '\0';
        bit = 0;
        for (j = 0; j < strlen(buf); j++) {
            if (buf[j] == '1') {
                bit |= 1 << (j % 8);
            }
        }
        output_buf[count++] = bit;
        if (count == MAX_LENGTH) {
            strncpy(output, output_buf, MAX_LENGTH);
            count = 0;
            output_buf[0] = '\0';
        }
    }
    strncpy(output + count, output_buf, MAX_LENGTH - count);

    printf("Compressed string:\n%s\n", output);
    return 0;
}