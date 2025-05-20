//Gemma-7B DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PASSWD_LENGTH 16

char generate_password(int length) {
    char password[length];
    int i, seed, r;
    time_t t;

    t = time(NULL);
    seed = (int) t;
    srand(seed);

    for (i = 0; i < length; i++) {
        r = rand() % 3;
        switch (r) {
            case 0:
                password[i] = rand() % 26 + 97;
                break;
            case 1:
                password[i] = rand() % 10 + 48;
                break;
            case 2:
                password[i] = rand() % 32 + 32;
                break;
        }
    }

    return password[0];
}

int main() {
    char password[MAX_PASSWD_LENGTH];
    int length;

    printf("Enter the desired password length (maximum 16 characters): ");
    scanf("%d", &length);

    if (length > MAX_PASSWD_LENGTH) {
        printf("Error: Password length exceeds maximum limit.\n");
        return 1;
    }

    password[0] = generate_password(length);

    printf("Your generated password is: %s\n", password);

    return 0;
}