#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[50];
    char reason[100];
    char quest[200];

    for (int i = 0; i < 3; ++i) {
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        for (int j = 0; name[j] != '\0'; ++j) {
            if (!isalnum(name[j]) && name[j] != '_' && name[j] != ' ') {
                name[j] = '_';
            }
        }
        printf("Hello, %s!\n", name);

        printf("Enter your reason for visiting: ");
        fgets(reason, sizeof(reason), stdin);
        for (int j = 0; reason[j] != '\0'; ++j) {
            if (reason[j] == '\n') {
                reason[j] = '\0';
                break;
            }
            if (!isalnum(reason[j]) && reason[j] != ' ') {
                reason[j] = '_';
            }
        }
        printf("Welcome, %s!\n", reason);

        printf("State your quest: ");
        fgets(quest, sizeof(quest), stdin);
        for (int j = 0; quest[j] != '\0'; ++j) {
            if (quest[j] == '\n') {
                quest[j] = '\0';
                break;
            }
            if (!isalnum(quest[j]) && quest[j] != ' ' && quest[j] != '_') {
                quest[j] = '_';
            }
        }
        printf("Your quest, %s, shall be honored.\n\n", quest);
    }

    printf("Farewell, traveler!\n");

    return 0;
}
