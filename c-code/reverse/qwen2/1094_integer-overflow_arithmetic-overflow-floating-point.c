#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void cmyk_to_rgb(float c, float m, float y, float k) {
    int r = (int)((1 - c) * (1 - k) * 255);
    int g = (int)((1 - m) * (1 - k) * 255);
    int b = (int)((1 - y) * (1 - k) * 255);

    printf("RGB: %d, %d, %d\n", r, g, b);
}

int main() {
    float c, m, y, k;

    while (1) {
        printf("Enter CMYK values (0-1): ");
        if (scanf("%f %f %f %f", &c, &m, &y, &k) != 4 || c < 0 || c > 1 || m < 0 || m > 1 || y < 0 || y > 1 || k < 0 || k > 1) {
            printf("Invalid input. Please enter values between 0 and 1.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        cmyk_to_rgb(c, m, y, k);
    }

    return 0;
}
