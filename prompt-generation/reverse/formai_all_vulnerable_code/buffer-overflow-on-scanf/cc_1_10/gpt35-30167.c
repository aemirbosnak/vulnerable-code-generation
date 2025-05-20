//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

char generate_random_character() {
    char character_type;
    int random_integer;

    random_integer = rand() % 4;

    switch(random_integer) {
        case 0:
            character_type = 'A' + (rand() % 26);
            break;
        case 1:
            character_type = 'a' + (rand() % 26);
            break;
        case 2:
            character_type = '0' + (rand() % 10);
            break;
        case 3:
            character_type = '!' + (rand() % 14);
            break;
    }

    return character_type;
}

bool is_special_character(char character) {
    if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || (character >= '0' && character <= '9')) {
        return false;
    } else {
        return true;
    }
}

void generate_password(char *password, int length) {
    int i;
    char random_character;

    for (i = 0; i < length; i++) {
        random_character = generate_random_character();
        
        if (i == 0 && is_special_character(random_character)) {
            i--;
            continue;
        }

        password[i] = random_character;
    }

    password[i] = '\0';
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int password_length;

    srand(time(NULL));

    printf("Enter the length of the password (min %d, max %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Please try again.\n");
        return 1;
    }

    generate_password(password, password_length);

    printf("Your generated password is: %s\n", password);

    return 0;
}