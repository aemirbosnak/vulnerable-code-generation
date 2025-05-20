//FormAI DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
    char c = ' ';
    int r, g, b;

    printf("Enter color code in hexadecimal format: #");
    scanf("%c", &c);

    if (c >= '0' && c <= '9') {
        r = c - '0';
    } else if (c >= 'a' && c <= 'f') {
        r = c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
        r = c - 'A' + 10;
    } else {
        printf("Invalid color code.\n");
        exit(EXIT_FAILURE);
    }

    printf("Red: %d\n", r);

    printf("Enter color code in hexadecimal format: #");
    scanf("%c", &c);

    if (c >= '0' && c <= '9') {
        g = c - '0';
    } else if (c >= 'a' && c <= 'f') {
        g = c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
        g = c - 'A' + 10;
    } else {
        printf("Invalid color code.\n");
        exit(EXIT_FAILURE);
    }

    printf("Green: %d\n", g);

    printf("Enter color code in hexadecimal format: #");
    scanf("%c", &c);

    if (c >= '0' && c <= '9') {
        b = c - '0';
    } else if (c >= 'a' && c <= 'f') {
        b = c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
        b = c - 'A' + 10;
    } else {
        printf("Invalid color code.\n");
        exit(EXIT_FAILURE);
    }

    printf("Blue: %d\n", b);

    printf("RGB color code: (%d,%d,%d)\n", r, g, b);

    return 0;
}