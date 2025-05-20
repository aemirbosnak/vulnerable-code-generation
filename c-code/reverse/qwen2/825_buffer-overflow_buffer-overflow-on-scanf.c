#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define NAME_LEN 20

int main() {
    char candidate[NAME_LEN];
    printf("Enter candidate name: ");
    scanf("%s", candidate);
    printf("Candidate selected: %s\n", candidate);
    return 0;
}
