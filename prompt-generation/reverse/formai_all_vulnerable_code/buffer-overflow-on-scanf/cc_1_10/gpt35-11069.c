//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Flight {
    char flight_number[6];
    int num_bags;
};

struct Baggage {
    char id[8];
    char flight_number[6];
    int weight;
};

struct Conveyor {
    struct Baggage* bags;
    int num_bags;
    int capacity;
};

void add_bag_to_conveyor(struct Conveyor* conveyor, struct Baggage* bag) {
    if(conveyor->num_bags < conveyor->capacity) {
        conveyor->bags[conveyor->num_bags++] = *bag;
        printf("Bag with id %s added to the conveyor.\n\n", bag->id);
    }
    else {
        printf("Conveyor is full. Cannot add more bags.\n\n");
    }
}

void remove_bag_from_conveyor(struct Conveyor* conveyor, int index) {
    if(index < conveyor->num_bags) {
        printf("Bag with id %s removed from the conveyor.\n\n", conveyor->bags[index].id);
        for(int i = index; i < conveyor->num_bags-1; i++) {
            conveyor->bags[i] = conveyor->bags[i+1];
        }
        conveyor->num_bags--;
    }
    else {
        printf("Invalid index. Cannot remove bag.\n\n");
    }
}

int main() {
    struct Conveyor baggage_conveyor;
    baggage_conveyor.bags = malloc(sizeof(struct Baggage)*10);
    baggage_conveyor.num_bags = 0;
    baggage_conveyor.capacity = 10;
    printf("Welcome to the Baggage Handling System!\n\n");
    
    while(true) {
        printf("1. Add baggage to the conveyor.\n");
        printf("2. Remove baggage from the conveyor.\n");
        printf("3. View all bags on the conveyor.\n");
        printf("4. Exit.\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        
        if(choice == 1) {
            printf("\nEnter the flight number: ");
            char flight_num[6];
            scanf("%s", flight_num);
            printf("Enter the baggage id: ");
            char baggage_id[8];
            scanf("%s", baggage_id);
            printf("Enter the weight of the baggage: ");
            int weight;
            scanf("%d", &weight);
            struct Baggage new_baggage;
            strcpy(new_baggage.flight_number, flight_num);
            strcpy(new_baggage.id, baggage_id);
            new_baggage.weight = weight;
            add_bag_to_conveyor(&baggage_conveyor, &new_baggage);
        }
        else if(choice == 2) {
            printf("\nEnter the index of the bag to remove: ");
            int index;
            scanf("%d", &index);
            remove_bag_from_conveyor(&baggage_conveyor, index);
        }
        else if(choice == 3) {
            printf("\nList of bags on the conveyor:\n");
            for(int i = 0; i < baggage_conveyor.num_bags; i++) {
                printf("%d. Id: %s, Flight Number: %s, Weight: %d kg\n", i+1, baggage_conveyor.bags[i].id, baggage_conveyor.bags[i].flight_number, baggage_conveyor.bags[i].weight);
            }
            printf("\n");
        }
        else if(choice == 4) {
            printf("\nThank you for using the Baggage Handling System!\n");
            return 0;
        }
        else {
            printf("\nInvalid choice. Please enter a valid choice.\n\n");
        }
    }
}