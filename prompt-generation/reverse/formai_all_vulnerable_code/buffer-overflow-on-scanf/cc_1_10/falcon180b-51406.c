//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

Point add_points(Point p1, Point p2) {
    Point result;
    result.x = (p1.x * p2.y + p2.x * p1.y) % 1000000007;
    result.y = (p1.x * p2.x + p1.y * p2.y) % 1000000007;
    return result;
}

Point double_point(Point p) {
    Point result;
    result.x = (3 * p.x + 1) % 1000000007;
    result.y = (3 * p.y + 1) % 1000000007;
    return result;
}

void print_point(Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

void generate_key() {
    int x, y;
    do {
        x = rand() % 1000000007;
        y = rand() % 1000000007;
    } while (gcd(x, 1000000007) == 1);
    printf("Public key: (%d, %d)\n", x, y);
    printf("Private key: (%d, %d)\n", x, y);
}

int main() {
    srand(time(NULL));
    generate_key();
    Point public_key, private_key;
    public_key.x = 1;
    public_key.y = 0;
    private_key.x = 0;
    private_key.y = 1;
    Point message;
    printf("Enter message: ");
    scanf("%d %d", &message.x, &message.y);
    Point encrypted_message = add_points(message, public_key);
    Point decrypted_message = add_points(encrypted_message, private_key);
    print_point(decrypted_message);
    return 0;
}