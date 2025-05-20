//FormAI DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *unit_name;
    float multiplier;
} unit;

const unit TABLE[] = {
        {"m",1},
        {"cm",0.01},
        {"km",1000},
        {"in",0.0254},
        {"ft",0.3048},
        {"yd",0.9144}
};

const int TABLE_SIZE = sizeof(TABLE) / sizeof(unit);

float convert(float value, int from, int to) {
    return value * TABLE[from].multiplier / TABLE[to].multiplier;
}

int get_unit_index(char *unit_name) {
    for (int i=0; i<TABLE_SIZE; i++) {
        if (!strcmp(TABLE[i].unit_name, unit_name))
            return i;
    }
    return -1;
}

void print_table() {
    printf("\n");
    for (int i=0; i<TABLE_SIZE; i++) {
        printf("%s\t--->\t%s\n", TABLE[i].unit_name, TABLE[i].unit_name);
    }
}

void convert_units(float value, char *from_unit, char *to_unit) {
    int from = get_unit_index(from_unit);
    int to = get_unit_index(to_unit);

    if (from == -1 || to == -1) {
        printf("Invalid unit!\n");
        return;
    }

    printf("%.4f %s is equivalent to %.4f %s\n", value, from_unit, convert(value, from, to), to_unit);
}

void input(float *value, char *unit) {
    printf("Enter value and unit: ");
    scanf("%f %s", value, unit);
}

void input_async(float *value, char *unit) {
    fflush(stdout);
    printf("\nEnter value and unit: ");
    fflush(stdout);
    scanf("%f %s", value, unit);
}

void print_menu() {
    printf("\nC UNIT CONVERTER\n");
    printf("1. Convert units\n");
    printf("2. Print unit table\n");
    printf("3. Exit\n\n");
}

int main() {
    int choice;
    float value;
    char from_unit[10], to_unit[10];

    while (1) {
        print_menu();
        input_async(&value, from_unit);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_async(&value, from_unit);
                input_async(&value, to_unit);
                convert_units(value, from_unit, to_unit);
                break;
            case 2:
                print_table();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}