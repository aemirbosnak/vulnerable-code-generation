//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASS_LEN 100

int is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_special(char c) {
    return c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*';
}

int main() {
    srand(time(NULL));
    char password[MAX_PASS_LEN + 1];
    printf("Enter password length: ");
    scanf("%d", &password[0]);
    printf("Enter password complexity (1-3): ");
    scanf("%d", &password[1]);
    int length = password[0];
    int complexity = password[1];
    int num_alpha = 0;
    int num_digit = 0;
    int num_special = 0;
    int i = 2;
    while (i < length) {
        if (complexity & 1) {
            password[i] = 'a' + rand() % 26;
            num_alpha++;
        }
        if (complexity & 2) {
            password[i] = '0' + rand() % 10;
            num_digit++;
        }
        if (complexity & 4) {
            password[i] = "!@#$%&*";
            num_special++;
        }
        i++;
    }
    while (num_alpha < 2) {
        int index = rand() % length;
        if (is_alpha(password[index])) {
            password[index] = 'a' + rand() % 26;
            num_alpha++;
        }
    }
    while (num_digit < 2) {
        int index = rand() % length;
        if (is_digit(password[index])) {
            password[index] = '0' + rand() % 10;
            num_digit++;
        }
    }
    while (num_special < 2) {
        int index = rand() % length;
        if (is_special(password[index])) {
            password[index] = "!@#$%&*";
            num_special++;
        }
    }
    printf("Generated password: %s\n", password);
    return 0;
}