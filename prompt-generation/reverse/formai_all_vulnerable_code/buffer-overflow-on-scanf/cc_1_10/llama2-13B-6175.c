//LLAMA2-13B DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define CHOICE_COUNT 5

typedef enum {
    YES,
    NO,
    MAYBE
} choice_t;

typedef struct {
    char *name;
    choice_t choice;
} option_t;

option_t options[] = {
    {"Yes", YES},
    {"No", NO},
    {"Maybe", MAYBE},
    {"I don't know", YES},
    {"I don't care", YES}
};

int main() {
    srand(time(NULL));
    int i, j, random_index;
    char *user_input;

    printf("Welcome to the configurable C program!\n");

    do {
        printf("Please select an option (1-5): ");
        scanf("%d", &i);

        if (i < 1 || i > CHOICE_COUNT) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        random_index = rand() % CHOICE_COUNT;
        user_input = options[random_index].name;

        printf("Your selected option is: %s\n", user_input);
    } while (strcmp(user_input, "I don't know") != 0 && strcmp(user_input, "I don't care") != 0);

    return 0;
}