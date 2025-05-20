#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void vote(char name[100]) {
    printf("Voting for: %s\n", name);
}

int main() {
    char name[10];
    printf("Enter candidate name (up to 10 characters): ");
    scanf("%s", name);
    vote(name);
    return 0;
}
