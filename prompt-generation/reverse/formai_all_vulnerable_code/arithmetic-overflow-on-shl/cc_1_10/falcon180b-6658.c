//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 12
#define MAX_CODE_VALUE 4095

typedef struct {
    int code;
    int length;
} Code;

typedef struct {
    int *codes;
    int num_codes;
    int max_code_length;
} CodeTable;

void init_code_table(CodeTable *table) {
    table->codes = (int*)malloc(MAX_CODE_VALUE * sizeof(int));
    table->num_codes = 0;
    table->max_code_length = 0;
}

int get_next_code(CodeTable *table) {
    int code = table->num_codes;
    table->num_codes++;
    if (table->num_codes > MAX_CODE_VALUE) {
        printf("Error: Code table overflow\n");
        exit(1);
    }
    return code;
}

void add_code(CodeTable *table, int code, int length) {
    if (length > MAX_CODE_LENGTH) {
        printf("Error: Code length too long\n");
        exit(1);
    }
    table->codes[code] = length;
    if (length > table->max_code_length) {
        table->max_code_length = length;
    }
}

int encode(char *input, int input_length, CodeTable *table) {
    int i = 0;
    int code = 0;
    while (i < input_length) {
        int j = 0;
        while (j < MAX_CODE_LENGTH && i < input_length && input[i] == input[i + j]) {
            j++;
        }
        if (j == 0) {
            printf("Error: Input string too short\n");
            exit(1);
        }
        int length = j;
        int code_value = table->codes[input[i]];
        if (code_value == 0) {
            add_code(table, input[i], length);
            code_value = get_next_code(table);
        }
        code = (code << (MAX_CODE_LENGTH - length)) | code_value;
        i += length;
    }
    return code;
}

void decode(int code, CodeTable *table, char *output) {
    int i = 0;
    while (code > 0) {
        int code_value = code & (MAX_CODE_VALUE - 1);
        int length = MAX_CODE_LENGTH - __builtin_clz(code_value);
        if (length > MAX_CODE_LENGTH) {
            printf("Error: Invalid code value\n");
            exit(1);
        }
        output[i] = code_value;
        i++;
        code >>= length;
    }
    output[i] = '\0';
}

int main() {
    char input[] = "aaabbbcccdddeeeeffffgggg";
    int input_length = strlen(input);
    CodeTable table;
    init_code_table(&table);
    int code = encode(input, input_length, &table);
    printf("Encoded code: %d\n", code);
    char output[MAX_CODE_LENGTH];
    decode(code, &table, output);
    printf("Decoded string: %s\n", output);
    return 0;
}