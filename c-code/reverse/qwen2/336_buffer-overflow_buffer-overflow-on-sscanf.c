#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char recipient[5];
    printf("Enter recipient email: ");
    scanf("%s", recipient);
    printf("Sending mail to %s\n", recipient);
    return 0;
}
