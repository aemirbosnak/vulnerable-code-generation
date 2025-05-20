//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_ADDRESS_LEN 200
#define MAX_PHONE_NUM_LEN 20
#define MAX_EMAIL_LEN 100
#define MAX_ROOM_NUM 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone_num[MAX_PHONE_NUM_LEN];
    char email[MAX_EMAIL_LEN];
    int room_num;
} Guest;

Guest* create_guest(char* name, char* address, char* phone_num, char* email, int room_num) {
    Guest* guest = (Guest*)malloc(sizeof(Guest));
    strncpy(guest->name, name, MAX_NAME_LEN);
    strncpy(guest->address, address, MAX_ADDRESS_LEN);
    strncpy(guest->phone_num, phone_num, MAX_PHONE_NUM_LEN);
    strncpy(guest->email, email, MAX_EMAIL_LEN);
    guest->room_num = room_num;
    return guest;
}

void delete_guest(Guest* guest) {
    free(guest);
}

void print_guest(Guest* guest) {
    printf("Name: %s\n", guest->name);
    printf("Address: %s\n", guest->address);
    printf("Phone Number: %s\n", guest->phone_num);
    printf("Email: %s\n", guest->email);
    printf("Room Number: %d\n", guest->room_num);
}

int main() {
    Guest* guest1 = create_guest("Sherlock Holmes", "221B Baker Street", "555-1234", "sherlock@example.com", 1);
    Guest* guest2 = create_guest("Dr. John Watson", "456 Maple Ave", "555-5678", "john@example.com", 2);

    printf("Guest 1:\n");
    print_guest(guest1);

    printf("Guest 2:\n");
    print_guest(guest2);

    delete_guest(guest1);
    delete_guest(guest2);

    return 0;
}