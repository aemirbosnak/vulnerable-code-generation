#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void sanitize(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '<' || str[i] == '>' || str[i] == '&') {
            str[i] = ' ';
        }
    }
}

int main() {
    char name[51], hobby[51], food[51];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    sanitize(name);

    printf("Enter your hobby: ");
    fgets(hobby, sizeof(hobby), stdin);
    sanitize(hobby);

    printf("Enter your favorite food: ");
    fgets(food, sizeof(food), stdin);
    sanitize(food);

    printf("Welcome, %s! Your hobby is %s, and you love eating %s.\n", name, hobby, food);

    return 0;
}
