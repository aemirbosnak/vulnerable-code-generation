//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct { int r, g, b; } rgb;
typedef struct { char hex[3]; } hex;

rgb rgb_from_hex(const char* hex) {
    rgb result;
    sscanf(hex, "%2hhx%2hhx%2hhx", &result.r, &result.g, &result.b);
    return result;
}

hex hex_from_rgb(const rgb* rgb_val) {
    char temp[3][3];
    int i;

    for (i = 0; i < 3; i++) {
        sprintf(temp[i], "%02x", rgb_val->r >> (8 * (2 - i)));
        strcat(temp[i], temp[(i + 1) % 3]);
    }

    hex result;
    strncpy(result.hex, temp[0], 2);
    strncpy(result.hex + 2, temp[1], 2);
    strncpy(result.hex + 4, temp[2], 2);

    return result;
}

int main() {
    char rgb_str[11];
    char hex_str[7];
    rgb rgb_val;
    hex hex_val;

    puts("Enter RGB value: #RRGGBB or RRGGBB");
    scanf("%s", rgb_str);

    if (rgb_str[0] == '#') {
        rgb_val = rgb_from_hex(rgb_str + 1);
        hex_val = hex_from_rgb(&rgb_val);

        sprintf(hex_str, "#%s%s%s", hex_val.hex, hex_val.hex + 2, hex_val.hex + 4);
        printf("HEX: %s\n", hex_str);
    } else {
        sscanf(rgb_str, "%d%d%d", &rgb_val.r, &rgb_val.g, &rgb_val.b);
        hex_val = hex_from_rgb(&rgb_val);

        printf("RGB: (%d, %d, %d)\n", rgb_val.r, rgb_val.g, rgb_val.b);
        printf("HEX: #%s%s%s\n", hex_val.hex, hex_val.hex + 2, hex_val.hex + 4);
    }

    return 0;
}