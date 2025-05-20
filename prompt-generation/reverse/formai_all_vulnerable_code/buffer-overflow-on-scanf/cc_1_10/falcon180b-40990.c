//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_SIZE 1024
#define MAX_CODE_LENGTH 16
#define MAX_CODE_CHAR 256

typedef struct {
    int frequency;
    char code;
} Code;

void initialize_code(Code *code, int num_codes) {
    for (int i = 0; i < num_codes; i++) {
        code[i].frequency = 0;
        code[i].code = '\0';
    }
}

void build_code(char *string, int length, Code *code) {
    int i;
    for (i = 0; i < length; i++) {
        if (code[string[i]].frequency == 0) {
            code[string[i]].frequency = 1;
            code[string[i]].code = (char)i;
        } else {
            code[string[i]].frequency++;
        }
    }
}

void generate_code(char *string, int length, Code *code) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%c = %c%c\n", string[i], code[string[i]].code, (i == length - 1)? '\n' : ',');
    }
}

int main() {
    char string[MAX_CODE_LENGTH];
    Code code[MAX_CODE_SIZE];

    printf("Enter a string: ");
    scanf("%s", string);

    int length = strlen(string);

    initialize_code(code, MAX_CODE_SIZE);
    build_code(string, length, code);
    generate_code(string, length, code);

    return 0;
}