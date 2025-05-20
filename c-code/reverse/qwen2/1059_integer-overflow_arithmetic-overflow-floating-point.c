#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define M_TO_MI 0.000621371
#define MI_TO_M 1.60934
#define K_TO_LB 2.20462
#define LB_TO_K 0.453592
#define S_TO_MIN 0.0166667

void convert(char *from_unit, char *to_unit, double value) {
    if (strcmp(from_unit, "m") == 0 && strcmp(to_unit, "mi") == 0)
        printf("%.2f\n", value * M_TO_MI);
    else if (strcmp(from_unit, "mi") == 0 && strcmp(to_unit, "m") == 0)
        printf("%.2f\n", value * MI_TO_M);
    else if (strcmp(from_unit, "kg") == 0 && strcmp(to_unit, "lb") == 0)
        printf("%.2f\n", value * K_TO_LB);
    else if (strcmp(from_unit, "lb") == 0 && strcmp(to_unit, "kg") == 0)
        printf("%.2f\n", value * LB_TO_K);
    else if (strcmp(from_unit, "s") == 0 && strcmp(to_unit, "min") == 0)
        printf("%.2f\n", value * S_TO_MIN);
    else if (strcmp(from_unit, "min") == 0 && strcmp(to_unit, "s") == 0)
        printf("%.2f\n", value / S_TO_MIN);
    else
        printf("Invalid units.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }
    double value = atof(argv[1]);
    convert(argv[2], argv[3], value);
    return 0;
}
