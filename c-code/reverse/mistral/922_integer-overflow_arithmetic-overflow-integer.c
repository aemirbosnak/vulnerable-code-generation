#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    printf("Enter 21 integers:\n");

    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p, &q, &r, &s, &t, &u);

    v = a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + q + r + s + t + u;
    w = a * b * c * d * e * f * g * h * i * j * k * l * m * n * o * p * q * r * s * t * u;
    x = v + w;
    y = v * w;
    z = x + y;

    printf("Result 1: %d\n", x);
    printf("Result 2: %d\n", y);
    printf("Result 3: %d\n", z);

    return 0;
}
