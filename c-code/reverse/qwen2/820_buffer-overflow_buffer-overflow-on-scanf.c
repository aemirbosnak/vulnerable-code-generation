#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_NAME_LENGTH 10

int main() {
    char candidate1[MAX_NAME_LENGTH], candidate2[MAX_NAME_LENGTH];
    char voterName[MAX_NAME_LENGTH];

    printf("Enter name of candidate 1: ");
    scanf("%s", candidate1);
    printf("Enter name of candidate 2: ");
    scanf("%s", candidate2);

    printf("Enter your name: ");
    scanf("%s", voterName);

    printf("Voting for %s\n", voterName);

    return 0;
}
