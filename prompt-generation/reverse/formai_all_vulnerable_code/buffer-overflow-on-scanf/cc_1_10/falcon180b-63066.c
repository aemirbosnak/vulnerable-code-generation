//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[50];
    char phone[15];
};

int main() {
    FILE *fp;
    int count = 0;
    struct entry entries[MAX_ENTRIES];
    char choice;
    char search[50];
    char filename[50];

    printf("Welcome to the Phone Book!\n");
    printf("Please enter the filename for the phone book: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s", entries[count].name, entries[count].phone)!= EOF) {
        count++;
    }

    fclose(fp);

    do {
        printf("\nChoose an option:\n");
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Enter name: ");
            scanf(" %s", entries[count].name);
            printf("Enter phone number: ");
            scanf(" %s", entries[count].phone);
            count++;
            printf("\nEntry added successfully.\n");
            break;
        case '2':
            printf("Enter name to search: ");
            scanf(" %s", search);
            for (int i = 0; i < count; i++) {
                if (strcmp(entries[i].name, search) == 0) {
                    printf("\nName: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
                }
            }
            break;
        case '3':
            printf("\nExiting program.\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice!= '3');

    return 0;
}