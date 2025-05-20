//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100

struct guest {
    char name[50];
    int room_no;
    float bill;
    struct guest *next;
};

struct room {
    int no;
    struct guest *occupant;
    struct room *next;
};

void insert_guest(struct guest **head) {
    struct guest *new_guest = (struct guest *)malloc(sizeof(struct guest));
    printf("Enter your name: ");
    scanf("%s", new_guest->name);
    printf("Enter your room number: ");
    scanf("%d", &new_guest->room_no);
    printf("Enter your bill: ");
    scanf("%f", &new_guest->bill);
    new_guest->next = *head;
    *head = new_guest;
}

void check_in(struct guest **head) {
    printf("Enter your name: ");
    char name[50];
    scanf("%s", name);
    struct guest *current = *head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            printf("Welcome, %s! Your room number is %d.", current->name, current->room_no);
            return;
        }
        current = current->next;
    }
    printf("Sorry, your name is not found.");
}

void calculate_bill(struct guest **head) {
    struct guest *current = *head;
    while (current) {
        current->bill = current->bill + 10;
        current = current->next;
    }
}

void print_guests(struct guest **head) {
    struct guest *current = *head;
    printf("Guests:\n");
    while (current) {
        printf("%s, room number %d, bill %f\n", current->name, current->room_no, current->bill);
        current = current->next;
    }
}

int main() {
    struct guest *head = NULL;
    struct room *rooms = NULL;

    insert_guest(&head);
    insert_guest(&head);
    insert_guest(&head);

    check_in(&head);

    calculate_bill(&head);

    print_guests(&head);

    return 0;
}