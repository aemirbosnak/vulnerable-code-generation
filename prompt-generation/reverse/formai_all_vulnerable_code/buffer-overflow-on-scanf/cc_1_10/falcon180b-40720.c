//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHARS 100
#define MAX_LEN 100

void generate_password(char* password, int length, int complexity);

int main(void) {
    int length, complexity;
    char password[MAX_CHARS];

    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    printf("Enter the desired complexity of the password (1-3): ");
    scanf("%d", &complexity);

    srand(time(NULL));
    generate_password(password, length, complexity);

    printf("Your password is: %s\n", password);

    return 0;
}

void generate_password(char* password, int length, int complexity) {
    int i;
    char ch;

    if (complexity == 1) {
        for (i = 0; i < length; i++) {
            password[i] = 'a' + rand() % 26;
        }
    } else if (complexity == 2) {
        for (i = 0; i < length; i++) {
            ch = rand() % 2? 'a' : 'A';
            password[i] = ch + rand() % 25;
        }
    } else if (complexity == 3) {
        for (i = 0; i < length; i++) {
            ch = rand() % 3? 'a' : 'A';
            password[i] = ch + rand() % 25;
        }
    } else {
        printf("Invalid complexity level\n");
        exit(1);
    }
}