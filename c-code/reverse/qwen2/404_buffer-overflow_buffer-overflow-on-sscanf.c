#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char date[11];
    int year, month, day;

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);

    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3) {
        printf("Invalid date format.\n");
        return 1;
    }

    // Simulate time travel logic here

    return 0;
}
