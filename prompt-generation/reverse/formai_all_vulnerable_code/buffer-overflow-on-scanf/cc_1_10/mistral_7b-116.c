//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBER 10
#define MAX_STRING 50

typedef struct {
    char name[MAX_STRING];
    float value;
} HappyNumber;

void print_happy_numbers(HappyNumber numbers[], int size) {
    printf("\n***** Happy Numbers *****\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s = %.2f\n", i+1, numbers[i].name, numbers[i].value);
    }
}

HappyNumber create_number(char name[], float value) {
    HappyNumber number;
    strcpy(number.name, name);
    number.value = value;
    return number;
}

float square_root(float number) {
    float result = 0;
    if (number < 0) {
        printf("Error: Negative number!\n");
        exit(1);
    }
    result = sqrt(number);
    return result;
}

int main() {
    HappyNumber numbers[MAX_NUMBER];
    int size = 0;

    while (size < MAX_NUMBER) {
        char name[MAX_STRING];
        float value;
        printf("\nEnter name of the happy number %d: ", size+1);
        scanf("%s", name);
        printf("Enter its square root: ");
        scanf("%f", &value);

        if (value < 0) {
            printf("Error: Negative square root!\n");
            continue;
        }

        numbers[size] = create_number(name, value);
        size++;
    }

    print_happy_numbers(numbers, size);

    printf("\n***** Adding some more happiness *****\n");

    for (int i = 0; i < size; i++) {
        numbers[i].value += square_root(numbers[i].value);
        printf("%s is now happier and equals %.2f\n", numbers[i].name, numbers[i].value);
    }

    print_happy_numbers(numbers, size);

    return 0;
}