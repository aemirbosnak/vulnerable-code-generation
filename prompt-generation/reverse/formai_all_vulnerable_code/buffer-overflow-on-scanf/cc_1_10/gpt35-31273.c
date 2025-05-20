//FormAI DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char email[30];
    int age;
    char city[20];
} Subscriber;

void addSubscriber(Subscriber *list, int *size) {
    printf("Enter subscriber name: ");
    scanf("%s", list[*size].name);
    printf("Enter subscriber email: ");
    scanf("%s", list[*size].email);
    printf("Enter subscriber age: ");
    scanf("%d", &list[*size].age);
    printf("Enter subscriber city: ");
    scanf("%s", list[*size].city);
    *size += 1;
    printf("Subscriber added successfully!\n");
}

void deleteSubscriber(Subscriber *list, int *size) {
    char email[30];
    int i, found = 0;
    printf("Enter subscriber email: ");
    scanf("%s", email);
    for (i = 0; i < *size; i++) {
        if (!strcmp(list[i].email, email)) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < *size-1; i++) {
            strcpy(list[i].name, list[i+1].name);
            strcpy(list[i].email, list[i+1].email);
            list[i].age = list[i+1].age;
            strcpy(list[i].city, list[i+1].city);
        }
        *size -= 1;
        printf("Subscriber deleted successfully!\n");
    } else {
        printf("Subscriber not found!\n");
    }
}

void listSubscribers(Subscriber *list, int size) {
    int i;
    printf("\nList of subscribers:\n");
    for (i = 0; i < size; i++) {
        printf("Name: %s\n", list[i].name);
        printf("Email: %s\n", list[i].email);
        printf("Age: %d\n", list[i].age);
        printf("City: %s\n", list[i].city);
        printf("\n");
    }
}

int main() {
    Subscriber list[100];
    int size = 0, choice;
    while (1) {
        
        printf("\nWelcome to the Love Mailing List Manager!\n");
        printf("1. Add subscriber\n");
        printf("2. Delete subscriber\n");
        printf("3. List subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addSubscriber(list, &size);
                break;
            case 2:
                deleteSubscriber(list, &size);
                break;
            case 3:
                listSubscribers(list, size);
                break;
            case 4:
                printf("Thank you for using the Love Mailing List Manager! We hope you find true love!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}