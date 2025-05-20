//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 100
#define MIN_TEMP -10

typedef struct {
    int current_temp;
    int min_temp;
    int max_temp;
} temperature_t;

temperature_t* create_temperature() {
    temperature_t* temp = (temperature_t*)malloc(sizeof(temperature_t));
    temp->current_temp = 20;
    temp->min_temp = MIN_TEMP;
    temp->max_temp = MAX_TEMP;
    return temp;
}

void print_temperature(temperature_t* temp) {
    printf("Current temperature: %d\n", temp->current_temp);
    printf("Minimum temperature: %d\n", temp->min_temp);
    printf("Maximum temperature: %d\n", temp->max_temp);
}

void set_temperature(temperature_t* temp, int value) {
    if (value < temp->min_temp || value > temp->max_temp) {
        printf("Invalid temperature value.\n");
        return;
    }
    temp->current_temp = value;
}

void increase_temperature(temperature_t* temp) {
    if (temp->current_temp >= temp->max_temp) {
        printf("Maximum temperature reached.\n");
        return;
    }
    temp->current_temp++;
}

void decrease_temperature(temperature_t* temp) {
    if (temp->current_temp <= temp->min_temp) {
        printf("Minimum temperature reached.\n");
        return;
    }
    temp->current_temp--;
}

int main() {
    temperature_t* temp = create_temperature();

    print_temperature(temp);

    set_temperature(temp, 30);
    print_temperature(temp);

    increase_temperature(temp);
    print_temperature(temp);

    decrease_temperature(temp);
    print_temperature(temp);

    free(temp);
    return 0;
}