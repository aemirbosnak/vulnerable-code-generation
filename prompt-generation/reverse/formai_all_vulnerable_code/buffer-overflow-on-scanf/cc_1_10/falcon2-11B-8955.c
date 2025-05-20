//Falcon2-11B DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[100];
    char password[100];
    char email[100];
} User;

int isValidPassword(char password[100]) {
    int length = strlen(password);
    int upper = 0, lower = 0, digit = 0, special = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (isupper(c)) {
            upper++;
        } else if (islower(c)) {
            lower++;
        } else if (isdigit(c)) {
            digit++;
        } else {
            special++;
        }
    }

    if (upper >= 1 && lower >= 1 && digit >= 1 && special >= 1) {
        return 1;
    }

    return 0;
}

void generatePassword(char password[100]) {
    srand(time(NULL));

    int length = 8;
    char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    int i = 0;

    while (i < length) {
        int index = rand() % (sizeof(chars) - 1);
        password[i++] = chars[index];
    }
}

int main() {
    User user;

    printf("Enter your name: ");
    scanf("%s", user.name);

    printf("Enter your password (must be at least 8 characters with at least one uppercase letter, one lowercase letter, one digit, and one special character): ");
    char password[100];
    scanf("%s", password);

    if (isValidPassword(password)) {
        generatePassword(password);
    } else {
        printf("Invalid password.\n");
        return 1;
    }

    printf("Enter your email: ");
    scanf("%s", user.email);

    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(file, "%s,%s,%s\n", user.name, password, user.email);

    fclose(file);

    printf("Success! Your new password is: %s\n", password);

    printf("Thank you for using this program.\n");

    return 0;
}