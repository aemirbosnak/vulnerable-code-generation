//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

#define MIN_LENGTH 8
#define MAX_TRIES 5
#define HASH_TABLE_SIZE 10000

typedef struct HashNode {
    char *password;
    int count;
    struct HashNode *next;
} HashNode;

HashNode *hash_table[HASH_TABLE_SIZE];

unsigned int hash_function(const char *str, int len) {
    unsigned int h = 0, i, charVal;
    for (i = 0; i < len; i++) {
        charVal = (unsigned char)str[i];
        h = (h * 31 + charVal) & (HASH_TABLE_SIZE - 1);
    }
    return h;
}

void add_password_to_hash_table(char *password) {
    unsigned int hash = hash_function(password, strlen(password));
    HashNode *newNode = (HashNode *)calloc(1, sizeof(HashNode));
    newNode->password = strdup(password);
    newNode->count = 1;
    if (hash_table[hash] != NULL) {
        HashNode *currentNode = hash_table[hash];
        while (currentNode->next != NULL && strcmp(currentNode->password, password) != 0) {
            currentNode = currentNode->next;
        }
        if (currentNode->password == password) {
            currentNode->count++;
            free(newNode);
            return;
        }
    }
    newNode->next = hash_table[hash];
    hash_table[hash] = newNode;
}

bool check_password_strength(char *password) {
    int length = strlen(password), upperCaseCount = 0, lowerCaseCount = 0, digitCount = 0, specialCharCount = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upperCaseCount++;
        } else if (islower(password[i])) {
            lowerCaseCount++;
        } else if (isdigit(password[i])) {
            digitCount++;
        } else {
            specialCharCount++;
        }
    }

    bool hasUpper = upperCaseCount > 0;
    bool hasLower = lowerCaseCount > 0;
    bool hasDigit = digitCount > 0;
    bool hasSpecialChar = specialCharCount > 0;

    bool isStrong = (length >= MIN_LENGTH)
                 && (hasUpper && hasLower && hasDigit && hasSpecialChar);

    if (!isStrong) {
        printf("Weak password: %s\n", password);
        printf("Password must be at least %d characters long and contain at least one uppercase letter, one lowercase letter, one digit and one special character.\n", MIN_LENGTH);
    } else {
        add_password_to_hash_table(password);
        printf("Strong password: %s\n", password);
    }

    return isStrong;
}

int main() {
    int tries = 0;
    char password[MIN_LENGTH + 1];

    while (tries < MAX_TRIES) {
        printf("Enter a password: ");
        scanf("%s", password);
        getchar(); // consume newline character
        check_password_strength(password);
        tries++;
    }

    printf("Maximum number of tries reached.\n");
    return 0;
}