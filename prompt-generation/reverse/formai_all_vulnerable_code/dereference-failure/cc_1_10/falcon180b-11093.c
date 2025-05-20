//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LENGTH 32

char input_line[MAX_LINE_LENGTH];
char *binary_num = NULL;
int binary_len = 0;

void read_line(FILE *file) {
    fgets(input_line, MAX_LINE_LENGTH, file);
    input_line[strcspn(input_line, "\n")] = '\0';
}

int is_binary(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i]) && str[i]!= '0' && str[i]!= '1') {
            return 0;
        }
    }
    return 1;
}

void convert_binary(char *decimal_num) {
    int i, j;
    char binary_digit;
    int decimal_value = atoi(decimal_num);

    for (i = MAX_NUM_LENGTH - 1; i >= 0; i--) {
        binary_digit = decimal_value % 2;
        if (binary_digit == 0) {
            binary_num[i] = '0';
        } else {
            binary_num[i] = '1';
        }
        decimal_value /= 2;
    }
    binary_len = strlen(binary_num);
}

void print_binary(char *binary_num, int binary_len) {
    int i;
    for (i = 0; i < binary_len; i++) {
        printf("%c", binary_num[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(input_line, MAX_LINE_LENGTH, file)!= NULL) {
        if (is_binary(input_line)) {
            binary_num = strdup(input_line);
            binary_len = strlen(binary_num);
            print_binary(binary_num, binary_len);
        } else {
            convert_binary(input_line);
            print_binary(binary_num, binary_len);
        }
    }

    fclose(file);
    return 0;
}