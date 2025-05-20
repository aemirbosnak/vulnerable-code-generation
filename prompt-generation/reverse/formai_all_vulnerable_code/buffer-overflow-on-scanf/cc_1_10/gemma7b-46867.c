//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define MAX_PASS_LENGTH 255

typedef struct PassStrength {
    int strength;
    char message[256];
} PassStrength;

PassStrength checkPasswordStrength(char *pass) {
    PassStrength ps;
    ps.strength = 0;
    ps.message[0] = '\0';

    if (strlen(pass) < 8) {
        strcat(ps.message, "Password too short!");
    } else if (strlen(pass) > MAX_PASS_LENGTH) {
        strcat(ps.message, "Password too long!");
    }

    if (!isalnum(pass[0])) {
        strcat(ps.message, "Weak first character!");
    }

    if (!strcmp(pass, strchr(pass, pass[0]))) {
        strcat(ps.message, "No repeated characters!");
    }

    for (int i = 0; i < strlen(pass); i++) {
        if (isupper(pass[i])) {
            ps.strength++;
        }
        if (islower(pass[i])) {
            ps.strength++;
        }
        if (isdigit(pass[i])) {
            ps.strength++;
        }
    }

    return ps;
}

int main() {
    char pass[MAX_PASS_LENGTH];
    printf("Enter your password: ");
    scanf("%s", pass);

    PassStrength ps = checkPasswordStrength(pass);

    if (ps.strength > 0) {
        printf("Password strength: %d\n", ps.strength);
        printf("Message: %s\n", ps.message);
    } else {
        printf("Error: Invalid password!\n");
    }

    return 0;
}