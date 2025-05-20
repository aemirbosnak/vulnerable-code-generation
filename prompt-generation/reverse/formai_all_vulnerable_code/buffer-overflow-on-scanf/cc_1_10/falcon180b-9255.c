//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct {
    char name[30];
    char phone[15];
} data[MAX];

void add();
void delete();
void search();
void display();

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add();
                break;
            case 2:
                delete();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}

void add() {
    int i;
    char name[30], phone[15];

    printf("\nEnter name: ");
    scanf("%s", name);
    strcpy(data[i].name, name);

    printf("Enter phone number: ");
    scanf("%s", phone);
    strcpy(data[i].phone, phone);

    printf("\nAdded successfully!\n");
}

void delete() {
    char name[30];

    printf("\nEnter name to delete: ");
    scanf("%s", name);

    for(int i=0; i<MAX; i++) {
        if(strcmp(data[i].name, name) == 0) {
            data[i].name[0] = '\0';
            data[i].phone[0] = '\0';
            printf("\nDeleted successfully!\n");
            return;
        }
    }

    printf("\nNot found!\n");
}

void search() {
    char name[30];

    printf("\nEnter name to search: ");
    scanf("%s", name);

    for(int i=0; i<MAX; i++) {
        if(strcmp(data[i].name, name) == 0) {
            printf("\nName: %s\nPhone: %s\n", data[i].name, data[i].phone);
            return;
        }
    }

    printf("\nNot found!\n");
}

void display() {
    for(int i=0; i<MAX; i++) {
        if(data[i].name[0]!= '\0') {
            printf("\nName: %s\nPhone: %s\n", data[i].name, data[i].phone);
        }
    }
}