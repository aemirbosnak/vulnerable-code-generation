//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20

const char *char_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`";

void generate_password(int length) {
    int i, random_index;
    char password[length + 1];

    for (i = 0; i < length; i++) {
        random_index = rand() % (strlen(char_set) - 1);
        password[i] = char_set[random_index];
    }
    password[length] = '\0';

    printf("Generated password: %s\n", password);
}

int main() {
    int length, choice;

    printf("Welcome to the Secure Password Generator!\n");
    printf("-----------------------------------------\n");

    srand(time(NULL));

    while (1) {
        printf("\nEnter the desired password length (min %d, max %d): ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &length);

        if (length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Invalid length! Try again.\n");
            continue;
        }

        generate_password(length);

        printf("\nDo you want to generate another password? (1) Yes, (0) No: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }
    }

    return 0;
}