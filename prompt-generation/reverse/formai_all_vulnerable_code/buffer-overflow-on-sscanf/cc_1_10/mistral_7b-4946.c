//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct { char str[MAX]; int len; } String;

void itob(int n, String s) {
    int i = 0;
    char c;

    do {
        c = '0' + (n % 10);
        s.str[i++] = c;
    } while ((n /= 10));

    s.str[i] = '\0';
    s.len = i;
}

int main(int argc, char **argv) {
    String a, b, c, d;
    int x, y, z;

    if (argc != 4) {
        printf("Usage: %s <integer1> <integer2> <integer3>\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%d", &x);
    sscanf(argv[2], "%d", &y);
    sscanf(argv[3], "%d", &z);

    itob(x, a);
    itob(y, b);
    itob(z, c);

    if (x + y > z) {
        printf("Error: %s + %s > %s\n", a.str, b.str, c.str);
        return 1;
    }

    strcpy(d.str, a.str);
    strncat(d.str, b.str, MAX - strlen(a.str) - strlen(b.str) - 1);

    printf("The sum of %s and %s is %s\n", a.str, b.str, d.str);

    free(argv);
    return 0;
}