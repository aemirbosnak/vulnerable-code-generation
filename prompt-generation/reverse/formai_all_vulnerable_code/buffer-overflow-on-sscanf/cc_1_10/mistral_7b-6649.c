//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} rgb;

typedef struct {
    char hex[3];
    unsigned char value;
} hex_byte;

void rgb_to_hex(rgb rgb_val) {
    hex_byte hex_arr[3];

    for (int i = 0; i < 3; i++) {
        sprintf(hex_arr[i].hex, "%02X", rgb_val.r >> (i * 5));
        hex_arr[i].value = strtoul(hex_arr[i].hex, NULL, 16);
        rgb_val.r &= ~(0xF << (i * 5));
        rgb_val.r |= hex_arr[i].value << (i * 5);
    }

    for (int i = 0; i < 3; i++) {
        printf("%s%s", hex_arr[i].hex, (i == 2) ? "\n" : "");
    }
}

void hex_to_rgb(char hex[7]) {
    hex_byte hex_arr[3];
    unsigned char r, g, b;

    sscanf(hex, "%2c%2c%2c%2c%2c%2c", &hex_arr[0].hex[0], &hex_arr[0].hex[1], &hex_arr[1].hex[0], &hex_arr[1].hex[1], &hex_arr[2].hex[0], &hex_arr[2].hex[1]);

    sscanf(hex_arr[0].hex, "%X", &hex_arr[0].value);
    r = (hex_arr[0].value >> 3) << 3;

    sscanf(hex_arr[1].hex, "%X", &hex_arr[1].value);
    g = (hex_arr[1].value >> 3) << 5;

    sscanf(hex_arr[2].hex, "%X", &hex_arr[2].value);
    b = hex_arr[2].value << 3;

    printf("R: %d\nG: %d\nB: %d\n", r | g | b, g, b);
}

int main() {
    char input[10];
    rgb rgb_val;
    char hex_val[7];

    printf("Enter RGB (R G B) or HEX (#XXXXXX) values: ");
    fgets(input, sizeof(input), stdin);

    if (input[0] == '#') {
        sscanf(input, "#%s%s%s%s%s%s", hex_val, NULL, NULL, NULL, NULL, NULL);
        hex_to_rgb(hex_val);
    } else {
        sscanf(input, "%d%d%d", &rgb_val.r, &rgb_val.g, &rgb_val.b);
        rgb_to_hex(rgb_val);
    }

    return 0;
}