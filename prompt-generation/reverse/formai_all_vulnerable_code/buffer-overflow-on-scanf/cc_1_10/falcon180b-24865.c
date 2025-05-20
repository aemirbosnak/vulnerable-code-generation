//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODES 1000
#define MAX_CODE_LENGTH 7

typedef struct {
    char code[MAX_CODE_LENGTH];
    int value;
} Code;

int main() {
    int num_codes = 0;
    Code codes[MAX_CODES];
    char input_code[MAX_CODE_LENGTH];
    int input_value;
    char choice;

    do {
        printf("Enter a color code (or 'q' to quit):\n");
        scanf("%s", input_code);

        if (strcmp(input_code, "q") == 0) {
            break;
        }

        input_value = strtol(input_code, NULL, 16);

        for (int i = 0; i < num_codes; i++) {
            if (codes[i].value == input_value) {
                printf("%s -> %s\n", codes[i].code, input_code);
                break;
            }
        }

        if (num_codes >= MAX_CODES) {
            printf("Maximum number of codes reached.\n");
            continue;
        }

        strcpy(codes[num_codes].code, input_code);
        codes[num_codes].value = input_value;
        num_codes++;

        printf("Code added.\n");
    } while (1);

    return 0;
}