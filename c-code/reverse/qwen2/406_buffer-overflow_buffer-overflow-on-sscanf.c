#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char date[51];
    printf("Enter a date (DD-MM-YYYY): ");
    scanf("%s", date);
    printf("Date entered: %s\n", date);
    return 0;
}
