#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char password[10];
    printf("Enter your password: ");
    scanf("%s", password);
    if (strlen(password) > 9) {
        printf("Password is too long!\n");
    } else {
        printf("Password is weak!\n");
    }
    return 0;
}
