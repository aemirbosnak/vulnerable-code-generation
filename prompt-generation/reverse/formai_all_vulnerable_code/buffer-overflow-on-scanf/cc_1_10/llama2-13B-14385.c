//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: genius
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define BINARY_STRING_MAX_LENGTH 1024
#define BINARY_CONVERT_TABLE_SIZE 64

typedef struct binary_convert_table_entry {
    uint8_t value;
    char binary_string[BINARY_STRING_MAX_LENGTH];
} binary_convert_table_entry_t;

static binary_convert_table_entry_t binary_convert_table[BINARY_CONVERT_TABLE_SIZE];

int main() {
    uint32_t input_number;
    char binary_string[BINARY_STRING_MAX_LENGTH];

    printf("Enter an integer number to convert to binary: ");
    scanf("%u", &input_number);

    binary_string[0] = '\0';
    for (int i = 0; i < BINARY_CONVERT_TABLE_SIZE; i++) {
        if (input_number >= binary_convert_table[i].value) {
            binary_string[0] = binary_convert_table[i].binary_string[0];
            input_number -= binary_convert_table[i].value;
            break;
        }
    }

    printf("The binary representation of %u is: %s\n", input_number, binary_string);

    return 0;
}

void init_binary_convert_table() {
    binary_convert_table_entry_t entry;

    for (int i = 0; i < BINARY_CONVERT_TABLE_SIZE; i++) {
        entry.value = (uint8_t)pow(2, i * 4);
        snprintf(entry.binary_string, BINARY_STRING_MAX_LENGTH, "%c%c%c%c",
                 (i % 4) ? '1' : '0',
                 (i % 4) ? '0' : '1',
                 (i % 4) ? '0' : '1',
                 (i % 4) ? '0' : '1');
        binary_convert_table[i] = entry;
    }
}