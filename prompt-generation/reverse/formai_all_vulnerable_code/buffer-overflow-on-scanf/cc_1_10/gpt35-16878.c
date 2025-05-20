//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int id;
    char brand[20];
    char model[20];
    float price;
} RC_vehicle;

int main() {
    RC_vehicle vehicle1, vehicle2, vehicle3; // Creating variables of type RC_vehicle

    // Initializing values for vehicle1
    vehicle1.id = 1;
    strcpy(vehicle1.brand, "Traxxas");
    strcpy(vehicle1.model, "X-Maxx");
    vehicle1.price = 899.99;

    // Initializing values for vehicle2
    vehicle2.id = 2;
    strcpy(vehicle2.brand, "Losi");
    strcpy(vehicle2.model, "Super Baja Rey");
    vehicle2.price = 1199.99;

    // Initializing values for vehicle3
    vehicle3.id = 3;
    strcpy(vehicle3.brand, "ARRMA");
    strcpy(vehicle3.model, "Mojave");
    vehicle3.price = 649.99;

    printf("RC Vehicle Simulation\n");
    printf("=====================\n");

    while (1) { // Loop until user decides to exit
        int option;
        printf("\nAvailable vehicles:\n");
        printf("1. %s %s ($%.2f)\n", vehicle1.brand, vehicle1.model, vehicle1.price);
        printf("2. %s %s ($%.2f)\n", vehicle2.brand, vehicle2.model, vehicle2.price);
        printf("3. %s %s ($%.2f)\n", vehicle3.brand, vehicle3.model, vehicle3.price);
        printf("Enter an option (1-3): ");
        scanf("%d", &option);

        if (option == 1) {
            printf("\nYou have selected the %s %s.\n", vehicle1.brand, vehicle1.model);
            printf("Press any key to exit...");
            getchar(); // Wait for user to press enter
            break;
        } else if (option == 2) {
            printf("\nYou have selected the %s %s.\n", vehicle2.brand, vehicle2.model);
            printf("Press any key to exit...");
            getchar(); // Wait for user to press enter
            break;
        } else if (option == 3) {
            printf("\nYou have selected the %s %s.\n", vehicle3.brand, vehicle3.model);
            printf("Press any key to exit...");
            getchar(); // Wait for user to press enter
            break;
        } else {
            printf("\nInvalid option. Please enter a number between 1 and 3.\n");
        }
    }

    return 0;
}