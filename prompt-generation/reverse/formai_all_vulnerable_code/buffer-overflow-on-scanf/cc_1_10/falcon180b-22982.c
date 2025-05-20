//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 16
#define MAX_COLOR_CODE_LENGTH 7

int hex_to_int(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else {
        return -1;
    }
}

int str_to_int(char* str) {
    int num = 0;
    int i = 0;
    while (str[i]!= '\0') {
        int digit = hex_to_int(str[i]);
        if (digit == -1) {
            return -1;
        }
        num = num * 16 + digit;
        i++;
    }
    return num;
}

void print_color_code(int code) {
    printf("#%06X\n", code);
}

int main() {
    char color_name[MAX_COLOR_NAME_LENGTH];
    char color_code[MAX_COLOR_CODE_LENGTH];
    int color_code_int;

    printf("Enter a color name: ");
    scanf("%s", color_name);

    printf("Enter a color code (in hexadecimal): ");
    scanf("%s", color_code);

    int code_len = strlen(color_code);
    if (code_len!= 6) {
        printf("Invalid color code length.\n");
        return 1;
    }

    color_code_int = str_to_int(color_code);
    if (color_code_int == -1) {
        printf("Invalid color code.\n");
        return 1;
    }

    printf("Color name: %s\n", color_name);
    printf("Color code: %s\n", color_code);
    printf("Color code (integer): %d\n", color_code_int);
    print_color_code(color_code_int);

    return 0;
}