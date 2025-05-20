//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int length;
    printf("Enter desired password length: ");
    scanf("%d", &length);

    char password[length+1];
    password[length] = '\0';

    int uppercase = rand() % 2;
    int lowercase = rand() % 2;
    int numbers = rand() % 2;
    int symbols = rand() % 2;

    if (uppercase) {
        password[0] = toupper(rand() % 26 + 'A');
    }
    else {
        password[0] = rand() % 26 + 'a';
    }

    int i;
    for (i = 1; i < length; i++) {
        int choice = rand() % 4;
        if (choice == 0 && uppercase) {
            password[i] = toupper(rand() % 26 + 'A');
        }
        else if (choice == 0 &&!uppercase) {
            password[i] = rand() % 26 + 'a';
        }
        else if (choice == 1 && lowercase) {
            password[i] = rand() % 26 + 'a';
        }
        else if (choice == 1 &&!lowercase) {
            password[i] = toupper(rand() % 26 + 'A');
        }
        else if (choice == 2 && numbers) {
            password[i] = rand() % 10 + '0';
        }
        else if (choice == 3 && symbols) {
            password[i] = "!@#$%^&*()_+";
        }
        else {
            password[i] = rand() % 26 + 'A';
        }
    }

    printf("Your password is: %s\n", password);

    return 0;
}