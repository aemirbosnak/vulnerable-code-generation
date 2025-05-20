//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _CRYPTIC_SPEED_TEST_
#define MIN_CHARS 100
#define MAX_CHARS 255
#define SECRET_KEY "The quick brown fox jumps over the lazy dog"
#define ENCRYPTION_ALGORITHM(x) (((x) << 3) ^ (~((x) >> 5)))

typedef struct {
    char str[MAX_CHARS];
    size_t len;
} cryptic_string;

cryptic_string generate_random_string(size_t size) {
    cryptic_string str;
    size_t i;

    str.len = 0;

    for (i = 0; i < size; i++) {
        str.str[i] = rand() % (MAX_CHARS - MIN_CHARS + 1) + MIN_CHARS;
        str.len++;
    }

    str.str[str.len] = '\0';

    return str;
}

void print_string_reverse(const char* str) {
    size_t len = strlen(str);

    for (size_t i = len; i > 0; i--) {
        putchar(str[i - 1]);
    }
}

void encrypt_string(const cryptic_string* str, char* encrypted) {
    size_t i;

    for (i = 0; i < str->len; i++) {
        encrypted[i] = ENCRYPTION_ALGORITHM(str->str[i]);
    }

    encrypted[i] = '\0';
}

int main(void) {
#ifdef _CRYPTIC_SPEED_TEST_
    clock_t start, end;
#endif

#ifdef _CRYPTIC_SPEED_TEST_
    start = clock();
#endif

    srand(time(NULL));

    cryptic_string original = generate_random_string(MIN_CHARS);
    char encrypted[MAX_CHARS];

    encrypt_string(&original, encrypted);

#ifdef _CRYPTIC_SPEED_TEST_
    printf("Original String: ");
    puts(original.str);

    printf("Encrypted String: ");
    puts(encrypted);

    printf("Encryption Time: %fms\n", 1000 * ((double)(clock() - start)) / CLOCKS_PER_SEC);
#endif

#ifdef _CRYPTIC_SPEED_TEST_
    print_string_reverse(encrypted);
    printf("\n");
#endif

    free(original.str);

    return EXIT_SUCCESS;
}