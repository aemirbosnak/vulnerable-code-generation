//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: futuristic
#include <stdio.h>
#include <string.h>

struct Cat {
    char name[20];
    int age;
    char breed[20];
    char color[20];
    char language[20];
};

int main() {
    struct Cat cat;
    char input[20];

    printf("Please input your cat's name: ");
    scanf("%s", cat.name);

    printf("Please input your cat's age: ");
    scanf("%d", &cat.age);

    printf("Please input your cat's breed: ");
    scanf("%s", cat.breed);

    printf("Please input your cat's color: ");
    scanf("%s", cat.color);

    printf("Please input your cat's preferred language: ");
    scanf("%s", cat.language);

    printf("Welcome %s to the C Cat Language Translator!\n", cat.name);

    printf("To exit the translator, type 'exit'\n");

    while (1) {
        printf("What would you like to translate to %s: \n", cat.language);
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) break;

        if (strcmp(input, "hello") == 0) printf("%s: Meow\n", cat.name);
        else if (strcmp(input, "food") == 0) printf("%s: Mew\n", cat.name);
        else if (strcmp(input, "sleep") == 0) printf("%s: Purr\n", cat.name);
        else if (strcmp(input, "play") == 0) printf("%s: Trill\n", cat.name);
        else if (strcmp(input, "scratch") == 0) printf("%s: Hiss\n", cat.name);
        else printf("%s: Meow\n", cat.name);
    }

    return 0;
}