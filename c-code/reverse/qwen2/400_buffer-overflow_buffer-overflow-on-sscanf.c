#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char input[10];
    int year, month, day, hour, minute, second;

    printf("Enter date and time (YYYY-MM-DD HH:MM:SS): ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second) != 6) {
        printf("Invalid input format.\n");
        return 1;
    }

    printf("Year: %d\nMonth: %d\nDay: %d\nHour: %d\nMinute: %d\nSecond: %d\n", year, month, day, hour, minute, second);

    // Intentionally leaving out bounds checking for demonstration purposes

    return 0;
}
