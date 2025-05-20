//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define LOWER 97
#define UPPER 90
#define DIGIT 48
#define SPECIAL 32

void generate_password(char *password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        int type = rand() % 4;
        switch (type) {
            case 0:
                password[i] = (char) (rand() % 26 + LOWER);
                break;
            case 1:
                password[i] = (char) (rand() % 26 + UPPER);
                break;
            case 2:
                password[i] = (char) (rand() % 10 + DIGIT);
                break;
            case 3:
                password[i] = (char) (rand() % 33 + SPECIAL);
                break;
        }
    }
    password[length] = '\0';
}

int main(void) {
    srand(time(NULL));
    int length;
    char password[MAX_LENGTH + 1];

    printf("Enter password length between %d and %d: ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length, please try again.\n");
        return 1;
    }

    generate_password(password, length);
    printf("Generated password: %s\n", password);

    return 0;
}