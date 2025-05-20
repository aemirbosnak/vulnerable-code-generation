#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void rgbToCmyk(float r, float g, float b, float *c, float *m, float *y, float *k) {
    if (r > 1.0 || g > 1.0 || b > 1.0) {
        printf("Error: Input values must be within the range [0, 1].\n");
        return;
    }
    
    float max = (r > g) ? ((r > b) ? r : b) : ((g > b) ? g : b);
    *k = 1 - max;
    
    if (*k == 1) {
        *c = 0;
        *m = 0;
        *y = 0;
    } else {
        *c = (max - r) / (1 - *k);
        *m = (max - g) / (1 - *k);
        *y = (max - b) / (1 - *k);
    }
}

int main() {
    float r, g, b;
    printf("Enter RGB values (0-1): ");
    scanf("%f %f %f", &r, &g, &b);

    float c, m, y, k;
    rgbToCmyk(r, g, b, &c, &m, &y, &k);

    printf("CMYK values: %.2f %.2f %.2f %.2f\n", c, m, y, k);

    return 0;
}
