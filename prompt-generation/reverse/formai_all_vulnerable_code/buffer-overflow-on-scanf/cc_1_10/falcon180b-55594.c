//Falcon-180B DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_PASSWORDS 100

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password generatePassword(int length) {
    Password password;
    char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    int numChars = strlen(chars);
    int i;

    for (i = 0; i < length; i++) {
        password.password[i] = chars[rand() % numChars];
    }

    password.length = length;

    return password;
}

int main() {
    int numPasswords, i;
    Password *passwords;
    time_t seed;

    printf("Enter the number of passwords to generate: ");
    scanf("%d", &numPasswords);

    passwords = (Password *)malloc(numPasswords * sizeof(Password));

    srand(time(&seed));

    printf("Generating passwords...\n");
    for (i = 0; i < numPasswords; i++) {
        int length = rand() % MAX_PASSWORD_LENGTH + 8;
        passwords[i] = generatePassword(length);
        printf("Password %d: %s (%d characters)\n", i+1, passwords[i].password, passwords[i].length);
    }

    printf("\nPasswords generated:\n");
    for (i = 0; i < numPasswords; i++) {
        printf("Password %d: %s (%d characters)\n", i+1, passwords[i].password, passwords[i].length);
    }

    free(passwords);

    return 0;
}