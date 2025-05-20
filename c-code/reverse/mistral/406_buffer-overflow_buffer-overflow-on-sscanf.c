#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void time_travel(char *date) {
    char buffer[50];
    sscanf(date, "%s", buffer);
    printf("You have traveled to the year: %s\n", buffer);
}

int main() {
    char input[100];
    printf("Enter a date (YYYY-MM-DD): ");
    fgets(input, sizeof(input), stdin);
    time_travel(input);
    return 0;
}
