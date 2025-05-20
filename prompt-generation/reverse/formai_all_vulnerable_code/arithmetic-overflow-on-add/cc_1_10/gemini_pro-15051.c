//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LEN 20

char *generate_password(int len) {
    char *password = malloc(len + 1);
    if (!password) {
        return NULL;
    }

    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        int type = rand() % 4;
        switch (type) {
            case 0:
                password[i] = 'a' + (rand() % 26);
                break;
            case 1:
                password[i] = 'A' + (rand() % 26);
                break;
            case 2:
                password[i] = '0' + (rand() % 10);
                break;
            case 3:
                password[i] = "!@#$%^&*()_+=-`~";
                break;
        }
    }

    password[len] = '\0';
    return password;
}

int main() {
    int len;

    printf("Enter the length of the password: ");
    scanf("%d", &len);

    char *password = generate_password(len);
    if (!password) {
        printf("Error generating password.\n");
        return 1;
    }

    printf("Your password is: %s\n", password);
    free(password);

    return 0;
}