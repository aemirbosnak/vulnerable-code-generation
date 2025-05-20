//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISHES 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char dish[MAX_NAME_LENGTH];
} noble;

noble dishes[MAX_DISHES];
int num_dishes = 0;

void add_dish(char *name, char *dish) {
    if (num_dishes >= MAX_DISHES) {
        printf("The Round Table Feast cannot accommodate more dishes!\n");
        return;
    }

    strcpy(dishes[num_dishes].name, name);
    strcpy(dishes[num_dishes].dish, dish);
    num_dishes++;
}

void display_dishes() {
    int i;

    printf("\nDishes at the Round Table Feast:\n");
    for (i = 0; i < num_dishes; i++) {
        printf("Noble %s brought %s\n", dishes[i].name, dishes[i].dish);
    }
}

int main() {
    char name[MAX_NAME_LENGTH], dish[MAX_NAME_LENGTH];

    while (1) {
        printf("\nWelcome noble, what is your name?\n");
        scanf("%s", name);
        printf("What scrumptious dish have you brought to the feast, noble %s?\n", name);
        scanf("%s", dish);

        add_dish(name, dish);

        printf("Thank you, noble %s, for contributing to the grand feast!\n", name);
        printf("Would you like to add another dish? Y for Yes, N for No.\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'N') {
            break;
        }
    }

    display_dishes();

    return 0;
}