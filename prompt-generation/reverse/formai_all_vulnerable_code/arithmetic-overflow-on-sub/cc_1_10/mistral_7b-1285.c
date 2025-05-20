//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

typedef struct fib_seq {
    int64_t a, b;
} fib_seq;

void fib_init(fib_seq* fs) {
    fs->a = 0;
    fs->b = 1;
}

void fib_next(fib_seq* fs) {
    int64_t tmp = fs->a;
    fs->a = fs->b;
    fs->b = tmp + fs->b;
}

bool fib_is_valid(int64_t n) {
    fib_seq fs;
    fib_init(&fs);
    int i = 0;

    while (fs.b <= n) {
        fib_next(&fs);
        i++;
    }

    return i >= (int) (log10(n) / log10(2.0) + 1);
}

int64_t fib(int64_t n) {
    fib_seq fs;
    fib_init(&fs);

    while (n != 0) {
        if (fib_is_valid(n)) {
            int i = 0;
            while (fs.b < n) {
                fib_next(&fs);
                i++;
            }
            return fs.b;
        }
        int64_t tmp = fs.a;
        fs.a = fs.b;
        fs.b = tmp + fs.b;
        n--;
    }

    return 0;
}

int main() {
    int64_t n;

    printf("Enter a number: ");
    scanf("%" PRId64, &n);

    int64_t fib_num = fib(n);

    if (fib_num == 0) {
        printf("Invalid Fibonacci number\n");
    } else {
        printf("Fibonacci number %" PRId64 " = %" PRId64 "\n", n, fib_num);
    }

    return 0;
}