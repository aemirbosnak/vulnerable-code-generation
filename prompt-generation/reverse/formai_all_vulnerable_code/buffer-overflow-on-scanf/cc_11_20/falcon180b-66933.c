//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 8
#define UPPER_CASE 1
#define LOWER_CASE 2
#define NUMBER 4
#define SPECIAL_CHAR 8
#define TOTAL_POINTS 16

int check_password_strength(char* password);

int main() {
    char password[MAX_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);
    int strength = check_password_strength(password);
    printf("Password strength: %d\n", strength);
    return 0;
}

int check_password_strength(char* password) {
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        return 0;
    }
    int points = 0;
    int has_upper_case = 0;
    int has_lower_case = 0;
    int has_number = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                has_upper_case = 1;
            } else {
                has_lower_case = 1;
            }
        } else if (isdigit(c)) {
            has_number = 1;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '+' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == ':' || c == '\"' || c == '\'' || c == ',' || c == '.' || c == '/' || c == '?' || c == '|') {
            has_special_char = 1;
        }
        points++;
    }

    if (has_upper_case) {
        points += UPPER_CASE;
    }
    if (has_lower_case) {
        points += LOWER_CASE;
    }
    if (has_number) {
        points += NUMBER;
    }
    if (has_special_char) {
        points += SPECIAL_CHAR;
    }

    return points;
}