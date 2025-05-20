#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_NAME_LENGTH 10

int main() {
    char candidate[MAX_NAME_LENGTH];
    printf("Enter candidate's name: ");
    scanf("%s", candidate);
    printf("Candidate's name is: %s\n", candidate);
    return 0;
}
