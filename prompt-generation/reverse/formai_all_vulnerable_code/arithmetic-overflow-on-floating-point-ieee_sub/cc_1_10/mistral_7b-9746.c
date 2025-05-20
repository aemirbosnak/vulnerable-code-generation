//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323846

typedef struct temp {
    char unit;
    double value;
} Temp;

void convert_f_to_c(Temp *temp) {
    temp->value = (temp->value - 32) * 5 / 9;
}

void convert_c_to_f(Temp *temp) {
    temp->value = temp->value * 9 / 5 + 32;
}

void print_temp(Temp temp) {
    printf("Temperature : %.2f", temp.value);
    switch(temp.unit) {
        case 'F': printf(" Fahrenheit"); break;
        case 'C': printf(" Celsius"); break;
        case 'K': printf(" Kelvin"); break;
        default: printf(" Invalid Unit");
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Usage : %s <Temperature> <F|C|K> <Temperature> <F|C|K>\n", argv[0]);
        return 1;
    }

    Temp temp1 = {'F', atof(argv[1])};
    Temp temp2 = {'F', atof(argv[3])};

    if(argv[2][0] == 'F') {
        convert_f_to_c(&temp1);
        convert_f_to_c(&temp2);
    } else if(argv[2][0] == 'C') {
        convert_c_to_f(&temp1);
        convert_c_to_f(&temp2);
    } else if(argv[2][0] == 'K') {
        temp1.value -= 273.15;
        temp2.value -= 273.15;
    } else {
        printf("Invalid Unit\n");
        return 1;
    }

    double diff = temp1.value - temp2.value;

    printf("Difference between %s %.2f%s and %s %.2f%s is %s %.2f%s\n", argv[1], temp1.value, argv[2], argv[5], temp2.value, argv[4], temp1.unit == temp2.unit ? "equal" : "not equal", abs(diff));

    print_temp(temp1);
    print_temp(temp2);

    return 0;
}