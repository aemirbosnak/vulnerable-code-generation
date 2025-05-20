//Falcon-180B DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100

struct password {
    char *username;
    char *password;
    char *website;
};

int main() {
    char username[50];
    char password[50];
    char website[100];
    int i, j;
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    printf("Welcome to the surrealist password manager!\n");
    printf("Please enter your username:\n");
    scanf("%s", username);

    printf("Please enter your master password:\n");
    scanf("%s", password);

    srand(time(NULL));
    for (i = 0; i < strlen(password); i++) {
        password[i] = toupper(password[i]) - 'A' + rand() % 26 + 'A';
    }

    printf("Please enter a website and its corresponding password:\n");
    while (1) {
        printf("Website: ");
        scanf("%s", website);
        printf("Password: ");
        scanf("%s", password);

        if (strlen(password) == 0) {
            printf("Password cannot be empty.\n");
        } else {
            break;
        }
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    strcpy(passwords[num_passwords].website, website);
    num_passwords++;

    while (1) {
        printf("Do you want to add another password? (y/n): ");
        scanf(" %c", &j);
        if (j == 'n') {
            break;
        }

        printf("Please enter a website and its corresponding password:\n");
        while (1) {
            printf("Website: ");
            scanf("%s", website);
            printf("Password: ");
            scanf("%s", password);

            if (strlen(password) == 0) {
                printf("Password cannot be empty.\n");
            } else {
                break;
            }
        }

        strcpy(passwords[num_passwords].username, username);
        strcpy(passwords[num_passwords].password, password);
        strcpy(passwords[num_passwords].website, website);
        num_passwords++;
    }

    printf("Your passwords have been saved.\n");

    return 0;
}