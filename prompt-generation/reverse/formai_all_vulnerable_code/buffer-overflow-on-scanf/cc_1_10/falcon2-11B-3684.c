//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char airport[100];
    char baggages[100][100];
    int num_baggages = 0;
    int num_passengers = 0;
    int passenger_baggage_num[100];
    int passenger_baggage_sum = 0;
    int passenger_baggage_max = 0;
    int passenger_baggage_avg = 0;

    printf("Welcome to the World's Most Efficient Airport Baggage Handling System!\n");
    printf("Please enter the name of the airport: ");
    scanf("%s", airport);

    printf("Please enter the number of passengers: ");
    scanf("%d", &num_passengers);

    printf("Please enter the number of baggages per passenger: ");
    scanf("%d", &num_baggages);

    for (int i = 0; i < num_passengers; i++) {
        printf("Please enter the name of passenger %d: ", i + 1);
        scanf("%s", passenger_baggage_num + i);

        printf("Please enter the number of baggages for passenger %d: ", i + 1);
        scanf("%d", &passenger_baggage_num[i]);
    }

    printf("Now, please enter the name of each baggage for every passenger:\n");

    for (int i = 0; i < num_passengers; i++) {
        printf("Passenger %d: ", i + 1);
        scanf("%s", baggages[i]);

        for (int j = 0; j < passenger_baggage_num[i]; j++) {
            printf("Baggage %d: ", j + 1);
            scanf("%s", baggages[i] + j * 100);
        }
    }

    printf("\n\n");

    printf("The number of baggages: %d\n", num_baggages);
    printf("The number of passengers: %d\n", num_passengers);

    printf("The passenger with the most baggages: %d, %s\n", passenger_baggage_max, passenger_baggage_num[passenger_baggage_max]);
    printf("The average number of baggages per passenger: %.2f\n", passenger_baggage_avg);

    return 0;
}