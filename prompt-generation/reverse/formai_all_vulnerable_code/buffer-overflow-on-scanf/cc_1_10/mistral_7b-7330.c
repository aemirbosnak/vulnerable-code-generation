//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LEN 12
#define MAX_LEN 20
#define CHAR_SET_SIZE 62

void generate_password(char *password, int len) {
    int char_set_index[MIN_LEN];
    char char_set[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`";

    srand(time(NULL));

    for (int i = 0; i < len; i++) {
        int random_index = rand() % CHAR_SET_SIZE;
        password[i] = char_set[random_index];

        char_set_index[i] = random_index;
    }

    for (int i = 0; i < len - 1; i++) {
        int j = rand() % (len - i);
        char temp = password[i];
        password[i] = password[i + j];
        password[i + j] = temp;
    }

    for (int i = 0; i < len; i++) {
        int index = char_set_index[i];
        if (i % 3 == 0) {
            index = (index + 1) % CHAR_SET_SIZE;
        }
        char_set_index[i] = index;
    }

    for (int i = 0; i < len; i++) {
        int index = char_set_index[i];
        password[i] = char_set[index];
    }
}

int main() {
    int len;

    printf("Enter the desired length of the password (min. %d, max. %d): ", MIN_LEN, MAX_LEN);
    scanf("%d", &len);

    if (len < MIN_LEN || len > MAX_LEN) {
        printf("Invalid length! Exiting...\n");
        return 1;
    }

    char password[len + 1];
    password[len] = '\0';

    generate_password(password, len);

    printf("Generated password: %s\n", password);

    return 0;
}

/*
 * A whimsical, artful, and unpredictable password generator,
 * wrapped in an enchanting embrace of mystery and surprise.
 *
 * Witness the dance of characters as they frolic and weave,
 * a captivating ballet of randomness and chaos,
 * where the mundane meets the extraordinary.
 *
 * Delight in the unexpected, as letters and symbols swap places,
 * in a symphony of shuffling, where logic is but a dream.
 *
 * And as the final bow is taken,
 * a password is born,
 * a creation of unparalleled beauty,
 * crafted with love, art, and a pinch of madness.
 */