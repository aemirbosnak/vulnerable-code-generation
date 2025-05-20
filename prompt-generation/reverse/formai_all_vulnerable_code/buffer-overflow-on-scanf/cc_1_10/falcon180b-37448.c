//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    double (*convert)(double);
} Unit;

double length(double value) {
    return value;
}

double weight(double value) {
    return value * 2.20462;
}

double volume(double value) {
    return value * 3.78541;
}

Unit units[] = {
    {"Length", length},
    {"Weight", weight},
    {"Volume", volume}
};

int main() {
    int choice, count = 0;
    double value;

    printf("Unit Converter\n");

    for (count = 0; count < sizeof(units) / sizeof(Unit); count++) {
        printf("%d. %s\n", count + 1, units[count].name);
    }

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("\nEnter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            (*units[0].convert)(value);
            break;
        case 2:
            (*units[1].convert)(value);
            break;
        case 3:
            (*units[2].convert)(value);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}