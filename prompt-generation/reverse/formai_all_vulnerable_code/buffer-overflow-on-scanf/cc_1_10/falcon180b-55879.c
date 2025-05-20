//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10000

char* binary_convert(char* str) {
    int len = strlen(str);
    char* binary = malloc(MAX_SIZE);
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (isdigit(str[i])) {
            int num = str[i] - '0';
            if (num < 0 || num > 1) {
                free(binary);
                return NULL;
            }
            binary[j++] = num + '0';
        } else if (str[i] == 'x' || str[i] == 'X') {
            i++;
            if (i >= len) {
                free(binary);
                return NULL;
            }
            if (isdigit(str[i])) {
                int num = str[i] - '0';
                if (num < 0 || num > 15) {
                    free(binary);
                    return NULL;
                }
                binary[j++] = num + '0';
            } else if (isxdigit(str[i])) {
                int num = tolower(str[i]) - 'a';
                if (num < 0 || num > 15) {
                    free(binary);
                    return NULL;
                }
                binary[j++] = num + '0';
            } else {
                free(binary);
                return NULL;
            }
        } else {
            free(binary);
            return NULL;
        }
        i++;
    }
    binary[j] = '\0';
    return binary;
}

int main() {
    char* input;
    char* binary;
    int len;
    int i;

    printf("Enter a string to convert to binary: ");
    scanf("%s", input);

    binary = binary_convert(input);

    if (binary == NULL) {
        printf("Invalid input.\n");
        return 1;
    }

    len = strlen(binary);
    for (i = 0; i < len; i++) {
        if (binary[i] == '0') {
            printf("0b0");
        } else if (binary[i] == '1') {
            printf("0b1");
        } else {
            printf("Invalid binary character: %c", binary[i]);
            return 1;
        }
    }

    printf("\n");
    return 0;
}