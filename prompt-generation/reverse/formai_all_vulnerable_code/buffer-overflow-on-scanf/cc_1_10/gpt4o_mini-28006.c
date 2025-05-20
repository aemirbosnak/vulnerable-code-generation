//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int status;  // 0: In Transit, 1: Delivered
} Bag;

Bag baggage[MAX_BAGS];
int bag_count = 0;

void checkInBag(char *name) {
    if (bag_count >= MAX_BAGS) {
        printf("===> Baggage reclaim limit reached. No more bags can be checked in! <===\n");
        return;
    }
    Bag new_bag;
    new_bag.id = bag_count + 1;
    strncpy(new_bag.name, name, MAX_NAME_LENGTH);
    new_bag.status = 0;
    baggage[bag_count] = new_bag;
    bag_count++;
    printf("===> Checked in bag with ID: %d and Name: %s <===\n", new_bag.id, new_bag.name);
}

void transferBag(int id) {
    if (id <= 0 || id > bag_count || baggage[id - 1].status == 1) {
        printf("===> Invalid bag ID or bag already delivered. <===\n");
        return;
    }
    baggage[id - 1].status = 1;
    printf("===> Bag ID: %d has been transferred for delivery. <===\n", id);
}

void displayBags() {
    printf("\n==== Current Baggage Status ====\n");
    for (int i = 0; i < bag_count; i++) {
        printf("ID: %d, Name: %s, Status: %s\n", baggage[i].id, baggage[i].name, 
               baggage[i].status == 0 ? "In Transit" : "Delivered");
    }
}

int main() {
    char option, name[MAX_NAME_LENGTH];
    
    printf("======= Airport Baggage Handling Simulation =======\n");
    do {
        printf("\nOptions:\n");
        printf("C - Check-in a bag\n");
        printf("T - Transfer a bag\n");
        printf("D - Display all bags\n");
        printf("E - Exit\n");
        printf("Enter your option: ");
        option = getchar();
        getchar();  // consume newline

        switch (option) {
            case 'C':
            case 'c':
                printf("Enter bag name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character
                checkInBag(name);
                break;
            case 'T':
            case 't':
                printf("Enter bag ID to transfer: ");
                int id;
                scanf("%d", &id);
                getchar();  // consume newline
                transferBag(id);
                break;
            case 'D':
            case 'd':
                displayBags();
                break;
            case 'E':
            case 'e':
                printf("Exiting the baggage handling simulation.\n");
                break;
            default:
                printf("===> Invalid option! Please try again. <===\n");
        }
    } while(option != 'E' && option != 'e');
    
    return 0;
}