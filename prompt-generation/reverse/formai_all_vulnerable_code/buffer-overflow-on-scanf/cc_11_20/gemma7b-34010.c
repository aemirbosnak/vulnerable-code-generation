//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[1000], b[1000], c[1000], d[1000], e[1000], f[1000], g[1000], h[1000], x, y, z, o, p, q, r, s, t, u, v, w, h_o, h_p, h_r, h_s, h_t, h_u, h_w, n_o, n_p, n_r, n_s, n_t, n_u, n_w, mem[1000], mem_o, mem_p, mem_r, mem_s, mem_t, mem_u, mem_w, mem_h, mem_n, mem_h_o, mem_h_p, mem_h_r, mem_h_s, mem_h_t, mem_h_u, mem_h_w, mem_n_o, mem_n_p, mem_n_r, mem_n_s, mem_n_t, mem_n_u, mem_n_w;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        b[i] = a[i] & 0x3F;
    }

    for (i = 0; i < n; i++)
    {
        c[i] = (a[i] >> 6) & 0x3F;
    }

    for (i = 0; i < n; i++)
    {
        d[i] = (a[i] >> 12) & 0x3F;
    }

    for (i = 0; i < n; i++)
    {
        e[i] = (a[i] >> 18) & 0x3F;
    }

    for (i = 0; i < n; i++)
    {
        f[i] = a[i] ^ 0x3F;
    }

    for (i = 0; i < n; i++)
    {
        g[i] = a[i] & 0x1F;
    }

    for (i = 0; i < n; i++)
    {
        h[i] = a[i] & 0x0F;
    }

    for (i = 0; i < n; i++)
    {
        x = (a[i] >> 8) & 0x3F;
        y = a[i] & 0xFF;
        z = x | y;
        c[i] = z;
    }

    for (i = 0; i < n; i++)
    {
        o = (a[i] >> 16) & 0x3F;
        p = a[i] & 0xFFFF;
        q = o | p;
        d[i] = q;
    }

    for (i = 0; i < n; i++)
    {
        r = (a[i] >> 24) & 0x3F;
        s = a[i] & 0x7FFFFF;
        t = r | s;
        e[i] = t;
    }

    for (i = 0; i < n; i++)
    {
        u = (a[i] >> 32) & 0x3F;
        v = a[i] & 0xFFFFFFFF;
        w = u | v;
        f[i] = w;
    }

    return 0;
}