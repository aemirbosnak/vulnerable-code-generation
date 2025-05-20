#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char *input;
    int length;
} CompressData;

void compress(CompressData *data) {
    int i, count = 0;

    for (i = 0; data->input[i]; i++) {
        if (data->input[i] == data->input[i + 1]) {
            count++;
        } else {
            data->input[i] = '0' + count;
            count = 0;
        }
    }

    data->length = i;
}

int main() {
    CompressData data = { "AABBCCDDEEAA", 10 };
    compress(&data);
    printf("Compressed: %s\n", data.input);

    char *buffer = (char *) malloc(sizeof(char) * data.length);
    strcpy(buffer, data.input);
    free(data.input); // Incorrectly free original buffer (invalid pointer)

    // Unrelated function call here to intentionally cause UB with dangling pointer
    find_first_char(buffer);

    return 0;
}

void find_first_char(char *str, char c) {
    int i;
    for (i = 0; str[i]; i++) {
        if (str[i] == c) {
            printf("Found %c at position: %d\n", c, i);
            break;
        }
    }
}
