//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum { WATER, EARTH, AIR, FIRE } Element;

struct Temperature {
    double celcius;
    Element element;
};

void print_element(Element e) {
    switch (e) {
        case WATER: printf("Water\n"); break;
        case EARTH: printf("Earth\n"); break;
        case AIR: printf("Air\n"); break;
        case FIRE: printf("Fire\n"); break;
    }
}

struct Temperature celsius_to_element(double celcius) {
    struct Temperature temp = {celcius, WATER};

    if (celcius < 0) {
        temp.element = EARTH;
        temp.celcius *= -1;
    } else if (celcius < 40) {
        temp.element = WATER;
    } else if (celcius < 60) {
        temp.element = AIR;
    } else {
        temp.element = FIRE;
        temp.celcius -= 40;
    }

    return temp;
}

double element_to_celsius(struct Temperature temp) {
    switch (temp.element) {
        case WATER: return temp.celcius;
        case EARTH: return temp.celcius * -1;
        case AIR: return temp.celcius + 40;
        case FIRE: return temp.celcius + 40;
    }

    // In case the temperature was not a valid element, return an error value
    return NAN;
}

int main() {
    double celsius;
    char input[10];

    printf("Welcome to Tempera's Oracle, mortal!\n");
    printf("Enter a temperature in Celsius: ");
    scanf("%s", input);
    celsius = atof(input);

    struct Temperature temperature = celsius_to_element(celsius);
    printf("The temperature %0.1f degrees Celsius is equivalent to\n", celsius);

    print_element(temperature.element);

    if (!isnan(temperature.celcius)) {
        printf("of the element %0.1f degrees\n", temperature.celcius);
    }

    double converted_back = element_to_celsius(temperature);
    printf("And back to Celsius it becomes %0.1f degrees.\n", converted_back);

    return 0;
}