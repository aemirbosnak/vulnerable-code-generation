//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    float temperature;
} Person;

typedef struct {
    char unit[5];
    float conversion_factor;
} TemperatureUnit;

void read_person_data(Person* person) {
    printf("Enter name: ");
    scanf("%s", person->name);
    printf("Enter temperature (Fahrenheit): ");
    scanf("%f", &person->temperature);
}

void print_person_data(Person person) {
    printf("\nName: %s", person.name);
    printf("\nTemperature in Fahrenheit: %.2f", person.temperature);
}

void convert_fahrenheit_to_celsius(Person* person) {
    TemperatureUnit celsius = { "Celsius", 1.8 };
    person->temperature = person->temperature * celsius.conversion_factor;
    printf("\nTemperature in Celsius: %.2f\n", person->temperature);
}

void convert_celsius_to_fahrenheit(Person* person) {
    TemperatureUnit fahrenheit = { "Fahrenheit", 1.8, 32.0 };
    person->temperature = (person->temperature * fahrenheit.conversion_factor) + fahrenheit.conversion_factor;
    printf("\nTemperature in Fahrenheit: %.2f\n", person->temperature);
}

int main() {
    Person person;
    int choice;

    read_person_data(&person);
    printf("Do you want to convert Fahrenheit to Celsius or Celsius to Fahrenheit?\n1. Fahrenheit to Celsius\n2. Celsius to Fahrenheit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            convert_fahrenheit_to_celsius(&person);
            break;
        case 2:
            convert_celsius_to_fahrenheit(&person);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    print_person_data(person);

    return 0;
}