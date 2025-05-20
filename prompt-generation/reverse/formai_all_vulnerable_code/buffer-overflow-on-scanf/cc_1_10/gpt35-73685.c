//FormAI DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure to hold mailing list details
struct mailing_list {
    int id;
    char name[100];
    char email[100];
};

//Function to add new subscriber to mailing list
void add_subscriber(struct mailing_list *list, int *count) {
    int id;
    printf("Enter subscriber id: ");
    scanf("%d", &id);

    //Checking if subscriber id already exists
    for(int i=0;i<*count;i++) {
        if(list[i].id == id) {
            printf("Subscriber with id %d already exists!\n", id);
            return;
        }
    }

    //Adding new subscriber
    list[*count].id = id;
    printf("Enter subscriber name: ");
    scanf("%s", list[*count].name);
    printf("Enter subscriber email: ");
    scanf("%s", list[*count].email);
    (*count)++;

    printf("Subscriber added successfully!\n");
}

//Function to delete subscriber from mailing list
void delete_subscriber(struct mailing_list *list, int *count) {
    int id;
    printf("Enter subscriber id to delete: ");
    scanf("%d", &id);

    //Finding the subscriber to delete
    int index = -1;
    for(int i=0;i<*count;i++) {
        if(list[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Subscriber with id %d not found!\n", id);
        return;
    }

    //Deleting subscriber
    for(int i=index+1;i<*count;i++) {
        list[i-1] = list[i];
    }
    (*count)--;
    printf("Subscriber deleted successfully!\n");
}

//Function to display all subscribers in mailing list
void display_subscribers(struct mailing_list *list, int count) {
    if(count == 0) {
        printf("No subscribers found!\n");
        return;
    }

    printf("%-10s %-20s %-20s\n", "ID", "NAME", "EMAIL");
    for(int i=0;i<count;i++) {
        printf("%-10d %-20s %-20s\n", list[i].id, list[i].name, list[i].email);
    }
}

int main() {
    int choice;
    int count = 0;
    struct mailing_list list[100];

    while(1) {
        printf("\nMENU\n");
        printf("1. Add subscriber\n");
        printf("2. Delete subscriber\n");
        printf("3. Display all subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_subscriber(list, &count);
                break;
            case 2:
                delete_subscriber(list, &count);
                break;
            case 3:
                display_subscribers(list, count);
                break;
            case 4:
                printf("Exiting program!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}