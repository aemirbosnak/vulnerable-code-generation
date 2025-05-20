#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void sanitize(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n' || str[i] == '<' || str[i] == '>') {
            str[i] = ' ';
        }
    }
}

int main() {
    char name[100], reason[200], quest[300];

    printf("Greetings! What is your name?\n");
    fgets(name, sizeof(name), stdin);
    sanitize(name);

    printf("Why are you here today?\n");
    fgets(reason, sizeof(reason), stdin);
    sanitize(reason);

    printf("What is your quest?\n");
    fgets(quest, sizeof(quest), stdin);
    sanitize(quest);

    printf("Farewell, %s. Your reason: '%s'. Your quest: '%s'.\n", name, reason, quest);

    return 0;
}
