//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MEWO "Mewow!"
#define FUR "Furry "
#define WHISKERS "Whiskers twitching!"
#define SHOCKED "Oh, my whiskers! I'm shocked!"
#define HUNGRY "Mew, I'm hungry!"

typedef struct cat {
    char name[20];
    int age;
    float weight;
} Cat;

void translate_meow(char *input) {
    int i, length = strlen(input);
    for (i = 0; i < length; i++) {
        if (input[i] == 'm' && (i < length - 1 && input[i+1] == 'e' && input[i+2] == 'w')) {
            printf(MEWO);
            i += 2;
        } else {
            printf("%c", input[i]);
        }
    }
}

void print_cat(Cat cat) {
    printf("%s is a %d-year-old cat weighing %.2f kg.\n", cat.name, cat.age, cat.weight);
}

int main() {
    char input[100];
    Cat my_cat = {"Whiskers", 5, 4.5};

    printf(FUR);
    printf(SHOCKED);
    printf("You said: ");

    scanf("%s", input);
    translate_meow(input);
    printf("\n");

    printf(SHOCKED);
    printf("Here's some info about my cat:");
    print_cat(my_cat);

    printf(HUNGRY);
    printf("Feeding time!\n");

    return 0;
}