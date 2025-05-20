//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert_color_code(char* color_code, char* rgb_color_code) {
    int length = strlen(color_code);
    int index = 0;

    while (index < length) {
        if (color_code[index] == '#') {
            rgb_color_code[index] = '#';
            index++;
        } else if (index < length - 1 && (color_code[index] == 'A' || color_code[index] == 'a') && color_code[index + 1] == 'B' || color_code[index] == 'B' && color_code[index + 1] == 'a') {
            rgb_color_code[index] = '0';
            rgb_color_code[index + 1] = 'x';
            index += 2;
        } else if (index < length - 2 && (color_code[index] == 'A' || color_code[index] == 'a') && color_code[index + 1] == 'C' && color_code[index + 2] == 'B' || color_code[index] == 'B' && color_code[index + 1] == 'C' && color_code[index + 2] == 'a') {
            rgb_color_code[index] = '0';
            rgb_color_code[index + 1] = 'x';
            rgb_color_code[index + 2] = 'x';
            index += 3;
        } else if (index < length - 3 && (color_code[index] == 'A' || color_code[index] == 'a') && color_code[index + 1] == 'D' && color_code[index + 2] == 'C' && color_code[index + 3] == 'B' || color_code[index] == 'B' && color_code[index + 1] == 'D' && color_code[index + 2] == 'C' && color_code[index + 3] == 'a') {
            rgb_color_code[index] = '0';
            rgb_color_code[index + 1] = 'x';
            rgb_color_code[index + 2] = 'x';
            rgb_color_code[index + 3] = 'x';
            index += 4;
        } else if (index < length - 4 && (color_code[index] == 'A' || color_code[index] == 'a') && color_code[index + 1] == 'E' && color_code[index + 2] == 'D' && color_code[index + 3] == 'C' && color_code[index + 4] == 'B' || color_code[index] == 'B' && color_code[index + 1] == 'E' && color_code[index + 2] == 'D' && color_code[index + 3] == 'C' && color_code[index + 4] == 'a') {
            rgb_color_code[index] = '0';
            rgb_color_code[index + 1] = 'x';
            rgb_color_code[index + 2] = 'x';
            rgb_color_code[index + 3] = 'x';
            rgb_color_code[index + 4] = 'x';
            index += 5;
        } else if (index < length - 5 && (color_code[index] == 'A' || color_code[index] == 'a') && color_code[index + 1] == 'F' && color_code[index + 2] == 'E' && color_code[index + 3] == 'D' && color_code[index + 4] == 'C' && color_code[index + 5] == 'B' || color_code[index] == 'B' && color_code[index + 1] == 'F' && color_code[index + 2] == 'E' && color_code[index + 3] == 'D' && color_code[index + 4] == 'C' && color_code[index + 5] == 'a') {
            rgb_color_code[index] = '0';
            rgb_color_code[index + 1] = 'x';
            rgb_color_code[index + 2] = 'x';
            rgb_color_code[index + 3] = 'x';
            rgb_color_code[index + 4] = 'x';
            rgb_color_code[index + 5] = 'x';
            index += 6;
        } else if (index < length - 6 && (color_code[index] == 'A' || color_code[index] == 'a') && color_code[index + 1] == 'G' && color_code[index + 2] == 'F' && color_code[index + 3] == 'E' && color_code[index + 4] == 'D' && color_code[index + 5] == 'C' && color_code[index + 6] == 'B' || color_code[index] == 'B' && color_code[index + 1] == 'G' && color_code[index + 2] == 'F' && color_code[index + 3] == 'E' && color_code[index + 4] == 'D' && color_code[index + 5] == 'C' && color_code[index + 6] == 'a') {
            rgb_color_code[index] = '0';
            rgb_color_code[index + 1] = 'x';
            rgb_color_code[index + 2] = 'x';
            rgb_color_code[index + 3] = 'x';
            rgb_color_code[index + 4] = 'x';
            rgb_color_code[index + 5] = 'x';
            rgb_color_code[index + 6] = 'x';
            index += 7;
        } else {
            rgb_color_code[index] = color_code[index];
            index++;
        }
    }
}

int main() {
    char color_code[8];
    scanf("%s", color_code);
    char rgb_color_code[8];
    convert_color_code(color_code, rgb_color_code);
    printf("%s\n", rgb_color_code);
    return 0;
}