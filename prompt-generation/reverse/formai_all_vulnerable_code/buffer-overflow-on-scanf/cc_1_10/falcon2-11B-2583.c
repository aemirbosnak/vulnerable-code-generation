//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARRIERS 10
#define MAX_BAGS 100
#define MAX_CARRIER_NAME 20
#define MAX_BAG_ID 10
#define MAX_BAG_WEIGHT 100
#define MAX_BAG_SIZE 100
#define MAX_DESTINATION 10
#define MAX_DEPARTURE_TIME 100
#define MAX_ARRIVAL_TIME 100

typedef struct {
    char carrier_name[MAX_CARRIER_NAME];
    int carrier_id;
    char bag_id[MAX_BAG_ID];
    int bag_weight;
    int bag_size;
    char destination[MAX_DESTINATION];
    int departure_time;
    int arrival_time;
} Bag;

typedef struct {
    int num_carriers;
    int num_bags;
    char carriers[MAX_CARRIERS][MAX_CARRIER_NAME];
    Bag bags[MAX_BAGS];
} Airport;

void read_airport(Airport *airport) {
    int i, j;
    char buffer[MAX_CARRIER_NAME];

    printf("Enter the number of carriers: ");
    scanf("%d", &airport->num_carriers);

    for (i = 0; i < airport->num_carriers; i++) {
        printf("Enter carrier %d name: ", i + 1);
        fgets(buffer, MAX_CARRIER_NAME, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(airport->carriers[i], buffer);
    }

    printf("Enter the number of bags: ");
    scanf("%d", &airport->num_bags);

    for (i = 0; i < airport->num_bags; i++) {
        printf("Enter bag %d details:\n", i + 1);
        printf("Carrier name: ");
        fgets(buffer, MAX_CARRIER_NAME, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(airport->bags[i].carrier_name, buffer);

        printf("Carrier ID: ");
        scanf("%d", &airport->bags[i].carrier_id);

        printf("Bag ID: ");
        fgets(buffer, MAX_BAG_ID, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(airport->bags[i].bag_id, buffer);

        printf("Bag weight: ");
        scanf("%d", &airport->bags[i].bag_weight);

        printf("Bag size: ");
        scanf("%d", &airport->bags[i].bag_size);

        printf("Destination: ");
        fgets(buffer, MAX_DESTINATION, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(airport->bags[i].destination, buffer);

        printf("Departure time: ");
        scanf("%d", &airport->bags[i].departure_time);

        printf("Arrival time: ");
        scanf("%d", &airport->bags[i].arrival_time);
    }
}

void print_airport(Airport *airport) {
    int i;
    for (i = 0; i < airport->num_carriers; i++) {
        printf("Carrier %d: %s\n", i + 1, airport->carriers[i]);
    }
    for (i = 0; i < airport->num_bags; i++) {
        printf("Bag %d:\n", i + 1);
        printf("Carrier: %s\n", airport->bags[i].carrier_name);
        printf("Carrier ID: %d\n", airport->bags[i].carrier_id);
        printf("Bag ID: %s\n", airport->bags[i].bag_id);
        printf("Bag weight: %d\n", airport->bags[i].bag_weight);
        printf("Bag size: %d\n", airport->bags[i].bag_size);
        printf("Destination: %s\n", airport->bags[i].destination);
        printf("Departure time: %d\n", airport->bags[i].departure_time);
        printf("Arrival time: %d\n", airport->bags[i].arrival_time);
        printf("\n");
    }
}

int main() {
    Airport airport;

    read_airport(&airport);
    print_airport(&airport);

    return 0;
}