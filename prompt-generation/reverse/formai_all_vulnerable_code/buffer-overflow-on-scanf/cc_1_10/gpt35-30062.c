//FormAI DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Hotel {
    int number;
    char name[20];
    int rooms;
    float price;
    struct Hotel* next;
};

typedef struct Hotel Hotel;

Hotel* create_new_hotel(int number, char name[], int rooms, float price) {
    Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
    hotel->number = number;
    strcpy(hotel->name, name);
    hotel->rooms = rooms;
    hotel->price = price;
    hotel->next = NULL;
    return hotel;
}

void add_hotel(Hotel** head, int number, char name[], int rooms, float price) {
    Hotel* hotel = create_new_hotel(number, name, rooms, price);
    if(*head == NULL) {
        *head = hotel;
    }
    else {
        Hotel* temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = hotel;
    }
}

void display_hotels(Hotel* head) {
    printf("Number\tName\tRooms\tPrice\n");
    while(head != NULL) {
        printf("%d\t%s\t%d\t%.2f\n", head->number, head->name, head->rooms, head->price);
        head = head->next;
    }
}

int count_hotels(Hotel* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void search_hotel(Hotel* head, char name[]) {
    Hotel* temp = head;
    int found = 0;
    while(temp != NULL) {
        if(strcmp(temp->name, name) == 0) {
            printf("Hotel Found!\n");
            printf("Number : %d\n", temp->number);
            printf("Name : %s\n", temp->name);
            printf("Rooms : %d\n", temp->rooms);
            printf("Price : %.2f\n", temp->price);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found == 0) {
        printf("Hotel not Found!\n");
    }
}

void delete_hotel(Hotel** head, char name[]) {
    Hotel* temp = *head, *prev;
    int found = 0;
    while(temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Hotel not Found!\n");
        return;
    }
    if(temp == *head) {
        *head = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    printf("Hotel Deleted Successfully!\n");
}

int main() {
    int choice, number, rooms;
    float price;
    char name[20];
    Hotel* head = NULL;
    do {
        printf("\n------Menu------\n");
        printf("1. Add Hotel\n");
        printf("2. Display Hotels\n");
        printf("3. Count Hotels\n");
        printf("4. Search Hotel\n");
        printf("5. Delete Hotel\n");
        printf("6. Exit\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Hotel Number : ");
                scanf("%d", &number);
                printf("Enter Hotel Name : ");
                scanf("%s", name);
                printf("Enter Number of Rooms : ");
                scanf("%d", &rooms);
                printf("Enter Price per Room : ");
                scanf("%f", &price);
                add_hotel(&head, number, name, rooms, price);
                printf("\nHotel added Successfully!\n");
                break;
            case 2:
                printf("\nHotel Details : \n");
                display_hotels(head);
                break;
            case 3:
                printf("\nTotal Number of Hotels in the List : %d\n", count_hotels(head));
                break;
            case 4:
                printf("Enter Hotel Name to Search : ");
                scanf("%s", name);
                search_hotel(head, name);
                break;
            case 5:
                printf("Enter Hotel Name to Delete : ");
                scanf("%s", name);
                delete_hotel(&head, name);
                break;
            case 6:
                printf("\nExiting Hotel Management System...\n");
                break;
            default:
                printf("\nInvalid Choice! Please Try Again!\n");
        }
    }while(choice != 6);

    return 0;
}