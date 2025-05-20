//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define LOWER 97
#define UPPER 90
#define NUMBER 48
#define SPECIAL 33

char *generate_password(int length) {
    int lower, upper, number, special;
    char *password;
    password = (char *)malloc(length + 1);

    srand(time(NULL));

    lower = rand() % 26;
    password[0] = (char)(LOWER + lower);

    for (int i = 1; i < length; i++) {
        int random_type = rand() % 4;

        if (random_type == 0) {
            lower = rand() % 26;
            password[i] = (char)(LOWER + lower);
        } else if (random_type == 1) {
            upper = rand() % 26;
            password[i] = (char)(UPPER + upper);
        } else if (random_type == 2) {
            number = rand() % 10;
            password[i] = (char)(NUMBER + number);
        } else {
            special = rand() % 33;
            password[i] = (char)(SPECIAL + special);
        }
    }

    password[length] = '\0';
    return password;
}

int main() {
    int length;
    char *password;

    printf("Enter the length of your password (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length! Password length must be between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    password = generate_password(length);
    printf("Your new password is: %s\n", password);
    free(password);

    return 0;
}