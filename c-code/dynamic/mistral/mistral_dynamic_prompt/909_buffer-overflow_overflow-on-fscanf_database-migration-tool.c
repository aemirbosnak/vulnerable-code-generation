#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void parseData(char *data) {
    char name[20], table[25], column[30];
    int id;

    // Boundary check to demonstrate overflow
    if (fscanf(stdin, "%s %d %s%*c", name, &id, column) != 3) {
        printf("Invalid input format.\n");
        return;
    }

    printf("Name: %s\nID: %d\nColumn: %s\n", name, id, column);

    // Buffer overflow in column
    strcat(column, "New data");
}

int main() {
    char input[1000];

    printf("Enter data (format: name id column):\n");
    gets(input); // Insecure gets() usage for demonstration purposes only

    parseData(input);

    return 0;
}
