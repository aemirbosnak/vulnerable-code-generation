//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

/* Struct to hold name and email address */
struct customer {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

/* Function to add customer to list */
void addCustomer(struct customer list[], int *count) {
    /* Check if list is full */
    if (*count == 10) {
        printf("ERROR: List is full! Cannot add anymore customers.\n");
        return;
    }
    /* Get name and email from user */
    printf("Enter customer name: ");
    fgets(list[*count].name, MAX_NAME_LEN, stdin);
    printf("Enter customer email: ");
    fgets(list[*count].email, MAX_EMAIL_LEN, stdin);
    /* Remove newline character from input */
    strtok(list[*count].name, "\n");
    strtok(list[*count].email, "\n");
    /* Increment count */
    (*count)++;
    /* Print success message */
    printf("Customer added to list.\n");
}

/* Function to remove customer from list */
void removeCustomer(struct customer list[], int *count) {
    /* Check if list is empty */
    if (*count == 0) {
        printf("ERROR: List is empty! Cannot remove customer.\n");
        return;
    }
    /* Get index of customer to be removed */
    int index;
    printf("Enter index of customer to be removed (0-%d): ", *count-1);
    scanf("%d", &index);
    getchar(); /* remove newline character from input buffer */
    /* Check if index is valid */
    if (index < 0 || index >= *count) {
        printf("ERROR: Invalid index! Cannot remove customer.\n");
        return;
    }
    /* Remove customer from list and shift remaining customers */
    for (int i = index; i < *count-1; i++) {
        strcpy(list[i].name, list[i+1].name);
        strcpy(list[i].email, list[i+1].email);
    }
    /* Decrement count */
    (*count)--;
    /* Print success message */
    printf("Customer removed from list.\n");
}

/* Function to display all customers in list */
void displayCustomers(struct customer list[], int count) {
    /* Check if list is empty */
    if (count == 0) {
        printf("ERROR: List is empty! Cannot display customers.\n");
        return;
    }
    /* Print headers */
    printf("Index\tName\t\tEmail\n");
    printf("-----\t----\t\t-----\n");
    /* Print each customer */
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\n", i, list[i].name, list[i].email);
    }
}

int main() {
    struct customer list[10]; /* Initialize list of maximum 10 customers */
    int count = 0; /* Initialize count of customers to 0 */
    int choice; /* Initialize user menu choice */

    /* Display menu until user exits */
    do {
        printf("\n------ MENU ------\n");
        printf("1. Add customer\n");
        printf("2. Remove customer\n");
        printf("3. Display all customers\n");
        printf("4. Exit\n");
        printf("------------------\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); /* remove newline character from input buffer */
        /* Perform corresponding action based on user choice */
        switch (choice) {
            case 1:
                addCustomer(list, &count);
                break;
            case 2:
                removeCustomer(list, &count);
                break;
            case 3:
                displayCustomers(list, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("ERROR: Invalid choice! Please choose again.\n");
        }
    } while (choice != 4); /* Exit loop when user chooses to exit */

    return 0;
}