//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{

    char *address;
    char *mask;
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    unsigned long int a, b, c, d;
    unsigned int e, f, g, h;

    if (argc != 3) 
    {
        printf("Usage: %s <address> <mask>\n", argv[0]);
        exit(1);
    }

    address = argv[1];
    mask = argv[2];

    sscanf(address, "%d.%d.%d.%d", &a, &b, &c, &d);
    sscanf(mask, "%d.%d.%d.%d", &e, &f, &g, &h);

    printf("Address:\t%d.%d.%d.%d\n", a, b, c, d);
    printf("Mask:\t\t%d.%d.%d.%d\n", e, f, g, h);

    a = a & e;
    b = b & f;
    c = c & g;
    d = d & h;

    printf("Network:\t%d.%d.%d.%d\n", a, b, c, d);

    a = ~e;
    b = ~f;
    c = ~g;
    d = ~h;

    a = a & b;
    b = a & c;
    c = b & d;

    printf("Broadcast:\t%d.%d.%d.%d\n", a, b, c, d);

    if (h == 0) 
    {
        printf("Wildcard:\t255.255.255.255\n");
    } else if (h == 255) 
    {
        printf("Wildcard:\t0.0.0.0\n");
    } else 
    {
        printf("Wildcard:\t%d.%d.%d.%d\n", a, b, c, d);
    }


    return 0;
}