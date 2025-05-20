//FormAI DATASET v1.0 Category: Database simulation ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of cars that the database can store
#define MAX_CARS 100

// Define a structure to represent a car
struct car {
    char brand[50];
    char model[50];
    int year;
};

// Define the database to hold an array of cars
struct car database[MAX_CARS];

// Define a variable to keep track of the number of cars in the database
int num_cars = 0;

// Function to search for a car by brand in the database
void search_car(char* search_brand) {
    int i;
    int found_car = 0;

    for (i = 0; i < num_cars; i++) {
        if (strcmp(database[i].brand, search_brand) == 0) {
            printf("Car found:\n");
            printf("Brand: %s\n", database[i].brand);
            printf("Model: %s\n", database[i].model);
            printf("Year: %d\n", database[i].year);
            found_car = 1;
        }
    }

    if (!found_car) {
        printf("No cars found.\n");
    }
}

// Function to add a new car to the database
void add_car(char* brand, char* model, int year) {
    if (num_cars == MAX_CARS) {
        printf("Error: database is full!\n");
        return;
    }

    strcpy(database[num_cars].brand, brand);
    strcpy(database[num_cars].model, model);
    database[num_cars].year = year;

    num_cars++;

    printf("Car added.\n");
}

// Function to print all cars in the database
void print_database() {
    int i;

    printf("Printing all cars in database:\n");

    for (i = 0; i < num_cars; i++) {
        printf("Brand: %s\n", database[i].brand);
        printf("Model: %s\n", database[i].model);
        printf("Year: %d\n", database[i].year);
        printf("\n");
    }
}

int main() {
    int choice;
    char brand[50];
    char model[50];
    int year;
    char search_brand[50];

    // Main menu loop
    while (1) {
        printf("Enter a command:\n");
        printf("1. Add a car.\n");
        printf("2. Search for a car by brand.\n");
        printf("3. Print all cars in database.\n");
        printf("4. Quit.\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter brand:\n");
                scanf("%s", brand);
                printf("Enter model:\n");
                scanf("%s", model);
                printf("Enter year:\n");
                scanf("%d", &year);

                add_car(brand, model, year);

                break;
            case 2:
                printf("Enter brand to search for:\n");
                scanf("%s", search_brand);

                search_car(search_brand);

                break;
            case 3:
                print_database();

                break;
            case 4:
                printf("Goodbye!\n");

                exit(0);
            default:
                printf("Invalid command.\n");

                break;
        }

        printf("\n");
    }

    return 0;
}