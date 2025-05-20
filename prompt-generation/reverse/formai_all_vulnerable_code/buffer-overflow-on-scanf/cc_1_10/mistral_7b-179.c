//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Struct to represent a carnival visitor
typedef struct {
    char name[50];
    int age;
    double height;
    bool can_ride_rollercoaster;
} visitor_t;

// Function to calculate the height requirement for a rollercoaster
double height_requirement(double rollercoaster_height) {
    return rollercoaster_height * 0.8;
}

// Function to print a welcome message for a carnival visitor
void print_welcome_message(visitor_t *visitor) {
    printf("-------------------------------\n");
    printf("| Welcome to the Arithmetic  |\n");
    printf("|  Carnival!                |\n");
    printf("-------------------------------\n");
    printf("| Name: %s                  |\n", visitor->name);
    printf("| Age: %d                   |\n", visitor->age);
    printf("| Height: %.2f cm           |\n", visitor->height);
    printf("-------------------------------\n");
}

// Function to check if a visitor can ride a rollercoaster
bool can_ride_rollercoaster(visitor_t *visitor, double rollercoaster_height) {
    visitor->can_ride_rollercoaster = (visitor->age >= 12) && (visitor->height >= height_requirement(rollercoaster_height));
    return visitor->can_ride_rollercoaster;
}

// Function to calculate the cost of a ride
double cost_of_ride(char *ride_name, double base_price, int height_bonus) {
    double cost = base_price;

    if (strcmp(ride_name, "Ferris Wheel") == 0) {
        cost += height_bonus;
    } else if (strcmp(ride_name, "Roller Coaster") == 0) {
        cost *= 2.0;
    }

    return cost;
}

// Function to simulate a ride experience
void simulate_ride(visitor_t *visitor, char *ride_name) {
    double rollercoaster_height = 10.0;
    double base_price = 5.0;
    int height_bonus = (int)ceil(visitor->height / 2.0);
    double cost = cost_of_ride(ride_name, base_price, height_bonus);

    if (!can_ride_rollercoaster(visitor, rollercoaster_height)) {
        printf("| %s is not tall enough to ride the %s. |\n", visitor->name, ride_name);
        printf("| Cost: $0.00                         |\n");
        return;
    }

    printf("| %s is tall enough to ride the %s! |\n", visitor->name, ride_name);
    printf("| Cost: $%.2f                         |\n", cost);
}

// Main function to run the Arithmetic Carnival simulation
int main() {
    srand(time(NULL));

    visitor_t visitor;
    char ride_name[20];

    printf("Enter your name: ");
    scanf("%s", visitor.name);
    printf("Enter your age: ");
    scanf("%d", &visitor.age);
    printf("Enter your height (cm): ");
    scanf("%lf", &visitor.height);

    print_welcome_message(&visitor);

    while (true) {
        printf("\nWhich ride would you like to go on? (Enter 'quit' to exit): ");
        scanf("%s", ride_name);

        if (strcmp(ride_name, "quit") == 0) {
            break;
        }

        simulate_ride(&visitor, ride_name);
    }

    printf("\nThank you for visiting the Arithmetic Carnival!");

    return 0;
}