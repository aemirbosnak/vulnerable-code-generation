//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Public key algorithm implementation in a funny style

typedef struct {
    int x;
    int y;
} Point;

Point add_points(Point p1, Point p2) {
    Point result;
    result.x = (p1.x + p2.x) % 1000000007;
    result.y = (p1.y + p2.y) % 1000000007;
    return result;
}

Point multiply_point(Point p, int n) {
    Point result;
    result.x = 1;
    result.y = 0;
    Point temp = p;
    while (n > 0) {
        if (n % 2 == 1) {
            result = add_points(result, temp);
        }
        temp = add_points(temp, temp);
        n /= 2;
    }
    return result;
}

int main() {
    int n, e, d, m, c, y;
    Point G, P;

    // Generate a random point G on the elliptic curve
    G.x = rand() % 1000000007;
    G.y = rand() % 1000000007;

    // Choose a random integer e
    e = rand() % 1000000007;

    // Calculate the corresponding point P
    P = multiply_point(G, e);

    // Print the public key (G, P)
    printf("Public key: (%d, %d), (%d, %d)\n", G.x, G.y, P.x, P.y);

    // Encryption
    scanf("%d", &m);
    m = m % 1000000007;
    c = multiply_point(G, m).x;

    // Decryption
    y = multiply_point(P, c).x;
    d = (y - 1) % 1000000007;
    m = (d * (d - 2)) % 1000000007;

    printf("Encrypted message: %d\n", c);
    printf("Decrypted message: %d\n", m);

    return 0;
}