//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int length, uppercase, lowercase, numbers, symbols;
    char password[25];
    printf("Enter length of password (1-25): ");
    scanf("%d", &length);
    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &uppercase);
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &lowercase);
    printf("Include numbers? (1 for yes, 0 for no): ");
    scanf("%d", &numbers);
    printf("Include symbols? (1 for yes, 0 for no): ");
    scanf("%d", &symbols);

    if (uppercase == 0 && lowercase == 0 && numbers == 0 && symbols == 0) {
        printf("Error: At least one type of character must be included.");
        return 0;
    }

    char uppercaseChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercaseChars[] = "abcdefghijklmnopqrstuvwxyz";
    char numberChars[] = "0123456789";
    char symbolChars[] = "!@#$%^&*()_+-={}[]|;:<>,.?/~`";

    int passwordIndex = 0;
    while (passwordIndex < length) {
        int randomType = rand() % 4;
        if (randomType == 0 && uppercase == 1) {
            password[passwordIndex] = uppercaseChars[rand() % 26];
            passwordIndex++;
        } else if (randomType == 1 && lowercase == 1) {
            password[passwordIndex] = lowercaseChars[rand() % 26];
            passwordIndex++;
        } else if (randomType == 2 && numbers == 1) {
            password[passwordIndex] = numberChars[rand() % 10];
            passwordIndex++;
        } else if (randomType == 3 && symbols == 1) {
            password[passwordIndex] = symbolChars[rand() % 26];
            passwordIndex++;
        }
    }
    password[length] = '\0';
    printf("Your randomly generated password is: %s", password);
    return 0;
}