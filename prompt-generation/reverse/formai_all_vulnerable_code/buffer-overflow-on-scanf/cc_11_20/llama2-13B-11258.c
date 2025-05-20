//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int T, N, M;
    char S[100];

    // Problem 1: The Lost City
    printf("Welcome to the lost city of Cmathia!\n");
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        printf("Problem %d:\n", i + 1);
        scanf("%d", &N);
        printf("You have been given a map of the city with %d streets.\n", N);
        char street[100];
        scanf("%s", &street);
        int found = 0;
        for (int j = 0; j < N; j++) {
            if (street[j] == 'A' || street[j] == 'a') {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("The street does not exist in the city. Please try again.\n");
            continue;
        }
        int num = 0;
        for (int j = 0; j < N; j++) {
            if (street[j] == 'B' || street[j] == 'b') {
                num++;
            }
        }
        printf("The street has %d buildings.\n", num);
    }

    // Problem 2: The Magic Potion
    printf("You have been given a magic potion that can turn any number into a prime number.\n");
    scanf("%d", &M);
    int prime = 0;
    for (int i = 0; i < M; i++) {
        int num = rand() % 100;
        if (num == 42) {
            prime++;
        }
        if (prime == 5) {
            break;
        }
    }
    printf("You have found %d prime numbers in the magic potion.\n", prime);

    // Problem 3: The Cursed Forest
    printf("You have been given a map of a cursed forest with %d trees.\n", M);
    int found = 0;
    for (int i = 0; i < M; i++) {
        int tree = rand() % 100;
        if (tree == 42) {
            found++;
        }
        if (found == 5) {
            break;
        }
    }
    printf("You have found %d cursed trees in the forest.\n", found);

    return 0;
}