//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    int temperature;
} person;

void create_person(person *p) {
    strcpy(p->name, "Unknown");
    p->age = -1;
    p->temperature = -1;
}

void read_person(person *p) {
    printf("Enter name: ");
    scanf("%s", p->name);
    printf("Enter age: ");
    scanf("%d", &p->age);
    printf("Enter temperature (Celsius or Fahrenheit): ");
    scanf("%d", &p->temperature);
}

void display_person(person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Temperature: %d\n", p.temperature);
}

int main() {
    person p;
    create_person(&p);
    read_person(&p);
    display_person(p);

    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (p.temperature >= -273) {
                    p.temperature += 32;
                    p.temperature *= 5/9;
                    printf("\nTemperature converted to Fahrenheit: %d\n", p.temperature);
                } else {
                    printf("\nInvalid temperature.\n");
                }
                break;
            case 2:
                if (p.temperature >= -459.67) {
                    p.temperature -= 32;
                    p.temperature *= 9/5;
                    printf("\nTemperature converted to Celsius: %d\n", p.temperature);
                } else {
                    printf("\nInvalid temperature.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}