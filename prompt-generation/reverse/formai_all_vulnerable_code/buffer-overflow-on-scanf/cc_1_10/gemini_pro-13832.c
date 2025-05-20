//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Ken Thompson
#include <stdio.h>

typedef struct {
    char name[32];
    char address[128];
    char phone[32];
    char email[64];
    char checkin[32];
    char checkout[32];
    int room;
    float amount;
} guest;

#define NUM_GUESTS 100

guest guests[NUM_GUESTS];

int main() {
    int i;

    for (i = 0; i < NUM_GUESTS; i++) {
        printf("Enter guest name: ");
        scanf("%s", guests[i].name);
        printf("Enter guest address: ");
        scanf("%s", guests[i].address);
        printf("Enter guest phone: ");
        scanf("%s", guests[i].phone);
        printf("Enter guest email: ");
        scanf("%s", guests[i].email);
        printf("Enter guest checkin: ");
        scanf("%s", guests[i].checkin);
        printf("Enter guest checkout: ");
        scanf("%s", guests[i].checkout);
        printf("Enter guest room: ");
        scanf("%d", &guests[i].room);
        printf("Enter guest amount: ");
        scanf("%f", &guests[i].amount);
        printf("\n");
    }

    for (i = 0; i < NUM_GUESTS; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Address: %s\n", guests[i].address);
        printf("Phone: %s\n", guests[i].phone);
        printf("Email: %s\n", guests[i].email);
        printf("Checkin: %s\n", guests[i].checkin);
        printf("Checkout: %s\n", guests[i].checkout);
        printf("Room: %d\n", guests[i].room);
        printf("Amount: %f\n", guests[i].amount);
        printf("\n");
    }

    return 0;
}