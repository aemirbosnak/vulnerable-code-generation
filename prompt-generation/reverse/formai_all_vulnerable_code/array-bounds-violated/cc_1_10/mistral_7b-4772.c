//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: creative
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define MAX 1000
#define WORD_SIZE 5
#define SEED 1337
void sieve_init(bool *sieve, int limit) {
    for (int i = 0; i < limit; i++) {
        sieve[i] = true;
    }
    sieve[0] = false;
    sieve[1] = false;
}
void sieve_generate(bool *sieve, int limit) {
    for (int i = 2; i * i < limit; i++) {
        if (sieve[i]) {
            for (int j = i * i; j < limit; j += i) {
                sieve[j] = false;
            }
        }
    }
}
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    bool sieve[MAX];
    sieve_init(sieve, MAX);
    sieve_generate(sieve, MAX);
    return sieve[num];
}
void print_word(char *word) {
    printf("%s ", word);
    for (int i = 0; i < strlen(word); i++) {
        if (is_prime(word[i] - '0')) {
            printf("%c", word[i]);
        }
    }
    printf("\n");
}
int main() {
    srand(SEED);
    char words[WORD_SIZE][10];
    for (int i = 0; i < WORD_SIZE; i++) {
        strcpy(words[i], "");
        for (int j = 0; j < 5; j++) {
            int num = rand() % 10;
            words[i][j] = num + '0';
        }
        words[i][strlen(words[i])] = '\0';
        print_word(words[i]);
    }
    return 0;
}