//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[20];
    int age;
    char gender;
    char card;
    int number;
    char suit;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I can predict your future based on your name, age, and gender.\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your gender (M/F): ");
    scanf(" %c", &gender);

    srand(time(NULL));
    number = rand() % 13 + 1;
    switch(number) {
        case 1:
            card = 'A';
            suit = 'C';
            break;
        case 2:
            card = '2';
            suit = 'C';
            break;
        case 3:
            card = '3';
            suit = 'C';
            break;
        case 4:
            card = '4';
            suit = 'C';
            break;
        case 5:
            card = '5';
            suit = 'C';
            break;
        case 6:
            card = '6';
            suit = 'C';
            break;
        case 7:
            card = '7';
            suit = 'C';
            break;
        case 8:
            card = '8';
            suit = 'C';
            break;
        case 9:
            card = '9';
            suit = 'C';
            break;
        case 10:
            card = '10';
            suit = 'C';
            break;
        case 11:
            card = 'J';
            suit = 'C';
            break;
        case 12:
            card = 'Q';
            suit = 'C';
            break;
        case 13:
            card = 'K';
            suit = 'C';
            break;
    }

    printf("Your fortune card is: %c of %c\n", card, suit);

    switch(gender) {
        case 'M':
            printf("As a man, your future is filled with success and prosperity.\n");
            break;
        case 'F':
            printf("As a woman, your future is filled with love and happiness.\n");
            break;
        default:
            printf("I cannot predict your future based on your gender.\n");
            break;
    }

    return 0;
}