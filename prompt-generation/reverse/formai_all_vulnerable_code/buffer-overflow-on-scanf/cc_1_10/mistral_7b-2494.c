//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INGREDIENTS 10
#define MAX_NAME_LENGTH 20
#define MAX_QUANTITY 100

struct ingredient {
    char name[MAX_NAME_LENGTH];
    int quantity;
};

void sanitize_string(char *str) {
    int i, len;
    len = strlen(str);

    for (i = 0; i < len; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            str[i] = '\0';
        }
    }
}

int main() {
    int num_ingredients = 0;
    struct ingredient ingredients[MAX_INGREDIENTS];

    printf("Welcome to the Magical Potion Shop!\n");
    printf("Please enter your name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    sanitize_string(name);
    printf("Hello, %s! Let's create your magical potion.\n", name);

    while (num_ingredients < MAX_INGREDIENTS) {
        printf("Enter the name of the %d ingredient (or 'done' to finish): ", num_ingredients + 1);
        char ingredient_name[MAX_NAME_LENGTH];
        scanf("%s", ingredient_name);
        sanitize_string(ingredient_name);

        if (strcmp(ingredient_name, "done") == 0) {
            break;
        }

        bool valid_ingredient = false;
        for (int i = 0; i < num_ingredients; i++) {
            if (strcmp(ingredient_name, ingredients[i].name) == 0) {
                printf("Error: You already added %s to the potion!\n", ingredient_name);
                valid_ingredient = true;
                break;
            }
        }

        if (!valid_ingredient) {
            printf("Enter the quantity of %s: ", ingredient_name);
            int quantity;
            scanf("%d", &quantity);
            if (quantity > MAX_QUANTITY) {
                printf("Error: Quantity cannot exceed %d.\n", MAX_QUANTITY);
                continue;
            }

            strcpy(ingredients[num_ingredients].name, ingredient_name);
            ingredients[num_ingredients].quantity = quantity;
            num_ingredients++;
        }
    }

    printf("\nYour magical potion contains the following ingredients:\n");
    for (int i = 0; i < num_ingredients; i++) {
        printf("%s: %d\n", ingredients[i].name, ingredients[i].quantity);
    }

    printf("\nThank you, %s! Your magical potion is ready.\n", name);

    return 0;
}