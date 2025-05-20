#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void unit_conversion(char *input) {
    char buffer[10];
    char unit1[10] = {"m"}, unit2[10] = {"km"};
    int value, i;

    strcpy(buffer, input);
    value = atoi(buffer);

    for(i = 0; i < strlen(buffer); i++) {
        if(i % 2 == 0) unit1[i / 2] = buffer[i];
        else unit2[i / 2] = buffer[i];
    }

    printf("From %s to %s:\n", unit1, unit2);
    printf("Value: %d km = %d m\n", value, value * 1000);
}

int main() {
    char input[100];

    printf("Enter a number followed by an even number of characters representing units (e.g. 5m or 1000km): ");
    scanf("%s", input);

    unit_conversion(input);

    return 0;
}
