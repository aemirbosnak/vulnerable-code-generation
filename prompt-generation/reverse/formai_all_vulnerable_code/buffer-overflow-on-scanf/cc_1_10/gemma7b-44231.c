//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    int num_of_bags;
    struct Guest* next;
} Guest;

Guest* insert_guest(Guest* head) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    printf("Enter your name: ");
    scanf("%s", new_guest->name);
    printf("Enter your room number: ");
    scanf("%d", &new_guest->room_number);
    printf("Enter the number of bags you have: ");
    scanf("%d", &new_guest->num_of_bags);
    new_guest->next = head;
    return new_guest;
}

void check_in(Guest* head) {
    printf("Welcome, %s! Please enjoy your stay at the Acme Hotel!", head->name);
    printf("Your room number is: %d", head->room_number);
    printf("You have %d bags. Please proceed to the baggage claim.", head->num_of_bags);
}

void check_out(Guest* head) {
    printf("Thank you for staying at the Acme Hotel, %s!", head->name);
    printf("We hope you enjoyed your stay. Please leave your bags at the baggage claim.");
    free(head);
}

int main() {
    Guest* head = NULL;

    char command;

    printf("Welcome to the Acme Hotel! Please select an option:");
    printf("\n1. Check In");
    printf("\n2. Check Out");
    scanf("%c", &command);

    switch (command) {
        case '1':
            insert_guest(head);
            check_in(head);
            break;
        case '2':
            check_out(head);
            break;
        default:
            printf("Invalid command.");
    }

    return 0;
}