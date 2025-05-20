//Falcon-180B DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERNAME_LEN 32
#define MAX_PASSWORD_LEN 64
#define MAX_NUM_USERNAME_LEN 32
#define MAX_NUM_PASSWORD_LEN 64

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    int num_username[MAX_NUM_USERNAME_LEN];
    int num_password[MAX_NUM_PASSWORD_LEN];
} user_data;

void generate_password(char* password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        password[i] = rand() % 62 + 'a';
    }
    password[length] = '\0';
}

int main() {
    user_data user;
    char password[MAX_PASSWORD_LEN];
    int num_password[MAX_NUM_PASSWORD_LEN];
    int num_length;

    printf("Enter your username: ");
    scanf("%s", user.username);

    printf("Enter your desired password length: ");
    scanf("%d", &num_length);

    generate_password(password, num_length);
    printf("Your password is: %s\n", password);

    printf("Do you want to save this password? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("Enter the number of times you want to repeat this password: ");
        scanf("%d", &num_length);
        strcpy(user.password, password);
        strcpy(user.num_password, password);
        int i;
        for (i = 0; i < num_length; i++) {
            strcat(user.num_password, " ");
        }
        strcat(user.num_password, "\n");
        printf("Saved password: %s\n", user.num_password);
    }

    return 0;
}