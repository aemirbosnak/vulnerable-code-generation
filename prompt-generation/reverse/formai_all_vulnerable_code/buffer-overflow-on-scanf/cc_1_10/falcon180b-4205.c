//Falcon-180B DATASET v1.0 Category: Educational ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERB 100
#define MAX_NOUN 100

typedef struct {
    char verb[MAX_VERB];
    char noun[MAX_NOUN];
} sentence;

sentence generate_sentence(int is_question) {
    sentence s;
    char *verbs[] = {"is", "was", "became", "seemed", "appeared", "felt", "smelled", "tasted", "sounded", "looked"};
    char *nouns[] = {"love", "passion", "affection", "devotion", "adoration", "cherish", "treasure", "idolize", "worship", "revere"};

    s.verb[0] = '\0';
    s.noun[0] = '\0';

    if (is_question) {
        int rand_verb = rand() % 10;
        int rand_noun = rand() % 10;
        strcat(s.verb, verbs[rand_verb]);
        strcat(s.noun, nouns[rand_noun]);
        strcat(s.verb, " your ");
        strcat(s.verb, nouns[rand_noun]);
        strcat(s.verb, " for me? ");
    } else {
        int rand_verb = rand() % 10;
        int rand_noun = rand() % 10;
        strcat(s.verb, verbs[rand_verb]);
        strcat(s.verb, " ");
        strcat(s.verb, nouns[rand_noun]);
        strcat(s.verb, " me. ");
    }

    return s;
}

int main() {
    int choice;
    char input[100];

    printf("Welcome to the Love Letter Generator!\n");
    printf("Please choose an option:\n");
    printf("1. Generate a romantic sentence\n");
    printf("2. Generate a love letter\n");
    printf("3. Quit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter your name: ");
            scanf("%s", input);
            sentence s = generate_sentence(0);
            printf("%s, %s.\n", input, s.verb);
            break;
        case 2:
            printf("Enter your name: ");
            scanf("%s", input);
            printf("Dear %s,\n\n", input);
            for (int i = 0; i < 5; i++) {
                sentence s = generate_sentence(0);
                printf("%s\n", s.verb);
            }
            printf("\nForever yours,\nThe Love Letter Generator");
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}