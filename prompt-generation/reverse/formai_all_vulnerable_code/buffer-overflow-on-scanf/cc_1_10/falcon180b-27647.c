//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

enum {
    SMALL = 1,
    MEDIUM = 2,
    LARGE = 3
};

struct item {
    char *name;
    int size;
    float price;
};

void display_menu(struct item menu[]) {
    printf("Welcome to the Cafe!\n");
    printf("Our menu:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s (%d oz) - $%.2f\n", i+1, menu[i].name, menu[i].size, menu[i].price);
    }
}

int get_choice(char *prompt) {
    int choice;
    do {
        printf("%s", prompt);
        scanf("%d", &choice);
    } while (choice < 1 || choice > 3);
    return choice;
}

float calculate_total(int choice, struct item menu[]) {
    float total = 0.0;
    switch (choice) {
        case SMALL:
            total = menu[0].price;
            break;
        case MEDIUM:
            total = menu[1].price;
            break;
        case LARGE:
            total = menu[2].price;
            break;
    }
    return total;
}

void print_receipt(float total) {
    printf("\nYour total is: $%.2f\n", total);
}

int main() {
    struct item menu[] = {{"Small Coffee", SMALL, 2.50},
                         {"Medium Coffee", MEDIUM, 3.00},
                         {"Large Coffee", LARGE, 3.50}};

    display_menu(menu);

    int choice = get_choice("Choose an item: ");
    float total = calculate_total(choice, menu);

    print_receipt(total);

    return 0;
}