//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random password
char* generate_password(int length) {
    char* password = (char*)malloc(length + 1);
    if (password == NULL) {
        printf("Error: Unable to allocate memory for password.\n");
        exit(1);
    }

    // Define character sets
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char special_characters[] = "!@#$%^&*()_+";

    // Initialize character sets
    char* character_sets[] = {uppercase_letters, lowercase_letters, numbers, special_characters};

    // Initialize random seed
    srand(time(NULL));

    // Generate password
    int i;
    for (i = 0; i < length; i++) {
        int random_set = rand() % 4;
        password[i] = character_sets[random_set][rand() % strlen(character_sets[random_set])];
    }
    password[length] = '\0';

    return password;
}

int main() {
    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    char** passwords = (char**)malloc(num_players * sizeof(char*));
    if (passwords == NULL) {
        printf("Error: Unable to allocate memory for passwords.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < num_players; i++) {
        int password_length;
        printf("Enter password length for player %d: ", i+1);
        scanf("%d", &password_length);

        char* password = generate_password(password_length);
        passwords[i] = password;

        printf("Password for player %d: %s\n", i+1, password);
    }

    free(passwords);

    return 0;
}