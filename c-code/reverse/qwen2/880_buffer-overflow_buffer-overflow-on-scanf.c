#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char password[10];
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Password entered: %s\n", password);
    return 0;
}
