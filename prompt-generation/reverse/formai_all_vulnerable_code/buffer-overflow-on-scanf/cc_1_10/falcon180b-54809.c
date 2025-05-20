//Falcon-180B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char* password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    int charset_length = strlen(charset);

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }

    password[length] = '\0';
}

int main() {
    srand(time(NULL));

    char username[MAX_PASSWORD_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);

    int length = 0;
    while (length <= 0 || length > MAX_PASSWORD_LENGTH) {
        printf("Enter desired password length (1-%d): ", MAX_PASSWORD_LENGTH);
        scanf("%d", &length);
    }

    generate_password(passwords[num_passwords].password, length);
    passwords[num_passwords].length = length;
    num_passwords++;

    printf("Your password is: ");
    for (int i = 0; i < passwords[num_passwords-1].length; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}