//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 32

void generate_password(char *password, int length) {
    int i;
    char ch;
    for (i = 0; i < length; i++) {
        ch = rand() % 94 + 33; // ASCII characters from 33 to 126
        password[i] = ch;
    }
    password[length] = '\0';
}

int main() {
    char password[MAX_LENGTH];
    int length;
    char choice;

    srand(time(NULL));

    do {
        printf("Enter password length (between 8 and %d): ", MAX_LENGTH - 1);
        scanf("%d", &length);
        if (length < 8 || length > MAX_LENGTH - 1) {
            printf("Invalid password length.\n");
        }
    } while (length < 8 || length > MAX_LENGTH - 1);

    printf("Enter password complexity level:\n");
    printf("1. Lowercase letters only\n");
    printf("2. Lowercase and uppercase letters\n");
    printf("3. Lowercase letters, uppercase letters, and numbers\n");
    printf("4. Lowercase letters, uppercase letters, numbers, and special characters\n");
    scanf("%c", &choice);

    switch (choice) {
        case '1':
            generate_password(password, length);
            break;
        case '2':
            generate_password(password, length);
            break;
        case '3':
            generate_password(password, length);
            break;
        case '4':
            generate_password(password, length);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("Generated password: %s\n", password);

    return 0;
}