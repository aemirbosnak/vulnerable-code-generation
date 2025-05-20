#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void timeTravel(char *input) {
    int year, month, day, hour, minute, second;
    char timezone[6];

    sscanf(input, "%d %d %d %d %d %d %s", &year, &month, &day, &hour, &minute, &second, timezone);

    printf("You have traveled to: %04d-%02d-%02d %02d:%02d:%02d %s\n", year, month, day, hour, minute, second, timezone);
}

int main() {
    char input[10];
    printf("Enter date and time (YYYY-MM-DD HH:MM:SS TZ): ");
    fgets(input, sizeof(input), stdin);
    timeTravel(input);

    return 0;
}
