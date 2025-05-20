//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BAGS 100
#define MAX_FLIGHTS 10

struct Flight {
    char origin[20];
    char destination[20];
    int numBags;
};

struct Bag {
    int flightNum;
    int destinationIndex;
    char color[20];
};

void generateFlights(struct Flight flights[]) {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Enter flight %d details:\n", i+1);
        scanf("%s %s %d", flights[i].origin, flights[i].destination, &flights[i].numBags);
    }
}

void generateBags(struct Bag bags[]) {
    for (int i = 0; i < MAX_BAGS; i++) {
        printf("Enter bag %d details:\n", i+1);
        scanf("%d %d %s", &bags[i].flightNum, &bags[i].destinationIndex, bags[i].color);
    }
}

void sortBags(struct Bag bags[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (bags[j].flightNum > bags[j+1].flightNum) {
                struct Bag temp = bags[j];
                bags[j] = bags[j+1];
                bags[j+1] = temp;
            }
        }
    }
}

void printSchedule(struct Flight flights[], int n) {
    printf("Flight Schedule:\n");
    for (int i = 0; i < n; i++) {
        printf("%s -> %s (%d bags)\n", flights[i].origin, flights[i].destination, flights[i].numBags);
    }
}

void printBags(struct Bag bags[], int n) {
    printf("Bags:\n");
    for (int i = 0; i < n; i++) {
        printf("Flight %d, Destination %d, Color %s\n", bags[i].flightNum, bags[i].destinationIndex, bags[i].color);
    }
}

int main() {
    struct Flight flights[MAX_FLIGHTS];
    generateFlights(flights);

    struct Bag bags[MAX_BAGS];
    generateBags(bags);

    sortBags(bags, MAX_BAGS);

    printSchedule(flights, MAX_FLIGHTS);
    printBags(bags, MAX_BAGS);

    return 0;
}