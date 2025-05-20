//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MIN_PASSWORD_LEN 8
#define MAX_PASSWORD_LEN 20

int is_upper(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

int is_lower(char ch) {
    return (ch >= 'a' && ch <= 'z');
}

int is_digit(char ch) {
    return (ch >= '0' && ch <= '9');
}

int is_special_symbol(char ch) {
    return (!is_upper(ch) && !is_lower(ch) && !is_digit(ch));
}

void print_success(char *password) {
    printf("\n%s is a Strong Password!\n", password);
}

void print_fail(char *password, char *reason) {
    printf("\n%s is a Weak Password! Reason: %s\n", password, reason);
}

int main() {
    char password[MAX_PASSWORD_LEN+1];

    printf("Enter Password: ");
    scanf("%s", password);

    int len = strlen(password);

    if (len < MIN_PASSWORD_LEN || len > MAX_PASSWORD_LEN) {
        print_fail(password, "Password length must be between MIN and MAX length!");
        return 0;
    }

    int num_uc=0, num_lc=0, num_digits=0, num_symbols=0;
    for (int i=0; i<len; ++i) {
        char ch = password[i];
        if (is_upper(ch))
            num_uc++;
        else if (is_lower(ch))
            num_lc++;
        else if (is_digit(ch))
            num_digits++;
        else if (is_special_symbol(ch))
            num_symbols++;
    }

    if (num_uc && num_lc && num_digits && num_symbols)
        print_success(password);
    else
        print_fail(password, "Password must contain at least one uppercase letter, one lowercase letter, one digit and one special character!");

    return 0;
}