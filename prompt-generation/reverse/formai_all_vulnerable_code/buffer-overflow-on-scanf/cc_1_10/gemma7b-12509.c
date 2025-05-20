//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct Knight {
    char name[MAX_PASSWORD_LENGTH];
    int strength;
} Knight;

Knight createKnight(char *name, int strength) {
    Knight knight;
    strcpy(knight.name, name);
    knight.strength = strength;
    return knight;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int passwordStrength = 0;

    printf("Welcome, traveler, to the Password Strength Checker!\n");
    printf("Please enter your password: ");
    scanf("%s", password);

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            passwordStrength++;
        }
        if (isdigit(password[i])) {
            passwordStrength++;
        }
        if (islower(password[i])) {
            passwordStrength++;
        }
    }

    Knight knight = createKnight("Sir Baldwin", passwordStrength);

    switch (knight.strength) {
        case 0:
            printf("Your password is as weak as a troll's underbelly. Prepare for a long night.\n");
            break;
        case 1:
            printf("Your password is as strong as a novice knight's blade. You might survive the night.\n");
            break;
        case 2:
            printf("Your password is as strong as a seasoned knight's armor. You are safe... for now.\n");
            break;
        case 3:
            printf("Your password is as strong as a dragon's fire. You are untouchable.\n");
            break;
        default:
            printf("Error: Invalid password strength.\n");
            break;
    }

    return 0;
}