//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *generate_password(int length, int uppercase, int lowercase, int numbers, int symbols) {
    srand(time(NULL));

    char *password = malloc(length + 1);
    if (password == NULL) {
        return NULL;
    }

    int i;
    for (i = 0; i < length; i++) {
        int type = rand() % 4;

        switch (type) {
            case 0:
                if (uppercase) {
                    password[i] = 'A' + (rand() % 26);
                } else {
                    password[i] = 'a' + (rand() % 26);
                }
                break;
            case 1:
                if (lowercase) {
                    password[i] = 'a' + (rand() % 26);
                } else {
                    password[i] = 'A' + (rand() % 26);
                }
                break;
            case 2:
                if (numbers) {
                    password[i] = '0' + (rand() % 10);
                } else {
                    password[i] = 'A' + (rand() % 26);
                }
                break;
            case 3:
                if (symbols) {
                    password[i] = "!@#$%^&*()_+=-`~"[(rand() % 14)];
                } else {
                    password[i] = 'a' + (rand() % 26);
                }
                break;
        }
    }

    password[length] = '\0';

    return password;
}

int main() {
    int length, uppercase, lowercase, numbers, symbols;

    printf("Enter the length of the password you want to generate: ");
    scanf("%d", &length);

    printf("Do you want uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &uppercase);

    printf("Do you want lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &lowercase);

    printf("Do you want numbers? (1 for yes, 0 for no): ");
    scanf("%d", &numbers);

    printf("Do you want symbols? (1 for yes, 0 for no): ");
    scanf("%d", &symbols);

    char *password = generate_password(length, uppercase, lowercase, numbers, symbols);
    if (password == NULL) {
        printf("Error allocating memory for password.\n");
        return 1;
    }

    printf("Your password is: %s\n", password);

    free(password);
    return 0;
}