//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n, i, j, k, l, c, d, r, p, q, s, t, u, v, w, x, y, z;
    char a[1000], b[1000], e[1000], f[1000], g[1000], h[1000];
    scanf("%s", a);
    n = strlen(a);
    for (i = 0; i < n; i++) {
        b[i] = a[n - i - 1];
    }
    for (i = 0; i < n; i++) {
        c = 0;
        for (j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                c++;
            }
        }
        if (c == 1) {
            e[k] = a[i];
            k++;
        }
    }
    for (i = 0; i < k; i++) {
        d = 0;
        for (j = 0; j < n; j++) {
            if (e[i] == a[j]) {
                d++;
            }
        }
        f[l] = d;
        l++;
    }
    for (i = 0; i < l; i++) {
        for (j = 0; j < l; j++) {
            if (f[i] > f[j]) {
                r = f[i];
                f[i] = f[j];
                f[j] = r;
            }
        }
    }
    for (i = 0; i < l; i++) {
        for (j = 0; j < l; j++) {
            if (f[i] == f[j]) {
                p = 0;
                for (k = 0; k < k; k++) {
                    if (e[i] == e[k]) {
                        p++;
                    }
                }
                if (p == 1) {
                    g[q] = e[i];
                    q++;
                }
            }
        }
    }
    for (i = 0; i < q; i++) {
        for (j = 0; j < q; j++) {
            if (g[i] > g[j]) {
                s = g[i];
                g[i] = g[j];
                g[j] = s;
            }
        }
    }
    for (i = 0; i < q; i++) {
        h[t] = g[i];
        t++;
    }
    for (i = 0; i < t; i++) {
        printf("%c", h[i]);
    }
    printf("\n");
    return 0;
}