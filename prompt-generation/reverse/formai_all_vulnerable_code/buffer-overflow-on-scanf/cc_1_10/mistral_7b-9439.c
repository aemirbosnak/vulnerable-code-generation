//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 40
#define HEIGHT 10

typedef struct {
    char name[20];
    int shock_level;
} Person;

void generate_shock(Person *person) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                putchar('*');
            } else if (person->shock_level > 5) {
                putchar('/');
            } else if (person->shock_level > 3) {
                putchar('o');
            } else if (person->shock_level > 0) {
                putchar('_');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

void calculate_shock_level(Person *person, char *input) {
    int length = strlen(input);
    int i;

    person->shock_level = 0;

    for (i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            person->shock_level += toupper(input[i]) - 'A' + 1;
        } else if (isspace(input[i])) {
            person->shock_level += 1;
        } else {
            person->shock_level += 3;
        }
    }
}

int main() {
    Person person;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    calculate_shock_level(&person, name);
    generate_shock(&person);

    return 0;
}

/* Shocked ASCII Art
**********************************************************
*                                                        *
*                                                        *
*                O                                       *
*                O                                       *
*        ________Oooooo___        ________Oooooo___       *
*       /       o          \     /       o          \     *
*      /        _|          \   /        _|          \   *
*     |_________|____________| /_________|____________| /   *
*                                                        *
*                                                        *
**********************************************************
*/