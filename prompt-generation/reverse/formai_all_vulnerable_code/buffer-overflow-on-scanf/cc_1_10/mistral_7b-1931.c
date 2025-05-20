//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 10
#define MAX_LENGTH 30

void generatePassword(char *password, int length) {
    int set1, set2, set3, set4, set5;

    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char special[] = "!@#$%^&*()_+-={[}]:;<>,.?/~`";
    char symbols[] = "|\\/";

    set1 = rand() % 2;
    set2 = rand() % 2;
    set3 = rand() % 2;
    set4 = rand() % 2;
    set5 = rand() % 2;

    if (set1)
        strcat(password, lowercase);
    if (set2)
        strcat(password, uppercase);
    if (set3)
        strcat(password, digits);
    if (set4)
        strcat(password, special);
    if (set5)
        strcat(password, symbols);

    for (int i = strlen(lowercase); i < length; i++) {
        int charSet = rand() % 5;

        switch (charSet) {
            case 0:
                password[i] = lowercase[rand() % strlen(lowercase)];
                break;
            case 1:
                password[i] = uppercase[rand() % strlen(uppercase)];
                break;
            case 2:
                password[i] = digits[rand() % strlen(digits)];
                break;
            case 3:
                password[i] = special[rand() % strlen(special)];
                break;
            case 4:
                password[i] = symbols[rand() % strlen(symbols)];
                break;
        }
    }

    password[length] = '\0';
}

int main() {
    srand(time(NULL));

    int length;
    printf("Enter password length (min %d, max %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid password length.\n");
        return 1;
    }

    char password[MAX_LENGTH + 1];
    generatePassword(password, length);

    printf("Generated password: %s\n", password);

    return 0;
}