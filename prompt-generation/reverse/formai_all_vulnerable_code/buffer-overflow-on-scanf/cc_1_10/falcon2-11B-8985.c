//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARRIER 5
#define MAX_BLOB 100

typedef struct {
    char name[50];
    int carrier;
} Passenger;

typedef struct {
    char name[50];
    int carrier;
} Carrier;

int main() {
    Passenger passengers[MAX_BLOB];
    Carrier carriers[MAX_CARRIER];
    int num_passengers, num_carriers, i, j;
    char name[50];

    printf("Enter number of passengers: ");
    scanf("%d", &num_passengers);

    printf("Enter passenger names: ");
    for (i = 0; i < num_passengers; i++) {
        scanf("%s", passengers[i].name);
        scanf("%d", &passengers[i].carrier);
    }

    printf("Enter number of carriers: ");
    scanf("%d", &num_carriers);

    printf("Enter carrier names: ");
    for (i = 0; i < num_carriers; i++) {
        scanf("%s", carriers[i].name);
        scanf("%d", &carriers[i].carrier);
    }

    printf("Passenger information:\n");
    for (i = 0; i < num_passengers; i++) {
        printf("%s - Carrier: %d\n", passengers[i].name, passengers[i].carrier);
    }

    printf("Carrier information:\n");
    for (i = 0; i < num_carriers; i++) {
        printf("%s - Carrier: %d\n", carriers[i].name, carriers[i].carrier);
    }

    return 0;
}