#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[32];
    int key;
} User;

void encrypt(User* user, int offset) {
    user->key += offset;
}

void decrypt(User* user, int offset) {
    user->key -= offset * 2;
}

void print_user(User* user) {
    printf("User: %s, Key: %d\n", user->name, user->key);
}

int main() {
    User bob = {"bob", 0};
    int i;

    for (i = 0; i < 100000; i++)
        encrypt(&bob, i);

    print_user(&bob);

    return 0;
}
