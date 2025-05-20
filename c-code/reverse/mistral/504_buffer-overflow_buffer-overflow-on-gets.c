#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 10

int main() {
    char name[MAX_NAME_LENGTH];
    int age, planet, invasion_probability;
    time_t t;

    printf("Enter your name: ");
    gets(name);

    if (strlen(name) > MAX_NAME_LENGTH) {
        printf("Name too long.\n");
        return 1;
    }

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age < 0) {
        printf("Age cannot be negative.\n");
        return 1;
    }

    printf("Enter the number of planets you've visited: ");
    scanf("%d", &planet);

    if (planet <= 0 || planet > 100) {
        printf("Invalid number of planets visited.\n");
        return 1;
    }

    if (age > 30 && planet > 5) {
        invasion_probability = 10;
    } else if (age > 20 && planet > 3) {
        invasion_probability = 8;
    } else if (age > 15 && planet > 2) {
        invasion_probability = 5;
    } else if (age > 10 && planet > 1) {
        invasion_probability = 3;
    } else {
        invasion_probability = 1;
    }

    printf("Your alien invasion probability is: %d\n", invasion_probability);

    return 0;
}
