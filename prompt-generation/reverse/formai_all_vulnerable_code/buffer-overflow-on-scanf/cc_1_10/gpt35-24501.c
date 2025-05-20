//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 50
#define MAX_FLIGHTS 10

typedef struct Baggage {
    int weight;
    char* destination;
} Baggage;

typedef struct Flight {
    int flight_number;
    char* destination;
} Flight;

typedef struct BaggageNode {
    Baggage* baggage;
    struct BaggageNode* next;
} BaggageNode;

typedef struct ConveyorBelt {
    BaggageNode* head;
    int capacity;
} ConveyorBelt;

ConveyorBelt* initializeConveyorBelt(int capacity) {
    ConveyorBelt* belt = malloc(sizeof(ConveyorBelt));
    belt->capacity = capacity;
    belt->head = NULL;
    return belt;
}

int addToConveyorBelt(ConveyorBelt* belt, Baggage* baggage) {
    if (baggage == NULL) {
        return -1;
    }
    BaggageNode* new_node = malloc(sizeof(BaggageNode));
    new_node->baggage = baggage;
    new_node->next = NULL;
    if (belt->head == NULL) {
        belt->head = new_node;
    } else {
        BaggageNode* current = belt->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return 0;
}

int removeFromConveyorBelt(ConveyorBelt* belt, char* destination) {
    if (belt->head == NULL) {
        return -1;
    }
    if (!strcmp(belt->head->baggage->destination, destination)) {
        BaggageNode* temp = belt->head;
        belt->head = belt->head->next;
        free(temp->baggage->destination);
        free(temp->baggage);
        free(temp);
        return 0;
    } else {
        BaggageNode* current = belt->head;
        while (current->next != NULL && strcmp(current->next->baggage->destination, destination)) {
            current = current->next;
        }
        if (current->next == NULL) {
            return -1;
        } else {
            BaggageNode* temp = current->next;
            current->next = temp->next;
            free(temp->baggage->destination);
            free(temp->baggage);
            free(temp);
            return 0;
        }
    }
}

void printConveyorBelt(ConveyorBelt* belt) {
    if (belt->head == NULL) {
        printf("Conveyor belt is empty.\n");
    } else {
        printf("Current conveyor belt contents:\n");
        BaggageNode* current = belt->head;
        while (current != NULL) {
            printf("Destination: %s  |  Weight: %d kg\n", current->baggage->destination, current->baggage->weight);
            current = current->next;
        }
    }
}

int main() {
    srand(time(0));
    int num_flights = rand() % MAX_FLIGHTS + 1;
    int capacity = rand() % MAX_BAGGAGE + 1;
    Flight flights[num_flights];
    for (int i = 0; i < num_flights; i++) {
        flights[i].flight_number = i + 1;
        flights[i].destination = malloc(sizeof(char) * 20);
        printf("Enter destination of flight %d: ", i + 1);
        scanf("%s", flights[i].destination);
    }
    ConveyorBelt* belt = initializeConveyorBelt(capacity);
    while (1) {
        printf("\nMenu:\n1. Add baggage to conveyor belt\n2. Remove baggage from conveyor belt\n3. Print conveyor belt contents\n4. Exit\nEnter option: ");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1: {
                Baggage* baggage = malloc(sizeof(Baggage));
                baggage->weight = rand() % 50 + 1;
                baggage->destination = malloc(sizeof(char) * 20);
                int flight_idx = rand() % num_flights;
                strcpy(baggage->destination, flights[flight_idx].destination);
                printf("Added baggage with weight %d kg to destination %s.\n", baggage->weight, baggage->destination);
                addToConveyorBelt(belt, baggage);
                break;
            }
            case 2: {
                char destination[20];
                printf("Enter destination to remove baggage: ");
                scanf("%s", destination);
                if (removeFromConveyorBelt(belt, destination) == 0) {
                    printf("Successfully removed baggage to destination %s.\n", destination);
                } else {
                    printf("Failed to remove baggage to destination %s: baggage not found on conveyor belt.\n", destination);
                }
                break;
            }
            case 3: {
                printConveyorBelt(belt);
                break;
            }
            case 4: {
                printf("Exiting program.\n");
                exit(0);
            }
            default: {
                printf("Invalid option.\n");
            }
        }
    }
    return 0;
}