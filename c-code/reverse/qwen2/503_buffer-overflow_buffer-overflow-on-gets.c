#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char name[100];
    char date[20];
    int secretCode;
    char alienType[50];
    float strength;

    printf("Enter your name: ");
    gets(name);
    printf("Enter the date: ");
    gets(date);
    printf("Enter the secret code: ");
    scanf("%d", &secretCode);
    getchar(); // Consume newline left-over
    printf("Enter the alien type: ");
    gets(alienType);
    printf("Enter the strength of the aliens: ");
    scanf("%f", &strength);

    printf("\nGreetings, %s! Based on your data from %s, with a secret code of %d, we predict a %s invasion with strength %.2f.\n", name, date, secretCode, alienType, strength);

    return 0;
}
