#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    char name[10];
    char key[50];
} User;

void encrypt(User* user) {
    char input;
    int i;

    printf("Enter key (min 10 chars): ");
    fscanf(stdin, "%s", user->key); // Buffer overflow vulnerability here

    for (i = 0; user->key[i] != '\0'; i++) {
        input = user->key[i] + 3;
        user->key[i] = (char)(input > 122 ? input - 26 : input);
    }
}

int main() {
    User* user = malloc(sizeof(User));
    encrypt(user);
    printf("Encrypted key: %s\n", user->key);
    free(user);
    return 0;
}
