#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void inputCandidateName(char *name) {
    printf("Enter candidate name: ");
    scanf("%s", name);
}

int main() {
    char candidateName[20];
    inputCandidateName(candidateName);
    printf("Candidate name: %s\n", candidateName);
    return 0;
}
