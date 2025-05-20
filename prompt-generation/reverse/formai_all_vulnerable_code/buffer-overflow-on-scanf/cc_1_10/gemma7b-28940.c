//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define DELAY 1

void convert_units(int from, int to, int value) {
    switch (from) {
        case 0:
            switch (to) {
                case 0:
                    printf("The value is the same: %d\n", value);
                    break;
                case 1:
                    printf("The value is doubled: %d\n", value * 2);
                    break;
                case 2:
                    printf("The value is tripled: %d\n", value * 3);
                    break;
            }
            break;
        case 1:
            switch (to) {
                case 0:
                    printf("The value is halved: %d\n", value / 2);
                    break;
                case 1:
                    printf("The value is doubled: %d\n", value * 2);
                    break;
                case 2:
                    printf("The value is tripled: %d\n", value * 3);
                    break;
            }
            break;
        case 2:
            switch (to) {
                case 0:
                    printf("The value is one third: %d\n", value / 3);
                    break;
                case 1:
                    printf("The value is doubled: %d\n", value * 2);
                    break;
                case 2:
                    printf("The value is tripled: %d\n", value * 3);
                    break;
            }
            break;
    }
}

int main() {
    int from, to, value;

    printf("Enter the unit conversion factors:\n");
    printf("1. From (0, 1, 2): ");
    scanf("%d", &from);

    printf("2. To (0, 1, 2): ");
    scanf("%d", &to);

    printf("Enter the value: ");
    scanf("%d", &value);

    convert_units(from, to, value);

    sleep(DELAY);

    return 0;
}