#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void check_password(char password[10]) {
    int strength = 0;
    int i;

    if (strlen(password) < 6) {
        strength++;
    }

    for (i = 0; password[i]; i++) {
        if (!isalnum(password[i])) {
            strength++;
        }
    }

    if (strlen(password) > 12) {
        strength++;
    }

    if (strength < 3) {
        printf("Weak password.\n");
    } else if (strength == 3) {
        printf("Medium password.\n");
    } else {
        printf("Strong password.\n");
    }
}

int main() {
    char password[10];
    printf("Enter your password: ");
    scanf("%s", password);
    check_password(password);
    return 0;
}
