//FormAI DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int room_number;
    int check_in_day;
    int check_in_month;
    int check_out_day;
    int check_out_month;
} guest_info;

guest_info guests[50];

void check_in(void) {
    char name[50];
    int room_number, check_in_day, check_in_month, check_out_day, check_out_month;
    printf("Enter guest name: ");
    scanf("%s", name);
    printf("Enter room number: ");
    scanf("%d", &room_number);
    printf("Enter check in day: ");
    scanf("%d", &check_in_day);
    printf("Enter check in month: ");
    scanf("%d", &check_in_month);
    printf("Enter check out day: ");
    scanf("%d", &check_out_day);
    printf("Enter check out month: ");
    scanf("%d", &check_out_month);
    for (int i = 0; guests[i].name[0] != '\0'; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            printf("Error: guest already exists.\n");
            return;
        }
    }
    for (int i = 0; i < 50; i++) {
        if (guests[i].name[0] == '\0') {
            strcpy(guests[i].name, name);
            guests[i].room_number = room_number;
            guests[i].check_in_day = check_in_day;
            guests[i].check_in_month = check_in_month;
            guests[i].check_out_day = check_out_day;
            guests[i].check_out_month = check_out_month;
            printf("Guest successfully checked in.\n");
            return;
        }
    }
    printf("Error: maximum number of guests reached.\n");
}

void check_out(void) {
    char name[50];
    printf("Enter guest name: ");
    scanf("%s", name);
    for (int i = 0; i < 50; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            guests[i].name[0] = '\0';
            printf("Guest successfully checked out.\n");
            return;
        }
    }
    printf("Error: guest not found.\n");
}

void display_guests(void) {
    printf("Guest Name\tRoom Number\tCheck-in Date\tCheck-out Date\n");
    for (int i = 0; guests[i].name[0] != '\0'; i++) {
        printf("%s\t\t%d\t\t%d/%d\t\t%d/%d\n", guests[i].name, guests[i].room_number, guests[i].check_in_day, guests[i].check_in_month, guests[i].check_out_day, guests[i].check_out_month);
    }
}

int main(void) {
    int choice;
    while (1) {
        printf("1. Check in guest\n");
        printf("2. Check out guest\n");
        printf("3. Display guests\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: check_in(); break;
            case 2: check_out(); break;
            case 3: display_guests(); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}