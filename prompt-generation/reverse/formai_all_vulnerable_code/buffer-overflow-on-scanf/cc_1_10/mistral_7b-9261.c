//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 16
#define MAX_LENGTH 32
#define CHAR_SET_SIZE 64

char char_set[CHAR_SET_SIZE] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  '!', '@', '#', '%', '&', '*', '(', ')', '_', '+', '=', '-', '>', '<', '?', '/', '\\', '|', '`', '{', '}', '[' ,']', ';', ':', '"', '\'', '.', ','
};

void init_rng() {
    unsigned long seed[4];
    FILE *rng_file = fopen("/dev/urandom", "r");
    fread(seed, sizeof(seed), 1, rng_file);
    fclose(rng_file);
    srand(seed[0] ^ seed[1] ^ seed[2] ^ seed[3]);
}

int random_char_index(int length) {
    return rand() % length;
}

void generate_password(char *password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        password[i] = char_set[random_char_index(CHAR_SET_SIZE)];
    }
    password[length] = '\0';
}

int main() {
    init_rng();

    char password[MAX_LENGTH + 1];
    int length;

    printf("Enter the desired password length (min 16, max 32): ");
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length. Exiting...\n");
        return 1;
    }

    generate_password(password, length);
    printf("Your secure password is: %s\n", password);

    return 0;
}