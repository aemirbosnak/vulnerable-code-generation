//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int hex_to_dec(char hex_num) {
    if (hex_num >= '0' && hex_num <= '9') {
        return hex_num - '0';
    } else if (hex_num >= 'A' && hex_num <= 'F') {
        return hex_num - 'A' + 10;
    } else if (hex_num >= 'a' && hex_num <= 'f') {
        return hex_num - 'a' + 10;
    } else {
        return -1;
    }
}

int dec_to_hex(int dec_num) {
    char hex_num[3];
    sprintf(hex_num, "%X", dec_num);
    return hex_num[0];
}

int main() {
    char input_color[MAX_LENGTH];
    char output_color[MAX_LENGTH];
    int i, j;

    printf("Enter a color code: ");
    scanf("%s", input_color);

    // check if input is valid color code
    if (strlen(input_color)!= 7 || input_color[0]!= '#') {
        printf("Invalid color code format.\n");
        return 1;
    }

    // convert input color code to decimal format
    for (i = 1, j = 0; i <= 6; i++, j++) {
        int hex_num = hex_to_dec(input_color[i]);
        if (hex_num == -1) {
            printf("Invalid color code format.\n");
            return 1;
        }
        output_color[j] = dec_to_hex(hex_num);
    }

    // convert decimal color code to RGB format
    printf("RGB color code: ");
    for (i = 0; i < 6; i++) {
        printf("%02X%02X%02X", output_color[i], output_color[i + 1], output_color[i + 2]);
        if (i!= 5) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}