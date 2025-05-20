//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define CHAR_COUNT 32

const char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";

void generate_password(int length) {
    int i, index;
    char password[length + 1];

    for (i = 0; i < length; ++i) {
        index = rand() % CHAR_COUNT;
        password[i] = char_set[index];
    }
    password[length] = '\0';

    printf("Generated password: %s\n", password);
}

int main() {
    int length, seed, choice;

    printf("Welcome to the Secure Password Generator!\n");
    printf("This program generates a random password of specified length.\n");
    printf("Length: %d to %d characters\n", MIN_LENGTH, MAX_LENGTH);

    srand(time(NULL));

    do {
        printf("\nEnter desired password length: ");
        scanf("%d", &length);

        if (length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Invalid length! Please enter a length between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        }

    } while (length < MIN_LENGTH || length > MAX_LENGTH);

    do {
        printf("\nSet seed for random number generator (1 to enable, 0 to disable): ");
        scanf("%d", &seed);

        if (seed) {
            printf("Enter seed value: ");
            scanf("%d", &seed);
            srand(seed);
        }

    } while (seed < 0);

    generate_password(length);

    printf("\nDo you want to generate another password? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);

    if (choice) {
        main();
    }

    return 0;
}