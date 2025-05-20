//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 100
#define MIN_TEMP 0

typedef struct {
    char *name;
    int temp;
} Temperature;

int main() {
    int num_temps;
    Temperature temps[MAX_TEMP];

    printf("Enter number of temperatures to monitor: ");
    scanf("%d", &num_temps);

    if (num_temps > MAX_TEMP) {
        printf("Error: Maximum number of temperatures is %d.\n", MAX_TEMP);
        exit(1);
    }

    for (int i = 0; i < num_temps; i++) {
        printf("Enter name of temperature %d: ", i+1);
        scanf("%s", temps[i].name);

        printf("Enter initial temperature for %s: ", temps[i].name);
        scanf("%d", &temps[i].temp);
    }

    while (1) {
        for (int i = 0; i < num_temps; i++) {
            printf("%s: %d\n", temps[i].name, temps[i].temp);
        }

        printf("Press Enter to continue monitoring...\n");
        char input;
        scanf("%c", &input);

        if (input == '\n') {
            continue;
        } else if (input == 'q') {
            break;
        } else {
            printf("Invalid input. Please press Enter to continue or 'q' to quit.\n");
        }
    }

    return 0;
}