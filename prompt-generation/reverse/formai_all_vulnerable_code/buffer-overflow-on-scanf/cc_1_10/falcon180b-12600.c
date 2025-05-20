//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBERS_PER_NAME 10
#define MAX_PHONE_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int num_phone_numbers;
    char phone_numbers[MAX_NUMBERS_PER_NAME][MAX_PHONE_NUMBER_LEN];
} PhoneBookEntry;

void add_entry(PhoneBookEntry* pb, char* name, char* phone_number) {
    int i;
    for (i = 0; i < pb->num_phone_numbers; i++) {
        if (strcmp(pb->phone_numbers[i], phone_number) == 0) {
            // Phone number already exists, do nothing
            return;
        }
    }
    // Add new phone number
    strcpy(pb->phone_numbers[pb->num_phone_numbers], phone_number);
    pb->num_phone_numbers++;
}

void print_entry(PhoneBookEntry* pb) {
    int i;
    printf("Name: %s\n", pb->name);
    printf("Number of phone numbers: %d\n", pb->num_phone_numbers);
    for (i = 0; i < pb->num_phone_numbers; i++) {
        printf("Phone number %d: %s\n", i+1, pb->phone_numbers[i]);
    }
}

int main() {
    PhoneBookEntry pb;
    char name[MAX_NAME_LEN];
    char phone_number[MAX_PHONE_NUMBER_LEN];
    int choice, i;

    printf("Welcome to the Phone Book!\n");
    printf("Please choose an option:\n");
    printf("1. Add entry\n");
    printf("2. Print entry\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    while (choice!= 3) {
        switch (choice) {
            case 1:
                printf("Enter name (max %d characters): ", MAX_NAME_LEN-1);
                scanf("%s", name);
                printf("Enter phone number (max %d characters): ", MAX_PHONE_NUMBER_LEN-1);
                scanf("%s", phone_number);
                add_entry(&pb, name, phone_number);
                break;
            case 2:
                print_entry(&pb);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
        printf("Please choose an option:\n");
        printf("1. Add entry\n");
        printf("2. Print entry\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
    }

    return 0;
}