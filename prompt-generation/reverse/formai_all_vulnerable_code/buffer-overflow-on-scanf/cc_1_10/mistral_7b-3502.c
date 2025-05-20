//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void rgb_to_hex(int r, int g, int b) {
    int red = r;
    int green = g;
    int blue = b;

    int r_hex[2], g_hex[2], b_hex[2];

    r_hex[0] = red >> 4;
    r_hex[1] = red & 0xF;
    g_hex[0] = green >> 4;
    g_hex[1] = green & 0xF;
    b_hex[0] = blue >> 4;
    b_hex[1] = blue & 0xF;

    if (r_hex[0] < 10)
        printf("0%X", r_hex[0]);
    else
        printf("%X", r_hex[0]);

    if (r_hex[1] < 10)
        printf("0%X", r_hex[1]);
    else
        printf("%X", r_hex[1]);

    if (g_hex[0] < 10)
        printf("0%X", g_hex[0]);
    else
        printf("%X", g_hex[0]);

    if (g_hex[1] < 10)
        printf("0%X", g_hex[1]);
    else
        printf("%X", g_hex[1]);

    if (b_hex[0] < 10)
        printf("0%X", b_hex[0]);
    else
        printf("%X", b_hex[0]);

    if (b_hex[1] < 10)
        printf("0%X", b_hex[1]);
    else
        printf("%X", b_hex[1]);
}

int main() {
    int r, g, b;

    printf("Enter RGB values (separated by spaces): ");
    scanf("%d%d%d", &r, &g, &b);

    printf("\nThe hexadecimal color code for RGB(%d, %d, %d) is: ", r, g, b);
    rgb_to_hex(r, g, b);
    printf("\n");

    return 0;
}