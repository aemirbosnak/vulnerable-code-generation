//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct appointment {
    int day;
    int month;
    int year;
    char description[100];
    struct appointment *next;
};

struct appointment *getAppointment(struct appointment *list, int day, int month, int year) {
    if(list == NULL) {
        return NULL;
    }
    if(list->day == day && list->month == month && list->year == year) {
        return list;
    }
    return getAppointment(list->next, day, month, year);
}

void addAppointment(struct appointment **list, int day, int month, int year, char *description) {
    struct appointment *newAppointment = (struct appointment*)malloc(sizeof(struct appointment));
    newAppointment->day = day;
    newAppointment->month = month;
    newAppointment->year = year;
    strcpy(newAppointment->description, description);
    newAppointment->next = NULL;
    if(*list == NULL) {
        *list = newAppointment;
    }
    else {
        struct appointment *lastNode = *list;
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newAppointment;
    }
}

void deleteAppointment(struct appointment **list, int day, int month, int year) {
    struct appointment *deleteNode = getAppointment(*list, day, month, year);
    if(deleteNode == NULL) {
        printf("\nThere are no appointments for this date!\n");
        return;
    }
    if(deleteNode == *list) {
        *list = (*list)->next;
    }
    else {
        struct appointment *prevNode = *list;
        while(prevNode->next != deleteNode) {
            prevNode = prevNode->next;
        }
        prevNode->next = deleteNode->next;
    }
    free(deleteNode);
}

void displayAppointment(struct appointment *list, int day, int month, int year) {
    struct appointment *displayNode = getAppointment(list, day, month, year);
    if(displayNode == NULL) {
        printf("\nThere are no appointments for this date!\n");
    }
    else {
        printf("\nAppointment on %d/%d/%d: %s\n", displayNode->day, displayNode->month, displayNode->year, displayNode->description);
    }
}

void displayList(struct appointment *list) {
    if(list == NULL) {
        printf("\nThere are no appointments scheduled!\n");
        return;
    }
    printf("\nList of Appointments:\n");
    while(list != NULL) {
        printf("%d/%d/%d: %s\n", list->day, list->month, list->year, list->description);
        list = list->next;
    }
}

int main() {
    struct appointment *list = NULL;
    int choice, day, month, year;
    char description[100];
    do {
        printf("\n1. Add appointment");
        printf("\n2. Delete appointment");
        printf("\n3. Display appointment");
        printf("\n4. Display list of appointments");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter appointment date (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                printf("Enter appointment description: ");
                scanf("%s", description);
                addAppointment(&list, day, month, year, description);
                printf("\nAppointment added successfully!");
                break;
            case 2:
                printf("\nEnter appointment date to delete (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                deleteAppointment(&list, day, month, year);
                break;
            case 3:
                printf("\nEnter appointment date to display (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                displayAppointment(list, day, month, year);
                break;
            case 4:
                displayList(list);
                break;
            case 5:
                printf("\nExiting program\n");
                exit(0);
            default:
                printf("\nInvalid choice, please enter a number from 1 to 5\n");
        }
    }while(1);
    return 0;
}