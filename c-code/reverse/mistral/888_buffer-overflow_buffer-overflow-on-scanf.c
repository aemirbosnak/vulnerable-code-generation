#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void evaluatePasswordStrength(char password[]) {
    int uppercase = 0, lowercase = 0, digits = 0, special = 0, length = strlen(password);

    for (int i = 0; password[i]; ++i) {
        if (isupper(password[i])) ++uppercase;
        else if (islower(password[i])) ++lowercase;
        else if (isdigit(password[i])) ++digits;
        else ++special;
    }

    if (length < 8)
        printf("Weak\n");
    else if (length < 16 && (uppercase + lowercase + digits + special) < 4)
        printf("Medium\n");
    else if (length >= 16 && (uppercase + lowercase + digits + special) >= 4)
        printf("Strong\n");
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    evaluatePasswordStrength(password);
    return 0;
}
