//Falcon-180B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 50
#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_SPECIAL_CHARS "!@#$%^&*()"

typedef struct password {
    char *password;
    time_t last_updated;
} password;

void generate_password(password *p, int length) {
    char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char *special_chars = PASSWORD_SPECIAL_CHARS;
    int chars_length = strlen(chars) - 1;
    int special_chars_length = strlen(special_chars) - 1;

    p->password = malloc(length + 1);
    if (p->password == NULL) {
        printf("Error: Unable to allocate memory\n");
        exit(1);
    }

    srand(time(NULL));
    int rand_index;

    for (int i = 0; i < length; i++) {
        rand_index = rand() % (chars_length + special_chars_length) + 1;

        if (rand_index <= chars_length) {
            p->password[i] = chars[rand() % chars_length];
        } else {
            p->password[i] = special_chars[rand_index - chars_length - 1];
        }
    }

    p->password[length] = '\0';
    p->last_updated = time(NULL);
}

int main() {
    password p;
    int length;

    printf("Enter password length (must be between %d and %d): ", PASSWORD_MIN_LENGTH, PASSWORD_MAX_LENGTH);
    scanf("%d", &length);

    if (length < PASSWORD_MIN_LENGTH || length > PASSWORD_MAX_LENGTH) {
        printf("Error: Invalid password length\n");
        return 1;
    }

    generate_password(&p, length);
    printf("Generated password: %s\n", p.password);

    return 0;
}