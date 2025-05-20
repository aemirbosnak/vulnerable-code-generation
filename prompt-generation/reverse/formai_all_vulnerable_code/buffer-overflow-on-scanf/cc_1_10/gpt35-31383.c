//FormAI DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[30];
    int room_num;
    char room_type[20];
    int nights;
    float cost;
};

void check_in(struct guest list[], int *num_guests);
void check_out(struct guest list[], int *num_guests);
void print_guests(struct guest list[], int num_guests);

int main() {
    int choice, num_guests = 0;
    struct guest list[100];

    while(1) {
        printf("Welcome to the C Hotel Management System!\n");
        printf("1. Check-in\n");
        printf("2. Check-out\n");
        printf("3. View guests\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                check_in(list, &num_guests);
                break;
            case 2:
                check_out(list, &num_guests);
                break;
            case 3:
                print_guests(list, num_guests);
                break;
            case 4:
                printf("Thank you for using the C Hotel Management System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void check_in(struct guest list[], int *num_guests) {
    int room_num, nights;
    float cost;
    char name[30], room_type[20];

    printf("Enter guest name: ");
    scanf("%s", name);
    printf("Enter room number: ");
    scanf("%d", &room_num);
    printf("Enter room type: ");
    scanf("%s", room_type);
    printf("Enter number of nights: ");
    scanf("%d", &nights);
    printf("Enter cost per night: ");
    scanf("%f", &cost);

    strcpy(list[*num_guests].name, name);
    list[*num_guests].room_num = room_num;
    strcpy(list[*num_guests].room_type, room_type);
    list[*num_guests].nights = nights;
    list[*num_guests].cost = cost;
    (*num_guests)++;

    printf("Guest checked in successfully!\n");
}

void check_out(struct guest list[], int *num_guests) {
    int room_num, i;

    printf("Enter room number: ");
    scanf("%d", &room_num);

    for(i = 0; i < *num_guests; i++) {
        if(list[i].room_num == room_num) {
            printf("Guest %s has checked out of room %d!\n", list[i].name, list[i].room_num);
            list[i] = list[*num_guests - 1];
            (*num_guests)--;
            return;
        }
    }

    printf("Room not found!\n");
}

void print_guests(struct guest list[], int num_guests) {
    int i;

    printf("Guest Name     Room Number     Room Type     Nights Stayed     Cost per Night     Total Cost\n");

    for(i = 0; i < num_guests; i++) {
        printf("%-15s %-15d %-13s %-17d %-18.2f %-18.2f\n", list[i].name, list[i].room_num, list[i].room_type, list[i].nights, list[i].cost, list[i].nights * list[i].cost);
    }
}