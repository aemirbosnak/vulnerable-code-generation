//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *code;
    int frequency;
} code_t;

int compare_codes(const void *a, const void *b) {
    code_t *code1 = (code_t *)a;
    code_t *code2 = (code_t *)b;
    return code1->frequency - code2->frequency;
}

void generate_codes(code_t *codes, int n, char *buff, int buff_size) {
    if (n == 1) {
        codes[0].code = malloc(buff_size + 1);
        strcpy(codes[0].code, buff);
        return;
    }

    qsort(codes, n, sizeof(code_t), compare_codes);
    code_t new_code;
    new_code.code = malloc(buff_size + 1);
    strcpy(new_code.code, buff);
    new_code.code[buff_size] = '0';
    codes[n-2] = new_code;
    new_code.code[buff_size] = '1';
    codes[n-1] = new_code;
    generate_codes(codes, n-2, buff, buff_size + 1);
}

int main() {
    char input[1000];
    printf("Enter the text to be compressed: ");
    scanf("%s", input);

    int frequency[256] = {0};
    for (int i = 0; input[i] != '\0'; i++) {
        frequency[input[i]]++;
    }

    int n = 0;
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            n++;
        }
    }

    code_t codes[n];
    for (int i = 0; i < n; i++) {
        codes[i].frequency = frequency[(int)input[i]];
    }

    char buff[1000];
    generate_codes(codes, n, buff, 0);

    printf("The compressed text is: ");
    for (int i = 0; input[i] != '\0'; i++) {
        for (int j = 0; j < n; j++) {
            if ((int)input[i] == (int)codes[j].code[0]) {
                printf("%s", codes[j].code);
            }
        }
    }

    return 0;
}