//FormAI DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main() {
    char input_unit[10], output_unit[10];
    double input_value, output_value;
    printf("C Unit Converter\n\n");
    printf("Enter Input Unit (cm, m, km, inch, ft, yd): ");
    scanf("%s", input_unit);
    printf("Enter Input Value: ");
    scanf("%lf", &input_value);
    printf("Enter Output Unit (cm, m, km, inch, ft, yd): ");
    scanf("%s", output_unit);

    if(strcmp(input_unit, "cm") == 0) {
        if(strcmp(output_unit, "cm") == 0) {
            output_value = input_value;
        }
        else if(strcmp(output_unit, "m") == 0) {
            output_value = input_value / 100.0;
        }
        else if(strcmp(output_unit, "km") == 0) {
            output_value = input_value / 100000.0;
        }
        else if(strcmp(output_unit, "inch") == 0) {
            output_value = input_value / 2.54;
        }
        else if(strcmp(output_unit, "ft") == 0) {
            output_value = input_value / 30.48;
        }
        else if(strcmp(output_unit, "yd") == 0) {
            output_value = input_value / 91.44;
        }
    }
    else if(strcmp(input_unit, "m") == 0) {
        if(strcmp(output_unit, "cm") == 0) {
            output_value = input_value * 100.0;
        }
        else if(strcmp(output_unit, "m") == 0) {
            output_value = input_value;
        }
        else if(strcmp(output_unit, "km") == 0) {
            output_value = input_value / 1000.0;
        }
        else if(strcmp(output_unit, "inch") == 0) {
            output_value = input_value * 39.37;
        }
        else if(strcmp(output_unit, "ft") == 0) {
            output_value = input_value * 3.281;
        }
        else if(strcmp(output_unit, "yd") == 0) {
            output_value = input_value * 1.094;
        }
    }
    else if(strcmp(input_unit, "km") == 0) {
        if(strcmp(output_unit, "cm") == 0) {
            output_value = input_value * 100000.0;
        }
        else if(strcmp(output_unit, "m") == 0) {
            output_value = input_value * 1000.0;
        }
        else if(strcmp(output_unit, "km") == 0) {
            output_value = input_value;
        }
        else if(strcmp(output_unit, "inch") == 0) {
            output_value = input_value * 39370.08;
        }
        else if(strcmp(output_unit, "ft") == 0) {
            output_value = input_value * 3280.84;
        }
        else if(strcmp(output_unit, "yd") == 0) {
            output_value = input_value * 1093.61;
        }
    }
    else if(strcmp(input_unit, "inch") == 0) {
        if(strcmp(output_unit, "cm") == 0) {
            output_value = input_value * 2.54;
        }
        else if(strcmp(output_unit, "m") == 0) {
            output_value = input_value / 39.37;
        }
        else if(strcmp(output_unit, "km") == 0) {
            output_value = input_value / 39370.08;
        }
        else if(strcmp(output_unit, "inch") == 0) {
            output_value = input_value;
        }
        else if(strcmp(output_unit, "ft") == 0) {
            output_value = input_value / 12.0;
        }
        else if(strcmp(output_unit, "yd") == 0) {
            output_value = input_value / 36.0;
        }
    }
    else if(strcmp(input_unit, "ft") == 0) {
        if(strcmp(output_unit, "cm") == 0) {
            output_value = input_value * 30.48;
        }
        else if(strcmp(output_unit, "m") == 0) {
            output_value = input_value / 3.281;
        }
        else if(strcmp(output_unit, "km") == 0) {
            output_value = input_value / 3280.84;
        }
        else if(strcmp(output_unit, "inch") == 0) {
            output_value = input_value * 12.0;
        }
        else if(strcmp(output_unit, "ft") == 0) {
            output_value = input_value;
        }
        else if(strcmp(output_unit, "yd") == 0) {
            output_value = input_value / 3.0;
        }
    }
    else if(strcmp(input_unit, "yd") == 0) {
        if(strcmp(output_unit, "cm") == 0) {
            output_value = input_value * 91.44;
        }
        else if(strcmp(output_unit, "m") == 0) {
            output_value = input_value / 1.094;
        }
        else if(strcmp(output_unit, "km") == 0) {
            output_value = input_value / 1093.61;
        }
        else if(strcmp(output_unit, "inch") == 0) {
            output_value = input_value * 36.0;
        }
        else if(strcmp(output_unit, "ft") == 0) {
            output_value = input_value * 3.0;
        }
        else if(strcmp(output_unit, "yd") == 0) {
            output_value = input_value;
        }
    }
    else {
        printf("Invalid input or output unit");
        return 0;
    }

    printf("%.3lf %s = %.3lf %s", input_value, input_unit, output_value, output_unit);
    return 0;
}