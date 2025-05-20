//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    char password[256];
    int strength = 0;
    FILE *fp;

    printf("Shocked Password Strength Checker!\n");
    printf("Enter your password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < 8)
    {
        strength = strength - 10;
    }

    // Check for uppercase letter
    if (strchr(password, 'A') || strchr(password, 'B') || strchr(password, 'C') || strchr(password, 'D') || strchr(password, 'E') || strchr(password, 'F') || strchr(password, 'G') || strchr(password, 'H') || strchr(password, 'I') || strchr(password, 'J') || strchr(password, 'K') || strchr(password, 'L') || strchr(password, 'M') || strchr(password, 'N') || strchr(password, 'O') || strchr(password, 'P') || strchr(password, 'Q') || strchr(password, 'R') || strchr(password, 'S') || strchr(password, 'T') || strchr(password, 'U') || strchr(password, 'V') || strchr(password, 'W') || strchr(password, 'X') || strchr(password, 'Y') || strchr(password, 'Z'))
    {
        strength = strength - 20;
    }

    // Check for number
    if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') || strchr(password, '3') || strchr(password, '4') || strchr(password, '5') || strchr(password, '6') || strchr(password, '7') || strchr(password, '8') || strchr(password, '9'))
    {
        strength = strength - 30;
    }

    // Check for special character
    if (strchr(password, '$') || strchr(password, '%') || strchr(password, '&') || strchr(password, ')') || strchr(password, '*') || strchr(password, '+') || strchr(password, ',') || strchr(password, '-'))
    {
        strength = strength - 40;
    }

    // Write password strength to file
    fp = fopen("password_strength.txt", "w");
    fprintf(fp, "Your password strength is: %d", strength);
    fclose(fp);

    // Print password strength
    printf("Your password strength is: %d", strength);
    printf("\n");
    printf("Shocked, but I'm glad you chose a strong password!");

    return 0;
}