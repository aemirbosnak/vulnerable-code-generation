//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAX_STR_LEN 10000

// Function to read a string from standard input
char* read_string() {
    char* str = NULL;
    int len = 0;
    char ch;

    do {
        ch = getchar();
        if (ch == '\n') {
            ch = '\0';
        }
        if (len >= MAX_STR_LEN) {
            printf("Error: Input string too long.\n");
            exit(1);
        }
        str = realloc(str, len + 2);
        str[len++] = tolower(ch);
    } while (ch!= '\0');

    str[len] = '\0';
    return str;
}

// Function to parse a QR code string and return its data
char* parse_qr_code(char* code) {
    int len = strlen(code);
    int i, j, k, num_bits, bit_pos, data_pos;
    char* data = malloc(len * 8 + 1); // Allocate memory for data string

    for (i = 0, j = 0, data_pos = 0; i < len; i++) {
        if (code[i] == '1') {
            if (j == 0) {
                j = 1;
                num_bits = 0;
            }
            num_bits++;
            if (num_bits == 8) {
                data[data_pos++] = (char) j;
                j = 0;
                num_bits = 0;
            }
        } else {
            if (j == 1) {
                j = 0;
            }
        }
    }

    if (num_bits > 0) {
        data[data_pos++] = (char) j;
    }
    data[data_pos] = '\0';

    return data;
}

// Function to display the data extracted from a QR code
void display_qr_data(char* data) {
    int i;

    printf("Data extracted from QR code:\n");
    for (i = 0; i < strlen(data); i++) {
        printf("%c", data[i]);
    }
    printf("\n");
}

// Main function
int main() {
    char* code = read_string();
    char* data = parse_qr_code(code);
    display_qr_data(data);

    free(code);
    free(data);

    return 0;
}