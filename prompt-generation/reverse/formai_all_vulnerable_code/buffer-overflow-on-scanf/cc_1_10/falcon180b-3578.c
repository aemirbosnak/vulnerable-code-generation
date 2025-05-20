//Falcon-180B DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
void generate_password(char *, int);
int check_password_strength(char *);
int main(void) {
    char password[100];
    int length, strength;

    printf("Welcome to the Password Generator!\n");
    printf("How long should your password be? (between 8 and 100 characters): ");
    scanf("%d", &length);

    if (length < 8 || length > 100) {
        printf("Invalid password length. Please enter a value between 8 and 100.\n");
        return 1;
    }

    printf("How strong should your password be? (between 1 and 5, 5 being strongest): ");
    scanf("%d", &strength);

    if (strength < 1 || strength > 5) {
        printf("Invalid password strength. Please enter a value between 1 and 5.\n");
        return 1;
    }

    generate_password(password, length);
    printf("\nYour password is: %s\n", password);
    printf("Password strength: %d/5\n", check_password_strength(password));

    return 0;
}

void generate_password(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    const int charset_size = strlen(charset);
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_size];
    }

    password[length] = '\0';
}

int check_password_strength(char *password) {
    int strength = 0;

    if (strlen(password) >= 8) {
        strength++;
    }

    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") > 0) {
        strength++;
    }

    if (strspn(password, "abcdefghijklmnopqrstuvwxyz") > 0) {
        strength++;
    }

    if (strspn(password, "0123456789") > 0) {
        strength++;
    }

    if (strspn(password, "!@#$%^&*()_+") > 0) {
        strength++;
    }

    return strength;
}