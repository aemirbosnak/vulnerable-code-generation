//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 16
#define MIN_PASSWORD_LENGTH 8

#define UPPER_CASE 0
#define LOWER_CASE 1
#define NUMBERS 2
#define SPECIAL_CHARS 3

int main(int argc, char *argv[]) {
    int num_players = 0;
    char *player_names[10];

    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    for(int i=0; i<num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", player_names[i]);
    }

    srand(time(NULL));
    int num_rounds = rand() % 3 + 1;

    printf("The game will consist of %d rounds.\n", num_rounds);

    for(int round=1; round<=num_rounds; round++) {
        printf("Round %d:\n", round);
        for(int i=0; i<num_players; i++) {
            int password_length = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH;
            char password[MAX_PASSWORD_LENGTH];

            printf("Player %s, your password must be %d characters long.\n", player_names[i], password_length);

            int num_chars = 0;
            while(num_chars < password_length) {
                int char_type = rand() % 4;

                if(char_type == UPPER_CASE) {
                    password[num_chars] = 'A' + rand() % 26;
                } else if(char_type == LOWER_CASE) {
                    password[num_chars] = 'a' + rand() % 26;
                } else if(char_type == NUMBERS) {
                    password[num_chars] = '0' + rand() % 10;
                } else {
                    password[num_chars] = rand() % 16 + 48;
                }

                num_chars++;
            }

            printf("Your password is: %s\n", password);
        }

        printf("\n");
    }

    return 0;
}