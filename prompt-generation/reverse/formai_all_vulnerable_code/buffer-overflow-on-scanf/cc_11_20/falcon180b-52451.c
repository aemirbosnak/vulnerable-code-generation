//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 8

int main() {
    int i, j, k, n, m, p, q, t, count = 0, r[N], c[N];
    char text[1000], watermark[1000];
    float alpha, beta, delta, gamma;

    printf("Enter the text: ");
    scanf("%[^\n]s", text);

    printf("Enter the watermark: ");
    scanf("%[^\n]s", watermark);

    m = strlen(text);
    n = strlen(watermark);

    for (i = 0; i < N; i++) {
        r[i] = rand() % 256;
        c[i] = rand() % 256;
    }

    for (i = 0; i < m; i++) {
        text[i] = toupper(text[i]);
    }

    for (i = 0; i < n; i++) {
        watermark[i] = toupper(watermark[i]);
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (text[i] == watermark[j]) {
                p = i;
                q = j;
                break;
            }
        }
    }

    for (i = 0; i < N; i++) {
        alpha = (float) r[i] / 256;
        beta = (float) c[i] / 256;
        delta = 0;
        gamma = 0;

        for (j = 0; j < m; j++) {
            if (j == p)
                continue;

            delta += (float) text[j] / 256 * alpha;
            gamma += (float) watermark[j] / 256 * beta;
        }

        t = 0;

        for (k = 0; k < n; k++) {
            if (k == q)
                continue;

            if (watermark[k] == text[p]) {
                t = 1;
                break;
            }
        }

        if (t == 1) {
            count++;
            for (j = 0; j < m; j++) {
                if (j == p)
                    continue;

                text[j] += round((delta - gamma) * 256);
            }
        }
    }

    printf("Watermarked text: %s\n", text);

    return 0;
}