//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 64
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_TRIES 10
#define MAX_PLAYERS 4

typedef struct {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
} Player;

void generatePassword(Player *player) {
    char password[MAX_PASSWORD_LENGTH];
    int passwordLength = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH;
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasNumber = 0;
    int hasSpecial = 0;

    for (int i = 0; i < passwordLength; i++) {
        char c = rand() % 62 + 'a';
        if (isupper(c)) {
            hasUppercase = 1;
        } else if (islower(c)) {
            hasLowercase = 1;
        } else if (isdigit(c)) {
            hasNumber = 1;
        } else {
            hasSpecial = 1;
        }
        password[i] = c;
    }

    if (!hasUppercase) {
        password[rand() % passwordLength] = toupper(password[rand() % passwordLength]);
    }
    if (!hasLowercase) {
        password[rand() % passwordLength] = tolower(password[rand() % passwordLength]);
    }
    if (!hasNumber) {
        password[rand() % passwordLength] = rand() % 10 + '0';
    }
    if (!hasSpecial) {
        password[rand() % passwordLength] = "!@#$%^&*()_+=-[]{}\\|;':\",./<>?"[rand() % 20];
    }

    strcpy(player->password, password);
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int numPlayers = 0;

    while (numPlayers < MAX_PLAYERS) {
        printf("Enter your username: ");
        scanf("%s", players[numPlayers].username);
        printf("Password generated: %s\n", players[numPlayers].password);
        numPlayers++;
    }

    return 0;
}