//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MIN_LEN 8
#define DICT_FILE "dictionary.txt"

int score(char *password, int len) {
    int has_digit = 0, has_upper = 0, has_lower = 0, has_special = 0;
    int dict_score = 0;

    for (int i = 0; password[i]; i++) {
        if (isdigit(password[i])) has_digit = 1;
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (!isalnum(password[i])) {
            if (strchr("!@#$%^&*()_+-=[]{}|;:,.<>/?`~", password[i]))
                has_special = 1;
            continue;
        }
    }

    dict_score = len - (has_digit + (has_upper ? 1 : 0) + (has_lower ? 1 : 0) + (has_special ? 1 : 0));

    FILE *dict = fopen(DICT_FILE, "r");
    if (!dict) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    char word[32];
    while (fscanf(dict, "%s", word) == 1) {
        if (strcasestr(password, word)) {
            fclose(dict);
            return len - 1;
        }
    }

    fclose(dict);
    return len + dict_score;
}

int main() {
    char password[32];
    int len;

    printf("Enter a password (minimum length %d): ", MIN_LEN);
    scanf("%s", password);
    len = strlen(password);

    if (len < MIN_LEN) {
        printf("Password is too short. Minimum length is %d.\n", MIN_LEN);
        return EXIT_FAILURE;
    }

    int strength = score(password, len);
    printf("Password strength: %d\n", strength);

    if (strength < 0) {
        printf("Warning: Weak password! Do not use this password in real life.\n");
    } else if (strength <= 39) {
        printf("Password could be improved.\n");
    } else if (strength <= 69) {
        printf("Good password.\n");
    } else {
        printf("Strong password.\n");
    }

    return EXIT_SUCCESS;
}